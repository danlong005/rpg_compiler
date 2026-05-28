#pragma once
//
// rpg_dspf_runtime.h — OpenDSPF display file runtime (ncurses)
//
// Renders RPG display file record formats in the terminal using ncurses.
// Works over SSH and locally; each process owns its own terminal session.
// No daemon, no network, no browser required.
//
// Link with -lncurses (Linux/macOS) or -lpdcurses (Windows/PDCurses).
//
// API (generated code requires no changes):
//   dspf_init(path)           load descriptor, initialise ncurses
//   dspf_set_indicators(p,n)  pass current indicator array before each I/O op
//   dspf_exfmt(rec, buf)      render screen, collect input, return indicator
//   dspf_write(rec, buf)      write record (SFL: append row; SFLCTL: clear SFL; else render)
//   dspf_read (rec, buf)      same as exfmt
//   dspf_close()              restore terminal
//

#ifdef _WIN32
#  include <curses.h>   // PDCurses drop-in
#else
#  include <ncurses.h>
#endif

#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <string>
#include <vector>

// =============================================================================
// Minimal JSON parser (reads the .dspfd descriptor)
// =============================================================================

struct DspfJVal {
    enum Kind { Null, Bool, Int, Str, Arr, Obj } kind = Null;
    bool b = false; int i = 0;
    std::string s;
    std::vector<DspfJVal> arr;
    std::map<std::string, DspfJVal> obj;

    const DspfJVal& operator[](const std::string& k) const {
        static DspfJVal nul;
        auto it = obj.find(k); return it == obj.end() ? nul : it->second;
    }
    const DspfJVal& operator[](size_t idx) const {
        static DspfJVal nul; return idx < arr.size() ? arr[idx] : nul;
    }
    bool        has(const std::string& k) const { return obj.count(k) > 0; }
    std::string str()  const { return s; }
    int         num()  const { return i; }
    size_t      size() const { return arr.size(); }
};

static void dspf__skipWS(const char*& p) {
    while (*p && isspace((unsigned char)*p)) p++;
}

static std::string dspf__parseStr(const char*& p) {
    assert(*p == '"'); p++;
    std::string r;
    while (*p && *p != '"') {
        if (*p == '\\') { p++;
            switch (*p) {
                case '"':  r += '"';  break; case '\\': r += '\\'; break;
                case 'n':  r += '\n'; break; case 'r':  r += '\r'; break;
                case 't':  r += '\t'; break; default:   r += *p;   break;
            }
        } else { r += *p; }
        p++;
    }
    if (*p == '"') p++;
    return r;
}

static DspfJVal dspf__parseVal(const char*& p);

static DspfJVal dspf__parseObj(const char*& p) {
    assert(*p == '{'); p++;
    DspfJVal v; v.kind = DspfJVal::Obj;
    dspf__skipWS(p);
    while (*p && *p != '}') {
        dspf__skipWS(p);
        if (*p != '"') { p++; continue; }
        std::string key = dspf__parseStr(p);
        dspf__skipWS(p); if (*p == ':') p++;
        dspf__skipWS(p);
        v.obj[key] = dspf__parseVal(p);
        dspf__skipWS(p); if (*p == ',') p++;
        dspf__skipWS(p);
    }
    if (*p == '}') p++;
    return v;
}

static DspfJVal dspf__parseArr(const char*& p) {
    assert(*p == '['); p++;
    DspfJVal v; v.kind = DspfJVal::Arr;
    dspf__skipWS(p);
    while (*p && *p != ']') {
        v.arr.push_back(dspf__parseVal(p));
        dspf__skipWS(p); if (*p == ',') p++;
        dspf__skipWS(p);
    }
    if (*p == ']') p++;
    return v;
}

static DspfJVal dspf__parseVal(const char*& p) {
    dspf__skipWS(p);
    if (*p == '{') return dspf__parseObj(p);
    if (*p == '[') return dspf__parseArr(p);
    if (*p == '"') { DspfJVal v; v.kind=DspfJVal::Str; v.s=dspf__parseStr(p); return v; }
    if (strncmp(p,"true", 4)==0){p+=4;DspfJVal v;v.kind=DspfJVal::Bool;v.b=true; return v;}
    if (strncmp(p,"false",5)==0){p+=5;DspfJVal v;v.kind=DspfJVal::Bool;v.b=false;return v;}
    if (strncmp(p,"null", 4)==0){p+=4;return DspfJVal{};}
    DspfJVal v; v.kind=DspfJVal::Int;
    bool neg=(*p=='-'); if(neg) p++;
    while (*p&&isdigit((unsigned char)*p)){v.i=v.i*10+(*p-'0');p++;}
    if(neg) v.i=-v.i;
    return v;
}

