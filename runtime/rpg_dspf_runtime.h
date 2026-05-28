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
//   dspf_init(path)        load descriptor, initialise ncurses
//   dspf_exfmt(rec, buf)   render screen, collect input, return indicator
//   dspf_write(rec, buf)   render screen without waiting for input
//   dspf_read (rec, buf)   same as exfmt
//   dspf_close()           restore terminal
//

#ifdef _WIN32
#  include <curses.h>   // PDCurses drop-in
#else
#  include <ncurses.h>
#endif

#include <algorithm>
#include <cassert>
#include <cctype>
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
    const char* p = (const char*)buf;
    const DspfJVal& fields = rec["fields"];
    for (size_t i = 0; i < fields.size(); i++) {
        std::string name = fields[i]["name"].str();
        std::string type = fields[i]["type"].str();
        int len  = fields[i]["len"].num();
        int dec  = fields[i]["dec"].num();
        std::string io = fields[i]["io"].str();
        if (io == "H") continue;
        if (type == "A") {
            std::string val(p, strnlen(p, (size_t)len));
            while (!val.empty() && val.back() == ' ') val.pop_back();
            m[name] = val;
            p += (len + 1);
        } else if (type == "B") {
            m[name] = std::to_string(*(long*)p);
            p += sizeof(long);
        } else {
            char tmp[64];
            snprintf(tmp, sizeof(tmp), "%.*f", dec, *(double*)p);
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
    const DspfJVal& fields = rec["fields"];
    for (size_t i = 0; i < fields.size(); i++) {
        std::string name = fields[i]["name"].str();
        std::string type = fields[i]["type"].str();
        int len = fields[i]["len"].num();
        std::string io = fields[i]["io"].str();
        if (io == "H") continue;
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
// ncurses colour / attribute helpers
// =============================================================================

// Colour pair IDs — initialised once in dspf_init.
enum {
    DSPF_PAIR_NORMAL  = 1,
    DSPF_PAIR_RED     = 2,
    DSPF_PAIR_BLUE    = 3,
    DSPF_PAIR_GREEN   = 4,
    DSPF_PAIR_YELLOW  = 5,
    DSPF_PAIR_MAGENTA = 6,   // PINK
    DSPF_PAIR_CYAN    = 7,   // TURQ
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

// =============================================================================
// Screen rendering
// =============================================================================

static void dspf__renderScreen(const DspfJVal& rec,
                                const std::map<std::string,std::string>& vals) {
    clear();

    // Literals
    const DspfJVal& lits = rec["literals"];
    for (size_t i = 0; i < lits.size(); i++) {
        int row = lits[i]["row"].num() - 1;
        int col = lits[i]["col"].num() - 1;
        mvprintw(row, col, "%s", lits[i]["text"].str().c_str());
    }

    // Fields
    const DspfJVal& fields = rec["fields"];
    for (size_t i = 0; i < fields.size(); i++) {
        std::string io = fields[i]["io"].str();
        if (io == "H") continue;

        int row = fields[i]["row"].num() - 1;
        int col = fields[i]["col"].num() - 1;
        int len = fields[i]["len"].num(); if (len == 0) len = 1;

        std::string name = fields[i]["name"].str();
        std::string val;
        auto it = vals.find(name);
        if (it != vals.end()) val = it->second;
        // Truncate to field length.
        if ((int)val.size() > len) val.resize(len);

        int pair   = dspf__colorPair(fields[i]);
        attr_t ext = dspf__fieldAttrs(fields[i]);

        if (io == "O") {
            // Output-only: display value, no input highlight.
            attron(COLOR_PAIR(pair) | ext);
            mvprintw(row, col, "%-*s", len, val.c_str());
            attroff(COLOR_PAIR(pair) | ext);
        } else {
            // Input or both: reverse-video underscored field.
            attron(COLOR_PAIR(pair) | ext | A_REVERSE);
            mvprintw(row, col, "%-*s", len, val.c_str());
            attroff(COLOR_PAIR(pair) | ext | A_REVERSE);
        }
    }

    // F-key legend on the line below the 24-row screen (only if terminal is tall enough).
    if (LINES > 24) {
        const DspfJVal& keys = rec["keys"];
        std::string legend = " Enter=Submit";
        for (size_t i = 0; i < keys.size(); i++) {
            const std::string& k = keys[i]["key"].str();
            legend += "  " + k;
            // Append description if recognisable.
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
    int  recIdx;   // index in rec["fields"]
    int  row, col, len;
    std::string name;
    std::string val;
};

static int dspf__inputLoop(const DspfJVal& rec,
                            std::map<std::string,std::string>& vals) {
    // Collect editable fields in display order.
    std::vector<DspfEditField> ef;
    const DspfJVal& fields = rec["fields"];
    for (size_t i = 0; i < fields.size(); i++) {
        std::string io = fields[i]["io"].str();
        if (io != "I" && io != "B") continue;
        DspfEditField f;
        f.recIdx = (int)i;
        f.row    = fields[i]["row"].num() - 1;
        f.col    = fields[i]["col"].num() - 1;
        f.len    = fields[i]["len"].num(); if (f.len == 0) f.len = 1;
        f.name   = fields[i]["name"].str();
        auto it  = vals.find(f.name);
        f.val    = (it != vals.end()) ? it->second : "";
        if ((int)f.val.size() > f.len) f.val.resize(f.len);
        ef.push_back(f);
    }

    int cur = 0;

    while (true) {
        // Position cursor at end of current field's value.
        if (!ef.empty()) {
            int cx = ef[cur].col + (int)ef[cur].val.size();
            if (cx >= ef[cur].col + ef[cur].len) cx = ef[cur].col + ef[cur].len - 1;
            move(ef[cur].row, cx);
            refresh();
        }

        int ch = getch();

        // --- F-keys ---
        if (ch >= KEY_F(1) && ch <= KEY_F(24)) {
            int fnum = ch - KEY_F(0);
            std::string key = "F" + std::to_string(fnum);
            // Write edited values back before returning.
            for (auto& f : ef) vals[f.name] = f.val;
            // Find indicator from descriptor.
            const DspfJVal& keys = rec["keys"];
            for (size_t i = 0; i < keys.size(); i++) {
                if (keys[i]["key"].str() == key)
                    return keys[i]["indicator"].num();
            }
            return fnum; // unmapped key — use function number as indicator
        }

        // --- Enter ---
        if (ch == '\n' || ch == '\r' || ch == KEY_ENTER) {
            for (auto& f : ef) vals[f.name] = f.val;
            return 0;
        }

        if (ef.empty()) continue;

        DspfEditField& f = ef[cur];

        // --- Tab / Shift-Tab: move between fields ---
        if (ch == '\t') {
            cur = (cur + 1) % (int)ef.size();
            continue;
        }
        if (ch == KEY_BTAB) {
            cur = (cur - 1 + (int)ef.size()) % (int)ef.size();
            continue;
        }

        // --- Backspace ---
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

        // --- Printable character ---
        if (isprint(ch) && (int)f.val.size() < f.len) {
            f.val += (char)ch;
            int pair = dspf__colorPair(fields[f.recIdx]);
            attr_t ext = dspf__fieldAttrs(fields[f.recIdx]);
            attron(COLOR_PAIR(pair) | ext | A_REVERSE);
            mvprintw(f.row, f.col, "%-*s", f.len, f.val.c_str());
            attroff(COLOR_PAIR(pair) | ext | A_REVERSE);
            // Auto-advance when field is full.
            if ((int)f.val.size() >= f.len)
                cur = (cur + 1) % (int)ef.size();
        }
    }
}

// =============================================================================
// Record lookup
// =============================================================================

static DspfJVal  g_dspfDescriptor;
static bool      g_dspfActive = false;

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
        // Fail visibly before ncurses takes over the terminal.
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
    auto vals = dspf__extractFields(*rec, recbuf);
    dspf__renderScreen(*rec, vals);
    int indicator = dspf__inputLoop(*rec, vals);
    dspf__applyFields(*rec, vals, recbuf);
    return indicator;
}

inline void dspf_write(const char* recname, const void* recbuf) {
    const DspfJVal* rec = dspf__findRec(recname);
    if (!rec) return;
    auto vals = dspf__extractFields(*rec, recbuf);
    dspf__renderScreen(*rec, vals);
    // WRITE does not wait for input — the next opcode will handle the terminal.
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
