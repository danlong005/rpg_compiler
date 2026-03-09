#ifndef RPG_RUNTIME_H
#define RPG_RUNTIME_H

#include <string>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <sstream>
#include <iomanip>

// %TRIM - trim both sides
inline std::string rpg_trim(const std::string& s) {
    auto start = s.find_first_not_of(' ');
    if (start == std::string::npos) return "";
    auto end = s.find_last_not_of(' ');
    return s.substr(start, end - start + 1);
}

// %TRIML - trim left
inline std::string rpg_triml(const std::string& s) {
    auto start = s.find_first_not_of(' ');
    if (start == std::string::npos) return "";
    return s.substr(start);
}

// %TRIMR - trim right
inline std::string rpg_trimr(const std::string& s) {
    auto end = s.find_last_not_of(' ');
    if (end == std::string::npos) return "";
    return s.substr(0, end + 1);
}

// %SCAN - find needle in haystack, returns 1-based position (0 if not found)
inline int rpg_scan(const std::string& needle, const std::string& haystack, int start = 1) {
    auto pos = haystack.find(needle, start - 1);
    return (pos == std::string::npos) ? 0 : static_cast<int>(pos) + 1;
}

// %SCANRPL - scan and replace all occurrences
inline std::string rpg_scanrpl(const std::string& find, const std::string& replace,
                                const std::string& source) {
    std::string result = source;
    size_t pos = 0;
    while ((pos = result.find(find, pos)) != std::string::npos) {
        result.replace(pos, find.length(), replace);
        pos += replace.length();
    }
    return result;
}

// %XLATE - translate characters
inline std::string rpg_xlate(const std::string& from, const std::string& to,
                              const std::string& source) {
    std::string result = source;
    for (auto& ch : result) {
        auto pos = from.find(ch);
        if (pos != std::string::npos && pos < to.size()) {
            ch = to[pos];
        }
    }
    return result;
}

// %FOUND / %EOF stubs - will be connected to file I/O later
inline bool rpg_found() { return false; }
inline bool rpg_eof() { return false; }

// %LOOKUP - find element in array, returns 1-based index (0 if not found)
template<typename T, std::size_t N>
inline int rpg_lookup(const T& val, const std::array<T, N>& arr) {
    for (std::size_t i = 0; i < N; i++) {
        if (arr[i] == val) return static_cast<int>(i + 1);
    }
    return 0;
}

// %CHECK - find first char in base NOT in comparator (1-based, 0 if all found)
inline int rpg_check(const std::string& comp, const std::string& base, int start = 1) {
    for (int i = start - 1; i < static_cast<int>(base.size()); i++) {
        if (comp.find(base[i]) == std::string::npos) return i + 1;
    }
    return 0;
}

// %CHECKR - same as %CHECK but from right
inline int rpg_checkr(const std::string& comp, const std::string& base, int start = 0) {
    int end = (start > 0) ? start - 1 : static_cast<int>(base.size()) - 1;
    for (int i = end; i >= 0; i--) {
        if (comp.find(base[i]) == std::string::npos) return i + 1;
    }
    return 0;
}

// %REPLACE(new : source : start {: length})
inline std::string rpg_replace(const std::string& newstr, const std::string& source, int start, int length = -1) {
    std::string result = source;
    int pos = start - 1; // 1-based to 0-based
    if (length < 0) {
        // Insert mode: insert at position without removing
        result.insert(pos, newstr);
    } else {
        result.replace(pos, length, newstr);
    }
    return result;
}

// %EDITC - format number with edit code
inline std::string rpg_editc(double val, const std::string& code) {
    bool negative = val < 0;
    double absval = negative ? -val : val;

    // Split into integer and decimal parts
    long long intpart = static_cast<long long>(absval * 100 + 0.5);
    long long cents = intpart % 100;
    long long dollars = intpart / 100;

    std::string digits = std::to_string(dollars);
    char editcode = code.empty() ? '1' : code[0];

    bool use_commas = (editcode == '1' || editcode == '3');
    bool show_sign = (editcode == '3' || editcode == '4');
    bool show_all_zeros = (editcode == 'X' || editcode == 'x');

    std::string result;
    if (show_all_zeros) {
        // Edit code X: show all digits with leading zeros
        char buf[32];
        snprintf(buf, sizeof(buf), "%07.2f", absval);
        return std::string(buf);
    }

    // Insert commas
    if (use_commas && digits.size() > 3) {
        std::string with_commas;
        int count = 0;
        for (int i = static_cast<int>(digits.size()) - 1; i >= 0; i--) {
            if (count > 0 && count % 3 == 0) with_commas = "," + with_commas;
            with_commas = digits[i] + with_commas;
            count++;
        }
        digits = with_commas;
    }

    char buf[8];
    snprintf(buf, sizeof(buf), ".%02lld", cents);
    result = digits + buf;

    if (show_sign && negative) {
        result += "CR";
    }

    return result;
}

inline std::string rpg_editc(int val, const std::string& code) {
    return rpg_editc(static_cast<double>(val), code);
}

// %EDITW - format number with edit word
inline std::string rpg_editw(double val, const std::string& editword) {
    bool negative = val < 0;
    double absval = negative ? -val : val;

    // Convert to string of digits (including decimals)
    long long scaled = static_cast<long long>(absval * 100 + 0.5);
    std::string digits = std::to_string(scaled);

    // Count blanks in edit word (positions for digits)
    int blank_count = 0;
    for (char c : editword) {
        if (c == ' ') blank_count++;
    }

    // Pad digits to match blank count
    while (static_cast<int>(digits.size()) < blank_count) {
        digits = "0" + digits;
    }

    // Fill in the edit word
    std::string result;
    int dpos = 0;
    bool significant = false;
    for (char c : editword) {
        if (c == ' ') {
            char d = digits[dpos++];
            if (d != '0') significant = true;
            result += significant ? d : ' ';
        } else {
            // Commas, periods, etc. - show only if significant digit has appeared
            if (significant || c == '.' || c == '0') {
                result += c;
            } else {
                result += ' ';
            }
        }
    }
    return result;
}