static DspfJVal dspf__parseJSON(const std::string& src) {
    const char* p = src.c_str(); return dspf__parseVal(p);
}

// =============================================================================
// Buffer helpers — walk buffer using descriptor to extract / apply field values
// =============================================================================

static std::map<std::string,std::string>
dspf__extractFields(const DspfJVal& rec, const void* buf) {
    std::map<std::string,std::string> m;
    std::map<std::string,bool> seen; // tracks fields already mapped to a buffer slot
    const char* p = (const char*)buf;
    const DspfJVal& fields = rec["fields"];
    for (size_t i = 0; i < fields.size(); i++) {
        std::string name = fields[i]["name"].str();
        std::string type = fields[i]["type"].str();
        int len  = fields[i]["len"].num();
        int dec  = fields[i]["dec"].num();
        std::string io = fields[i]["io"].str();
        if (io == "H") { // advance pointer but skip value
            if (type == "A") p += (len + 1);
            else if (type == "B") p += sizeof(long);
            else p += sizeof(double);
            continue;
        }
        // Duplicate display entries (same field, different conditioning/attributes)
        // share one buffer slot — only the first occurrence advances the pointer.
        if (seen.count(name)) continue;
        seen[name] = true;
        if (type == "A") {
            std::string val(p, strnlen(p, (size_t)len));
            while (!val.empty() && val.back() == ' ') val.pop_back();
            m[name] = val;
            p += (len + 1);
        } else if (type == "B") {
            m[name] = std::to_string(*(const long*)p);
            p += sizeof(long);
        } else {
            char tmp[64];
            snprintf(tmp, sizeof(tmp), "%.*f", dec, *(const double*)p);
            m[name] = tmp;
            p += sizeof(double);
        }
    }
    return m;
}

static void dspf__applyFields(const DspfJVal& rec,
                               const std::map<std::string,std::string>& vals,
                               void* buf) {
    char* p = (char*)buf;
    std::map<std::string,bool> seen;
    const DspfJVal& fields = rec["fields"];
    for (size_t i = 0; i < fields.size(); i++) {
        std::string name = fields[i]["name"].str();
        std::string type = fields[i]["type"].str();
        int len = fields[i]["len"].num();
        std::string io = fields[i]["io"].str();
        if (io == "H") {
            if (type == "A") p += (len + 1);
            else if (type == "B") p += sizeof(long);
            else p += sizeof(double);
            continue;
        }
        if (seen.count(name)) continue; // duplicate display entry — shares first slot
        seen[name] = true;
        if (type == "A") {
            auto it = vals.find(name);
            if (it != vals.end()) {
                size_t clen = std::min((int)it->second.size(), len);
                memcpy(p, it->second.c_str(), clen);
                memset(p + clen, ' ', len - clen);
                p[len] = '\0';
            }
            p += (len + 1);
        } else if (type == "B") {
            auto it = vals.find(name);
            if (it != vals.end()) try { *(long*)p = std::stol(it->second); } catch (...) {}
            p += sizeof(long);
        } else {
            auto it = vals.find(name);
            if (it != vals.end()) try { *(double*)p = std::stod(it->second); } catch (...) {}
            p += sizeof(double);
        }
    }
}

// =============================================================================
// Indicator state — set by caller before each I/O operation
// =============================================================================

static bool g_dspf_indicators[100] = {};

inline void dspf_set_indicators(const bool* inds, int count) {
    int n = (count < 100) ? count : 100;
    for (int i = 0; i < n; i++) g_dspf_indicators[i] = inds[i];
}

// Returns true if the item's COND keywords are satisfied (or absent).
static bool dspf__condPass(const DspfJVal& item) {
    const DspfJVal& kw = item["keywords"];
    for (size_t i = 0; i < kw.size(); i++) {
        const std::string& k = kw[i].str();
        if (k.rfind("COND(", 0) != 0) continue;
        std::string inner = k.substr(5, k.size() > 6 ? k.size() - 6 : 0);
        bool neg = (!inner.empty() && (inner[0]=='N' || inner[0]=='n'));
        if (neg) inner = inner.substr(1);
        int ind = 0;
        if (inner.rfind("*IN", 0) == 0) {
            try { ind = std::stoi(inner.substr(3)); } catch (...) {}
        } else {
            try { ind = std::stoi(inner); } catch (...) {}
        }
        if (ind >= 0 && ind < 100) {
            bool on = g_dspf_indicators[ind];
            if (neg ? on : !on) return false;
        }
    }
    return true;
}

