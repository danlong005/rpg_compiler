#ifndef RPG_CSV_RUNTIME_H
#define RPG_CSV_RUNTIME_H

// Lightweight CSV parser/generator for RPG DATA-INTO / DATA-GEN with %PARSER('CSV')

#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cctype>

struct RpgCsvDoc {
    std::vector<std::string> headers;           // column names from first row
    std::vector<std::vector<std::string>> rows; // data rows
};

namespace rpg_csv_detail {

// Split a single CSV line respecting RFC 4180 quoting.
inline std::vector<std::string> split_line(const std::string& line, char delim) {
    std::vector<std::string> fields;
    std::string field;
    bool in_quotes = false;
    for (size_t i = 0; i < line.size(); i++) {
        char c = line[i];
        if (in_quotes) {
            if (c == '"') {
                // Peek: doubled quote is an escaped quote
                if (i + 1 < line.size() && line[i + 1] == '"') {
                    field += '"';
                    i++;
                } else {
                    in_quotes = false;
                }
            } else {
                field += c;
            }
        } else {
            if (c == '"') {
                in_quotes = true;
            } else if (c == delim) {
                fields.push_back(field);
                field.clear();
            } else {
                field += c;
            }
        }
    }
    fields.push_back(field);
    return fields;
}

} // namespace rpg_csv_detail

inline RpgCsvDoc rpg_csv_parse(const std::string& csv, char delimiter = ',', bool has_header = true) {
    RpgCsvDoc doc;
    bool first = true;
    size_t start = 0;
    while (start <= csv.size()) {
        size_t end = csv.find('\n', start);
        std::string line = (end == std::string::npos)
            ? csv.substr(start)
            : csv.substr(start, end - start);
        // Strip trailing \r
        if (!line.empty() && line.back() == '\r') line.pop_back();
        start = (end == std::string::npos) ? csv.size() + 1 : end + 1;

        if (line.empty()) continue;

        auto fields = rpg_csv_detail::split_line(line, delimiter);
        if (first && has_header) {
            doc.headers = fields;
            first = false;
        } else {
            doc.rows.push_back(fields);
            first = false;
        }
    }
    return doc;
}

inline bool rpg_csv_name_match(const std::string& a, const std::string& b, bool case_any) {
    if (!case_any) return a == b;
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (std::toupper(static_cast<unsigned char>(a[i])) !=
            std::toupper(static_cast<unsigned char>(b[i])))
            return false;
    }
    return true;
}

inline int rpg_csv_col_index(const std::vector<std::string>& headers,
                              const std::string& name, bool case_any) {
    for (int i = 0; i < static_cast<int>(headers.size()); i++) {
        if (rpg_csv_name_match(headers[i], name, case_any))
            return i;
    }
    return -1;
}

inline std::string rpg_csv_get_str(const RpgCsvDoc& doc, size_t row_idx,
                                    const std::string& name, bool case_any) {
    if (row_idx >= doc.rows.size()) return "";
    int col = rpg_csv_col_index(doc.headers, name, case_any);
    if (col < 0 || col >= static_cast<int>(doc.rows[row_idx].size())) return "";
    return doc.rows[row_idx][col];
}

inline int rpg_csv_get_int(const RpgCsvDoc& doc, size_t row_idx,
                            const std::string& name, bool case_any) {
    std::string val = rpg_csv_get_str(doc, row_idx, name, case_any);
    if (val.empty()) return 0;
    return std::atoi(val.c_str());
}

inline double rpg_csv_get_double(const RpgCsvDoc& doc, size_t row_idx,
                                  const std::string& name, bool case_any) {
    std::string val = rpg_csv_get_str(doc, row_idx, name, case_any);
    if (val.empty()) return 0.0;
    return std::atof(val.c_str());
}

// Quote a field value for CSV output: wrap in double-quotes if it contains the
// delimiter, a double-quote, or a newline. Embedded double-quotes are doubled.
inline std::string rpg_csv_escape(const std::string& val, char delimiter) {
    bool needs_quoting = false;
    for (char c : val) {
        if (c == delimiter || c == '"' || c == '\n' || c == '\r') {
            needs_quoting = true;
            break;
        }
    }
    if (!needs_quoting) return val;
    std::string result = "\"";
    for (char c : val) {
        if (c == '"') result += "\"\"";
        else result += c;
    }
    result += '"';
    return result;
}

#endif // RPG_CSV_RUNTIME_H