inline std::string rpg_editw(int val, const std::string& editword) {
    return rpg_editw(static_cast<double>(val), editword);
}

// %STATUS / %ERROR - program status tracking
inline int& rpg_status_code() { static int s = 0; return s; }
inline bool& rpg_error_flag() { static bool e = false; return e; }
inline int rpg_status() { return rpg_status_code(); }
inline int rpg_error() { return rpg_error_flag() ? 1 : 0; }

// --- %CHAR: generic to-string conversion ---
inline std::string rpg_to_char(int v) { return std::to_string(v); }
inline std::string rpg_to_char(double v) { return std::to_string(v); }
inline std::string rpg_to_char(const std::string& v) { return v; }
inline std::string rpg_to_char(bool v) { return v ? "1" : "0"; }

// --- Date/Time/Timestamp types ---

// Helper: parse ISO date "YYYY-MM-DD" into struct tm
inline std::tm rpg_parse_date_tm(const std::string& s) {
    std::tm t = {};
    // Parse YYYY-MM-DD
    t.tm_year = std::stoi(s.substr(0, 4)) - 1900;
    t.tm_mon = std::stoi(s.substr(5, 2)) - 1;
    t.tm_mday = std::stoi(s.substr(8, 2));
    return t;
}

inline std::string rpg_format_date_tm(const std::tm& t) {
    char buf[32];
    std::snprintf(buf, sizeof(buf), "%04d-%02d-%02d",
                  t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
    return buf;
}

struct RpgDate {
    std::string value; // ISO format: YYYY-MM-DD
    RpgDate() : value("0001-01-01") {}
    RpgDate(const std::string& v) : value(v) {}
};

struct RpgTime {
    std::string value; // HH:MM:SS
    RpgTime() : value("00:00:00") {}
    RpgTime(const std::string& v) : value(v) {}
};

struct RpgTimestamp {
    std::string value; // YYYY-MM-DD-HH.MM.SS.MMMMMM
    RpgTimestamp() : value("0001-01-01-00.00.00.000000") {}
    RpgTimestamp(const std::string& v) : value(v) {}
};

struct RpgDuration {
    int amount;
    char unit; // 'D'=days, 'M'=months, 'Y'=years
};

// rpg_to_char overloads for date/time types
inline std::string rpg_to_char(const RpgDate& d) { return d.value; }
inline std::string rpg_to_char(const RpgTime& t) { return t.value; }
inline std::string rpg_to_char(const RpgTimestamp& ts) { return ts.value; }

// %DATE
inline RpgDate rpg_make_date(const std::string& s) { return RpgDate(s); }
inline RpgDate rpg_current_date() {
    time_t now = time(nullptr);
    std::tm* t = localtime(&now);
    return RpgDate(rpg_format_date_tm(*t));
}

// %TIME
inline RpgTime rpg_make_time(const std::string& s) { return RpgTime(s); }
inline RpgTime rpg_current_time() {
    time_t now = time(nullptr);
    std::tm* t = localtime(&now);
    char buf[16];
    std::snprintf(buf, sizeof(buf), "%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);
    return RpgTime(buf);
}

// %TIMESTAMP
inline RpgTimestamp rpg_make_timestamp(const std::string& s) { return RpgTimestamp(s); }
inline RpgTimestamp rpg_current_timestamp() {
    time_t now = time(nullptr);
    std::tm* t = localtime(&now);
    char buf[64];
    std::snprintf(buf, sizeof(buf), "%04d-%02d-%02d-%02d.%02d.%02d.000000",
                  t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                  t->tm_hour, t->tm_min, t->tm_sec);
    return RpgTimestamp(buf);
}

// %DIFF - date difference
inline int rpg_diff_days(const RpgDate& d1, const RpgDate& d2) {
    std::tm t1 = rpg_parse_date_tm(d1.value);
    std::tm t2 = rpg_parse_date_tm(d2.value);
    time_t time1 = mktime(&t1);
    time_t time2 = mktime(&t2);
    return static_cast<int>(difftime(time1, time2) / 86400);
}

inline int rpg_diff_months(const RpgDate& d1, const RpgDate& d2) {
    std::tm t1 = rpg_parse_date_tm(d1.value);
    std::tm t2 = rpg_parse_date_tm(d2.value);
    return (t1.tm_year - t2.tm_year) * 12 + (t1.tm_mon - t2.tm_mon);
}

inline int rpg_diff_years(const RpgDate& d1, const RpgDate& d2) {
    std::tm t1 = rpg_parse_date_tm(d1.value);
    std::tm t2 = rpg_parse_date_tm(d2.value);
    return t1.tm_year - t2.tm_year;
}

// Date + duration arithmetic
inline RpgDate operator+(const RpgDate& d, const RpgDuration& dur) {
    std::tm t = rpg_parse_date_tm(d.value);
    switch (dur.unit) {
        case 'D': t.tm_mday += dur.amount; break;
        case 'M': t.tm_mon += dur.amount; break;
        case 'Y': t.tm_year += dur.amount; break;
    }
    mktime(&t); // normalize
    return RpgDate(rpg_format_date_tm(t));
}

#endif // RPG_RUNTIME_H