// Check if a record has any keyword whose text starts with `prefix`.
static bool dspf__hasRecKw(const DspfJVal& rec, const std::string& prefix) {
    const DspfJVal& kw = rec["keywords"];
    for (size_t i = 0; i < kw.size(); i++) {
        if (kw[i].str().rfind(prefix, 0) == 0) return true;
    }
    return false;
}

// Returns true when PROTECT is present and its indicator condition (if any) is met.
static bool dspf__isProtected(const DspfJVal& rec) {
    const DspfJVal& kw = rec["keywords"];
    for (size_t i = 0; i < kw.size(); i++) {
        const std::string& k = kw[i].str();
        if (k == "PROTECT") return true;
        if (k.rfind("PROTECT(", 0) == 0) {
            std::string inner = k.substr(8, k.size() > 9 ? k.size() - 9 : 0);
            bool neg = (!inner.empty() && (inner[0]=='N' || inner[0]=='n'));
            if (neg) inner = inner.substr(1);
            int ind = 0;
            if (inner.rfind("*IN", 0) == 0) {
                try { ind = std::stoi(inner.substr(3)); } catch (...) {}
            } else {
                try { ind = std::stoi(inner); } catch (...) {}
            }
            if (ind >= 0 && ind < 100) {
                bool on = g_dspf_indicators[ind];
                return neg ? !on : on;
            }
            return true;
        }
    }
    return false;
}

// =============================================================================
// Edit code / edit word formatting
// =============================================================================

static std::string dspf__applyEditCode(double val, int /*len*/, int dec, char code) {
    char u = (char)toupper((unsigned char)code);
    bool negative = (val < 0.0);
    double absval = std::fabs(val);

    // Raw formatted number
    char buf[64];
    snprintf(buf, sizeof(buf), "%.*f", dec, absval);
    std::string raw(buf);

    // Split integer / decimal
    std::string intPart, decPart;
    auto dot = raw.find('.');
    if (dot == std::string::npos) { intPart = raw; }
    else { intPart = raw.substr(0, dot); decPart = raw.substr(dot + 1); }

    // Code Z: strip all formatting, remove leading zeros
    if (u == 'Z') {
        std::string z;
        bool lead = true;
        for (char c : intPart) {
            if (c == '0' && lead) continue;
            lead = false; z += c;
        }
        if (!decPart.empty()) { z += '.'; z += decPart; }
        return z.empty() ? "0" : z;
    }

    // Code Y: date edit — nnnnnnn → nn/nn/nn (strips leading zero from first pair)
    if (u == 'Y') {
        std::string digits;
        for (char c : intPart) if (isdigit((unsigned char)c)) digits += c;
        while (digits.size() < 6) digits = "0" + digits;
        // mm/dd/yy from rightmost 6 digits
        std::string d = digits.size() >= 6 ? digits.substr(digits.size() - 6) : digits;
        std::string mm = d.substr(0, 2); if (mm[0]=='0') mm = mm.substr(1);
        return mm + "/" + d.substr(2, 2) + "/" + d.substr(4, 2);
    }

    // Zero-suppress: replace leading zeros with spaces
    {
        bool leading = true;
        for (char& c : intPart) {
            if (leading && c == '0') c = ' ';
            else leading = false;
        }
    }

    // Asterisk fill (codes A-D): replace leading spaces with '*'
    bool asterisk = (u=='A'||u=='B'||u=='C'||u=='D');
    if (asterisk) {
        for (char& c : intPart) if (c == ' ') c = '*';
    }

    // Comma separator (codes 1,2,A,B,J,K,N,O)
    bool useComma = (u=='1'||u=='2'||u=='A'||u=='B'||u=='J'||u=='K'||u=='N'||u=='O');
    if (useComma) {
        std::string result;
        int digitCount = 0;
        for (int i = (int)intPart.size() - 1; i >= 0; i--) {
            char c = intPart[i];
            if (c != ' ' && c != '*') {
                if (digitCount > 0 && digitCount % 3 == 0) result = "," + result;
                digitCount++;
            }
            result = c + result;
        }
        intPart = result;
    }

    std::string out = intPart;
    if (!decPart.empty()) out += "." + decPart;

    // Sign handling
    bool useCR    = (u=='2'||u=='4'||u=='B'||u=='D'||u=='K'||u=='M'||u=='O'||u=='Q');
    bool useMinus = (u=='J'||u=='L'||u=='N'||u=='P'||u=='3'||u=='4'||u=='C'||u=='D');
    if (negative) {
        if (useCR)    out += "CR";
        else if (useMinus) out = "-" + out;
    }

    return out;
}

static std::string dspf__applyEditWord(double val, int /*len*/, int dec,
                                        const std::string& mask) {
    bool negative = (val < 0.0);
    double absval = std::fabs(val);

    // Separate body from status (after single quote in mask)
    std::string body = mask;
    std::string status;
    auto sq = mask.find('\'');
    if (sq != std::string::npos) {
        body   = mask.substr(0, sq);
        status = mask.substr(sq + 1);
    }

    // Count digit slots (spaces) in body
    int slots = 0;
    for (char c : body) if (c == ' ') slots++;

    // Build digit string with appropriate decimal places
    char buf[64];
    snprintf(buf, sizeof(buf), "%0*.*f", slots, dec, absval);
    std::string digits;
    for (char c : std::string(buf)) if (isdigit((unsigned char)c)) digits += c;
    while ((int)digits.size() < slots) digits = "0" + digits;
    if ((int)digits.size() > slots) digits = digits.substr(digits.size() - slots);

    // Fill body slots with digits left-to-right
    std::string result = body;
    int di = 0;
    for (char& c : result) if (c == ' ' && di < (int)digits.size()) c = digits[di++];

    // Zero-suppress: blank leading zeros and adjacent literal chars
    bool suppress = true;
    for (size_t i = 0; i < result.size(); i++) {
        char c = result[i];
        if (suppress) {
            if (c == '0') { result[i] = ' '; }
            else if (!isdigit((unsigned char)c)) { result[i] = ' '; } // leading literal
            else { suppress = false; }
        }
    }

    // Append status section if negative
    if (negative && !status.empty()) result += status;

    return result;
}

// =============================================================================
// ncurses colour / attribute helpers
// =============================================================================

enum {
    DSPF_PAIR_NORMAL  = 1,
    DSPF_PAIR_RED     = 2,
    DSPF_PAIR_BLUE    = 3,
    DSPF_PAIR_GREEN   = 4,
    DSPF_PAIR_YELLOW  = 5,
    DSPF_PAIR_MAGENTA = 6,
    DSPF_PAIR_CYAN    = 7,
};

static int dspf__colorPair(const DspfJVal& field) {
    const DspfJVal& kw = field["keywords"];
    for (size_t i = 0; i < kw.size(); i++) {
        const std::string& k = kw[i].str();
        if (k == "COLOR(RED)")    return DSPF_PAIR_RED;
        if (k == "COLOR(BLUE)")   return DSPF_PAIR_BLUE;
        if (k == "COLOR(GREEN)")  return DSPF_PAIR_GREEN;
        if (k == "COLOR(YELLOW)") return DSPF_PAIR_YELLOW;
        if (k == "COLOR(PINK)")   return DSPF_PAIR_MAGENTA;
        if (k == "COLOR(TURQ)")   return DSPF_PAIR_CYAN;
    }
    return DSPF_PAIR_NORMAL;
}

static attr_t dspf__fieldAttrs(const DspfJVal& field) {
    attr_t a = A_NORMAL;
    const DspfJVal& kw = field["keywords"];
    for (size_t i = 0; i < kw.size(); i++) {
        const std::string& k = kw[i].str();
        if (k == "DSPATR(HI)") a |= A_BOLD;
        if (k == "DSPATR(BL)") a |= A_BLINK;
        if (k == "DSPATR(RI)") a |= A_REVERSE;
        if (k == "DSPATR(UL)") a |= A_UNDERLINE;
    }
    return a;
}

// Apply EDTCDE/EDTWRD formatting to a numeric field value string.
static std::string dspf__formatField(const DspfJVal& field, const std::string& raw) {
    std::string type = field["type"].str();
    if (type == "A") return raw; // not numeric
    int len = field["len"].num();
    int dec = field["dec"].num();
    double numVal = 0.0;
    try { numVal = std::stod(raw); } catch (...) {}
    const DspfJVal& kw = field["keywords"];
    for (size_t i = 0; i < kw.size(); i++) {
        const std::string& k = kw[i].str();
        if (k.rfind("EDTCDE(", 0) == 0 && k.size() > 8) {
            return dspf__applyEditCode(numVal, len, dec, k[7]);
        }
        if (k.rfind("EDTWRD(", 0) == 0 && k.size() > 8) {
            std::string mask = k.substr(7, k.size() - 8);
            if (mask.size() >= 2 && mask.front() == '\'') mask = mask.substr(1);
            if (!mask.empty() && mask.back() == '\'') mask.pop_back();
            return dspf__applyEditWord(numVal, len, dec, mask);
        }
    }
    // No edit code: format with zero-fill, decimal point at correct position.
    // A ZONED/PACKED len=9 dec=2 field occupies 10 display chars (9 digits + '.').
    char buf[64];
    if (dec > 0) {
        snprintf(buf, sizeof(buf), "%0*.*f", len + 1, dec, numVal);
    } else {
        snprintf(buf, sizeof(buf), "%0*.*f", len, 0, numVal);
    }
    return std::string(buf);
}

// =============================================================================
// Screen rendering
// =============================================================================

static void dspf__renderScreen(const DspfJVal& rec,
                                const std::map<std::string,std::string>& vals) {
    if (!dspf__hasRecKw(rec, "OVERLAY") && !dspf__hasRecKw(rec, "NOCLEAR")) clear();

    // Literals
    const DspfJVal& lits = rec["literals"];
    for (size_t i = 0; i < lits.size(); i++) {
        if (!dspf__condPass(lits[i])) continue;
        int row = lits[i]["row"].num() - 1;
        int col = lits[i]["col"].num() - 1;
        mvprintw(row, col, "%s", lits[i]["text"].str().c_str());
    }

    // Fields
    const DspfJVal& fields = rec["fields"];
    for (size_t i = 0; i < fields.size(); i++) {
        std::string io = fields[i]["io"].str();
        if (io == "H") continue;
        if (!dspf__condPass(fields[i])) continue;

        int row = fields[i]["row"].num() - 1;
        int col = fields[i]["col"].num() - 1;
        int len = fields[i]["len"].num(); if (len == 0) len = 1;

        std::string name = fields[i]["name"].str();
        std::string val;
        auto it = vals.find(name);
        if (it != vals.end()) val = it->second;
        val = dspf__formatField(fields[i], val);
        if ((int)val.size() > len) val.resize(len);

        int pair   = dspf__colorPair(fields[i]);
        attr_t ext = dspf__fieldAttrs(fields[i]);

        if (io == "O") {
            std::string ftype = fields[i]["type"].str();
            attron(COLOR_PAIR(pair) | ext);
            if (ftype != "A") {
                mvprintw(row, col, "%*s", len, val.c_str());   // right-align numeric
            } else {
                mvprintw(row, col, "%-*s", len, val.c_str());  // left-align char
            }
            attroff(COLOR_PAIR(pair) | ext);
        } else {
            attron(COLOR_PAIR(pair) | ext | A_REVERSE);
            mvprintw(row, col, "%-*s", len, val.c_str());
            attroff(COLOR_PAIR(pair) | ext | A_REVERSE);
        }
    }

    // F-key legend on line 25 (0-indexed 24) when terminal is tall enough
    if (LINES > 24) {
        const DspfJVal& keys = rec["keys"];
        std::string legend = " Enter=Submit";
        for (size_t i = 0; i < keys.size(); i++) {
            const std::string& k = keys[i]["key"].str();
            legend += "  " + k;
            static const std::map<std::string,std::string> desc = {
                {"F3","=Exit"},{"F4","=Prompt"},{"F5","=Refresh"},{"F6","=Add"},
                {"F7","=Prev"},{"F8","=Next"},{"F12","=Cancel"},
            };
            auto it = desc.find(k);
            if (it != desc.end()) legend += it->second;
        }
        attron(A_REVERSE);
        mvprintw(24, 0, "%-*s", COLS, legend.c_str());
        attroff(A_REVERSE);
    }

    refresh();
}

// =============================================================================
// Input loop — tab between fields, F-keys and Enter exit
// =============================================================================

struct DspfEditField {
    int  recIdx;
    int  row, col, len;
    std::string name;
    std::string val;
};

static int dspf__inputLoop(const DspfJVal& rec,
                            std::map<std::string,std::string>& vals) {
    // NOINPUT: screen is display-only; no field editing allowed.
    // PROTECT: same effect — all I/B fields become read-only.
    bool noinput = dspf__hasRecKw(rec, "NOINPUT") || dspf__isProtected(rec);

    std::vector<DspfEditField> ef;
    if (!noinput) {
        std::map<std::string,bool> efSeen;
        const DspfJVal& fields = rec["fields"];
        for (size_t i = 0; i < fields.size(); i++) {
            std::string io = fields[i]["io"].str();
            if (io != "I" && io != "B") continue;
            if (!dspf__condPass(fields[i])) continue;
            std::string fname = fields[i]["name"].str();
            if (efSeen.count(fname)) continue; // first condPass-visible entry wins
            efSeen[fname] = true;
            DspfEditField f;
            f.recIdx = (int)i;
            f.row    = fields[i]["row"].num() - 1;
            f.col    = fields[i]["col"].num() - 1;
            f.len    = fields[i]["len"].num(); if (f.len == 0) f.len = 1;
            f.name   = fname;
            auto it  = vals.find(f.name);
            f.val    = (it != vals.end()) ? it->second : "";
            if ((int)f.val.size() > f.len) f.val.resize(f.len);
            ef.push_back(f);
        }
    }

    const DspfJVal& fields = rec["fields"];
    int cur = 0;

    while (true) {
        if (!ef.empty()) {
            int cx = ef[cur].col + (int)ef[cur].val.size();
            if (cx >= ef[cur].col + ef[cur].len) cx = ef[cur].col + ef[cur].len - 1;
            move(ef[cur].row, cx);
            refresh();
        }

        int ch = getch();

        if (ch >= KEY_F(1) && ch <= KEY_F(24)) {
            int fnum = ch - KEY_F(0);
            std::string key = "F" + std::to_string(fnum);
            for (auto& f : ef) vals[f.name] = f.val;
            const DspfJVal& keys = rec["keys"];
            for (size_t i = 0; i < keys.size(); i++) {
                if (keys[i]["key"].str() == key)
                    return keys[i]["indicator"].num();
            }
            return fnum;
        }

        if (ch == '\n' || ch == '\r' || ch == KEY_ENTER) {
            for (auto& f : ef) vals[f.name] = f.val;
            return 0;
        }

        if (ef.empty()) continue;

        DspfEditField& f = ef[cur];

        if (ch == '\t' || ch == KEY_DOWN) {
            cur = (cur + 1) % (int)ef.size(); continue;
        }
        if (ch == KEY_BTAB || ch == KEY_UP) {
            cur = (cur - 1 + (int)ef.size()) % (int)ef.size(); continue;
        }
        if (ch == KEY_HOME) { cur = 0; continue; }
        if (ch == KEY_END)  { cur = (int)ef.size() - 1; continue; }

        if (ch == KEY_BACKSPACE || ch == 127 || ch == 8) {
            if (!f.val.empty()) {
                f.val.pop_back();
                int pair = dspf__colorPair(fields[f.recIdx]);
                attr_t ext = dspf__fieldAttrs(fields[f.recIdx]);
                attron(COLOR_PAIR(pair) | ext | A_REVERSE);
                mvprintw(f.row, f.col, "%-*s", f.len, f.val.c_str());
                attroff(COLOR_PAIR(pair) | ext | A_REVERSE);
            }
            continue;
        }

        if (isprint(ch) && (int)f.val.size() < f.len) {
            f.val += (char)ch;
            int pair = dspf__colorPair(fields[f.recIdx]);
            attr_t ext = dspf__fieldAttrs(fields[f.recIdx]);
            attron(COLOR_PAIR(pair) | ext | A_REVERSE);
            mvprintw(f.row, f.col, "%-*s", f.len, f.val.c_str());
            attroff(COLOR_PAIR(pair) | ext | A_REVERSE);
            // Auto-advance: when field fills, move focus to next field
            if ((int)f.val.size() >= f.len) {
                cur = (cur + 1) % (int)ef.size();
                refresh();
            }
        }
    }
}

// =============================================================================
// Global descriptor (forward-declared here; defined in Public API section)
// =============================================================================

static DspfJVal g_dspfDescriptor;
static bool     g_dspfActive = false;

// =============================================================================
// Subfile store
// =============================================================================

struct DspfSflRow { std::map<std::string,std::string> fields; };
static std::map<std::string, std::vector<DspfSflRow>> g_dspf_subfiles;
static std::map<std::string, int> g_dspf_sfl_cursor; // sflctl name → 1-based RRN
static std::map<std::string, int> g_dspf_sfl_page;   // sflctl name → 0-based page offset

// =============================================================================
// Subfile EXFMT — render scrollable table and handle navigation
// =============================================================================

static int dspf__sflExfmt(const char* ctlName, const DspfJVal& ctl, void* ctlBuf) {
    std::string sflName = ctl["sfl"].str();
    int sflpag = ctl["sflpag"].num(); if (sflpag <= 0) sflpag = 10;

    // Locate the SFL record definition in the global descriptor
    const DspfJVal* sflRec = nullptr;
    {
        const DspfJVal& allRecs = g_dspfDescriptor["records"];
        for (size_t i = 0; i < allRecs.size(); i++) {
#ifdef _WIN32
            if (_stricmp(allRecs[i]["name"].str().c_str(), sflName.c_str()) == 0) {
#else
            if (strcasecmp(allRecs[i]["name"].str().c_str(), sflName.c_str()) == 0) {
#endif
                sflRec = &allRecs[i]; break;
            }
        }
    }

    auto& rows    = g_dspf_subfiles[sflName];
    int   numRows = (int)rows.size();

    std::string ctlKey(ctlName);
    int& pageOff = g_dspf_sfl_page[ctlKey];
    int& cursor  = g_dspf_sfl_cursor[ctlKey];
    if (cursor < 1) cursor = 1;
    if (numRows > 0 && cursor > numRows) cursor = numRows;

    // Keep cursor on screen
    if (cursor - 1 < pageOff)            pageOff = cursor - 1;
    if (cursor - 1 >= pageOff + sflpag)  pageOff = cursor - sflpag;
    if (pageOff < 0) pageOff = 0;

    // Find base row of SFL fields (0-indexed screen row for first data row)
    int sflBaseRow = 5;
    if (sflRec) {
        const DspfJVal& sf = (*sflRec)["fields"];
        int minR = INT_MAX;
        for (size_t i = 0; i < sf.size(); i++) {
            int r = sf[i]["row"].num();
            if (r > 0 && r < minR) minR = r;
        }
        if (minR < INT_MAX) sflBaseRow = minR - 1;
    }

    auto ctlVals = dspf__extractFields(ctl, ctlBuf);

    // Render everything (control record + subfile rows)
    auto render = [&]() {
        dspf__renderScreen(ctl, ctlVals);

        if (!sflRec) { refresh(); return; }
        const DspfJVal& sf = (*sflRec)["fields"];
        int endPage = std::min(numRows, pageOff + sflpag);

        for (int i = pageOff; i < endPage; i++) {
            int screenRow = sflBaseRow + (i - pageOff);
            bool isCursor = (i == cursor - 1);

            for (size_t fi = 0; fi < sf.size(); fi++) {
                if (sf[fi]["io"].str() == "H") continue;
                int col = sf[fi]["col"].num() - 1;
                int len = sf[fi]["len"].num(); if (len == 0) len = 1;
                std::string fname = sf[fi]["name"].str();

                std::string val;
                auto it = rows[i].fields.find(fname);
                if (it != rows[i].fields.end()) val = it->second;
                val = dspf__formatField(sf[fi], val);
                if ((int)val.size() > len) val.resize(len);

                int pair   = dspf__colorPair(sf[fi]);
                attr_t ext = dspf__fieldAttrs(sf[fi]);

                if (isCursor) {
                    attron(COLOR_PAIR(pair) | ext | A_REVERSE);
                    mvprintw(screenRow, col, "%-*s", len, val.c_str());
                    attroff(COLOR_PAIR(pair) | ext | A_REVERSE);
                } else {
                    attron(COLOR_PAIR(pair) | ext);
                    mvprintw(screenRow, col, "%-*s", len, val.c_str());
                    attroff(COLOR_PAIR(pair) | ext);
                }
            }
        }
        refresh();
    };

    render();

    while (true) {
        // Position cursor at start of current row
        if (numRows > 0 && sflRec) {
            const DspfJVal& sf = (*sflRec)["fields"];
            if (sf.size() > 0) {
                int screenRow = sflBaseRow + (cursor - 1 - pageOff);
                move(screenRow, sf[0]["col"].num() - 1);
            }
        }
        refresh();

        int ch = getch();

        if (ch >= KEY_F(1) && ch <= KEY_F(24)) {
            int fnum = ch - KEY_F(0);
            std::string key = "F" + std::to_string(fnum);
            ctlVals["SFLRCDNBR"] = std::to_string(cursor);
            dspf__applyFields(ctl, ctlVals, ctlBuf);
            const DspfJVal& keys = ctl["keys"];
            for (size_t i = 0; i < keys.size(); i++) {
                if (keys[i]["key"].str() == key) return keys[i]["indicator"].num();
            }
            return fnum;
        }

        if (ch == '\n' || ch == '\r' || ch == KEY_ENTER) {
            ctlVals["SFLRCDNBR"] = std::to_string(cursor);
            dspf__applyFields(ctl, ctlVals, ctlBuf);
            return 0;
        }

        if (numRows == 0) continue;

        if (ch == KEY_UP) {
            if (cursor > 1) {
                cursor--;
                if (cursor - 1 < pageOff) pageOff = std::max(0, pageOff - 1);
                render();
            }
        } else if (ch == KEY_DOWN) {
            if (cursor < numRows) {
                cursor++;
                if (cursor - 1 >= pageOff + sflpag) pageOff++;
                render();
            }
        } else if (ch == KEY_PPAGE) {
            pageOff = std::max(0, pageOff - sflpag);
            cursor  = pageOff + 1;
            render();
        } else if (ch == KEY_NPAGE) {
            if (pageOff + sflpag < numRows) {
                pageOff += sflpag;
                cursor   = pageOff + 1;
                render();
            }
        }
    }
}

// =============================================================================
// Record lookup
// =============================================================================

static const DspfJVal* dspf__findRec(const char* recname) {
    const DspfJVal& recs = g_dspfDescriptor["records"];
    for (size_t i = 0; i < recs.size(); i++) {
        std::string n = recs[i]["name"].str();
#ifdef _WIN32
        if (_stricmp(n.c_str(), recname) == 0) return &recs[i];
#else
        if (strcasecmp(n.c_str(), recname) == 0) return &recs[i];
#endif
    }
    return nullptr;
}

// =============================================================================
// Public API
// =============================================================================

inline void dspf_init(const char* descriptor_path) {
    FILE* f = fopen(descriptor_path, "rb");
    if (!f) {
        fprintf(stderr, "dspf_init: cannot open %s\n", descriptor_path);
        exit(1);
    }
    fseek(f, 0, SEEK_END); long sz = ftell(f); fseek(f, 0, SEEK_SET);
    std::string json(sz, '\0');
    fread(&json[0], 1, sz, f); fclose(f);
    g_dspfDescriptor = dspf__parseJSON(json);

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    if (has_colors()) {
        start_color();
        use_default_colors();
        init_pair(DSPF_PAIR_NORMAL,  COLOR_GREEN,   -1);
        init_pair(DSPF_PAIR_RED,     COLOR_RED,     -1);
        init_pair(DSPF_PAIR_BLUE,    COLOR_BLUE,    -1);
        init_pair(DSPF_PAIR_GREEN,   COLOR_GREEN,   -1);
        init_pair(DSPF_PAIR_YELLOW,  COLOR_YELLOW,  -1);
        init_pair(DSPF_PAIR_MAGENTA, COLOR_MAGENTA, -1);
        init_pair(DSPF_PAIR_CYAN,    COLOR_CYAN,    -1);
    }
    g_dspfActive = true;
}

inline int dspf_exfmt(const char* recname, void* recbuf) {
    const DspfJVal* rec = dspf__findRec(recname);
    if (!rec) return 0;
    if (dspf__hasRecKw(*rec, "ALARM")) beep();
    std::string recType = (*rec)["type"].str();
    if (recType == "sflctl") return dspf__sflExfmt(recname, *rec, recbuf);
    auto vals = dspf__extractFields(*rec, recbuf);
    dspf__renderScreen(*rec, vals);
    int indicator = dspf__inputLoop(*rec, vals);
    dspf__applyFields(*rec, vals, recbuf);
    return indicator;
}

inline void dspf_write(const char* recname, const void* recbuf) {
    const DspfJVal* rec = dspf__findRec(recname);
    if (!rec) return;
    std::string recType = (*rec)["type"].str();

    if (recType == "sfl") {
        // Append a row to the subfile store
        auto vals = dspf__extractFields(*rec, recbuf);
        g_dspf_subfiles[recname].push_back({vals});
        return;
    }

    if (recType == "sflctl") {
        // Writing to the control record clears the associated subfile
        std::string sflName = (*rec)["sfl"].str();
        g_dspf_subfiles[sflName].clear();
        std::string ctlKey(recname);
        g_dspf_sfl_cursor[ctlKey] = 1;
        g_dspf_sfl_page[ctlKey]   = 0;
        return;
    }

    // Normal record: render immediately (no input wait)
    auto vals = dspf__extractFields(*rec, recbuf);
    dspf__renderScreen(*rec, vals);
}

inline int dspf_read(const char* recname, void* recbuf) {
    return dspf_exfmt(recname, recbuf);
}

inline void dspf_close() {
    if (g_dspfActive) {
        endwin();
        g_dspfActive = false;
    }
}
