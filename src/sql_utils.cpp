#include "sql_utils.h"
#include <algorithm>
#include <cctype>
#include <regex>

namespace rpg {

static std::string toUpper(const std::string& s) {
    std::string r = s;
    for (auto& c : r) c = toupper(static_cast<unsigned char>(c));
    return r;
}

static bool isIdentChar(char c) {
    return std::isalnum(static_cast<unsigned char>(c)) || c == '_';
}

std::vector<std::string> extractHostVariables(const std::string& sql) {
    std::vector<std::string> vars;
    bool in_string = false;
    for (size_t i = 0; i < sql.size(); i++) {
        if (sql[i] == '\'') {
            in_string = !in_string;
            continue;
        }
        if (in_string) continue;
        if (sql[i] == ':' && i + 1 < sql.size() && (std::isalpha(static_cast<unsigned char>(sql[i+1])) || sql[i+1] == '_')) {
            size_t start = i + 1;
            size_t end = start;
            while (end < sql.size() && isIdentChar(sql[end])) end++;
            vars.push_back(toUpper(sql.substr(start, end - start)));
            i = end - 1;
        }
    }
    return vars;
}

std::string replaceHostVarsWithMarkers(const std::string& sql) {
    std::string result;
    bool in_string = false;
    for (size_t i = 0; i < sql.size(); i++) {
        if (sql[i] == '\'') {
            in_string = !in_string;
            result += sql[i];
            continue;
        }
        if (in_string) {
            result += sql[i];
            continue;
        }
        if (sql[i] == ':' && i + 1 < sql.size() && (std::isalpha(static_cast<unsigned char>(sql[i+1])) || sql[i+1] == '_')) {
            result += '?';
            size_t end = i + 1;
            while (end < sql.size() && isIdentChar(sql[end])) end++;
            i = end - 1;
        } else {
            result += sql[i];
        }
    }
    return result;
}

std::string stripSelectInto(const std::string& sql, std::vector<std::string>& into_vars) {
    // Find "INTO :var1, :var2, ..." in the SQL and remove it
    // Pattern: INTO followed by comma-separated :hostvar references
    std::string upper = toUpper(sql);
    auto pos = upper.find("INTO");
    if (pos == std::string::npos) return sql;

    // Make sure INTO is preceded by whitespace (not part of another word)
    if (pos > 0 && isIdentChar(sql[pos - 1])) return sql;

    // Find the start of the host variables after INTO
    size_t into_start = pos;
    size_t i = pos + 4; // skip "INTO"

    // Skip whitespace
    while (i < sql.size() && std::isspace(static_cast<unsigned char>(sql[i]))) i++;

    // Must start with ':'
    if (i >= sql.size() || sql[i] != ':') return sql;

    // Parse comma-separated :varName list
    size_t clause_end = i;
    while (i < sql.size()) {
        // Skip whitespace
        while (i < sql.size() && std::isspace(static_cast<unsigned char>(sql[i]))) i++;
        if (i >= sql.size() || sql[i] != ':') break;
        i++; // skip ':'
        size_t var_start = i;
        while (i < sql.size() && isIdentChar(sql[i])) i++;
        into_vars.push_back(toUpper(sql.substr(var_start, i - var_start)));
        clause_end = i;
        // Skip whitespace
        while (i < sql.size() && std::isspace(static_cast<unsigned char>(sql[i]))) i++;
        if (i < sql.size() && sql[i] == ',') {
            i++; // skip comma
        } else {
            break;
        }
    }

    // Remove the INTO clause from the SQL
    std::string result = sql.substr(0, into_start);
    // Trim trailing whitespace before INTO
    while (!result.empty() && std::isspace(static_cast<unsigned char>(result.back()))) {
        result.pop_back();
    }
    result += " ";
    result += sql.substr(clause_end);
    return result;
}

std::string extractCursorName(const std::string& sql) {
    std::string upper = toUpper(sql);
    size_t i = 0;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;

    // Skip the leading keyword: DECLARE, OPEN, FETCH, or CLOSE
    // Then the next non-whitespace word is the cursor name
    // Skip keyword
    while (i < upper.size() && !std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Skip whitespace
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Read cursor name
    size_t start = i;
    while (i < upper.size() && isIdentChar(upper[i])) i++;
    return upper.substr(start, i - start);
}

std::string extractCursorQuery(const std::string& sql) {
    // Find "CURSOR FOR" and return everything after it
    std::string upper = toUpper(sql);
    auto pos = upper.find("CURSOR");
    if (pos == std::string::npos) return "";
    pos += 6; // skip "CURSOR"
    // Skip optional whitespace
    while (pos < upper.size() && std::isspace(static_cast<unsigned char>(upper[pos]))) pos++;
    // Expect "FOR"
    if (upper.compare(pos, 3, "FOR") != 0) return "";
    pos += 3;
    // Skip whitespace
    while (pos < sql.size() && std::isspace(static_cast<unsigned char>(sql[pos]))) pos++;
    return sql.substr(pos);
}

std::vector<std::string> extractFetchIntoVars(const std::string& sql) {
    // Find "INTO" after cursor name, then parse :var list
    std::string upper = toUpper(sql);
    auto pos = upper.find("INTO");
    if (pos == std::string::npos) return {};
    // Make sure INTO is not part of another word
    if (pos > 0 && isIdentChar(sql[pos - 1])) return {};

    std::vector<std::string> vars;
    size_t i = pos + 4;
    while (i < sql.size()) {
        while (i < sql.size() && std::isspace(static_cast<unsigned char>(sql[i]))) i++;
        if (i >= sql.size() || sql[i] != ':') break;
        i++; // skip ':'
        size_t var_start = i;
        while (i < sql.size() && isIdentChar(sql[i])) i++;
        vars.push_back(toUpper(sql.substr(var_start, i - var_start)));
        while (i < sql.size() && std::isspace(static_cast<unsigned char>(sql[i]))) i++;
        if (i < sql.size() && sql[i] == ',') {
            i++;
        } else {
            break;
        }
    }
    return vars;
}

void parsePrepare(const std::string& sql, std::string& name, std::string& from_var) {
    std::string upper = toUpper(sql);
    size_t i = 0;
    // Skip whitespace
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Skip "PREPARE"
    i += 7;
    // Skip whitespace
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Read statement name
    size_t start = i;
    while (i < upper.size() && isIdentChar(upper[i])) i++;
    name = upper.substr(start, i - start);
    // Skip whitespace
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Skip "FROM"
    if (upper.compare(i, 4, "FROM") == 0) i += 4;
    // Skip whitespace
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Read :hostvar
    if (i < upper.size() && upper[i] == ':') {
        i++;
        start = i;
        while (i < upper.size() && isIdentChar(upper[i])) i++;
        from_var = upper.substr(start, i - start);
    }
}

void parseExecute(const std::string& sql, std::string& name, std::vector<std::string>& using_vars) {
    std::string upper = toUpper(sql);
    size_t i = 0;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Skip "EXECUTE"
    i += 7;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Read statement name
    size_t start = i;
    while (i < upper.size() && isIdentChar(upper[i])) i++;
    name = upper.substr(start, i - start);
    // Skip whitespace
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Check for USING
    if (upper.compare(i, 5, "USING") == 0) {
        i += 5;
        // Parse comma-separated :var list
        while (i < upper.size()) {
            while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
            if (i >= upper.size() || upper[i] != ':') break;
            i++; // skip ':'
            start = i;
            while (i < upper.size() && isIdentChar(upper[i])) i++;
            using_vars.push_back(upper.substr(start, i - start));
            while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
            if (i < upper.size() && upper[i] == ',') {
                i++;
            } else {
                break;
            }
        }
    }
}

std::string parseExecuteImmediate(const std::string& sql) {
    std::string upper = toUpper(sql);
    size_t i = 0;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Skip "EXECUTE IMMEDIATE"
    i += 17;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    if (i < upper.size() && upper[i] == ':') {
        i++;
        size_t start = i;
        while (i < upper.size() && isIdentChar(upper[i])) i++;
        return upper.substr(start, i - start);
    }
    return "";
}

std::vector<DiagItem> parseGetDiagnostics(const std::string& sql) {
    std::string upper = toUpper(sql);
    size_t i = 0;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Skip "GET DIAGNOSTICS" or "GET DIAGNOSTIC"
    if (upper.compare(i, 15, "GET DIAGNOSTICS") == 0) i += 15;
    else if (upper.compare(i, 14, "GET DIAGNOSTIC") == 0) i += 14;

    std::vector<DiagItem> items;
    // Parse assignments: :var = ITEM_NAME [, :var2 = ITEM_NAME2]
    while (i < upper.size()) {
        while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
        if (i >= upper.size() || upper[i] != ':') break;
        i++; // skip ':'
        size_t start = i;
        while (i < upper.size() && isIdentChar(upper[i])) i++;
        std::string var = upper.substr(start, i - start);
        // Skip whitespace and '='
        while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
        if (i < upper.size() && upper[i] == '=') i++;
        while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
        // Read item name (e.g. ROW_COUNT, DB2_RETURN_STATUS)
        start = i;
        while (i < upper.size() && isIdentChar(upper[i])) i++;
        std::string item = upper.substr(start, i - start);
        items.push_back({var, item});
        while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
        if (i < upper.size() && upper[i] == ',') {
            i++;
        } else {
            break;
        }
    }
    return items;
}

void parseCall(const std::string& sql, std::string& proc_name, std::vector<std::string>& params) {
    size_t i = 0;
    std::string upper = toUpper(sql);
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Skip "CALL"
    i += 4;
    while (i < sql.size() && std::isspace(static_cast<unsigned char>(sql[i]))) i++;
    // Read procedure name (preserve original case)
    size_t start = i;
    while (i < sql.size() && isIdentChar(sql[i])) i++;
    proc_name = sql.substr(start, i - start);
    // Skip whitespace
    while (i < sql.size() && std::isspace(static_cast<unsigned char>(sql[i]))) i++;
    // Parse parameter list in parentheses
    if (i < sql.size() && sql[i] == '(') {
        i++; // skip '('
        while (i < sql.size() && sql[i] != ')') {
            while (i < sql.size() && std::isspace(static_cast<unsigned char>(sql[i]))) i++;
            if (i < sql.size() && sql[i] == ':') {
                i++; // skip ':'
                start = i;
                while (i < sql.size() && isIdentChar(sql[i])) i++;
                params.push_back(toUpper(sql.substr(start, i - start)));
            }
            while (i < sql.size() && std::isspace(static_cast<unsigned char>(sql[i]))) i++;
            if (i < sql.size() && sql[i] == ',') {
                i++;
            } else {
                break;
            }
        }
    }
}

ConnectInfo parseConnect(const std::string& sql) {
    ConnectInfo info;
    std::string upper = toUpper(sql);
    size_t i = 0;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Skip "CONNECT"
    i += 7;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;

    // Check for RESET
    if (upper.compare(i, 5, "RESET") == 0) {
        info.is_reset = true;
        return info;
    }

    // Check for USING :connStr (connection string variant, no TO keyword)
    if (upper.compare(i, 5, "USING") == 0 && (i == 0 || !isIdentChar(upper[i-1]))) {
        i += 5;
        while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
        if (i < upper.size() && upper[i] == ':') {
            i++;
            size_t start = i;
            while (i < upper.size() && isIdentChar(upper[i])) i++;
            info.server = upper.substr(start, i - start);
            info.user = "__CONNSTR__"; // sentinel to indicate connection string mode
            return info;
        }
    }

    // Optional "TO"
    if (upper.compare(i, 2, "TO") == 0) {
        i += 2;
        while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    }

    // Read server/dsn (host var or literal)
    if (i < upper.size() && upper[i] == ':') {
        i++;
        size_t start = i;
        while (i < upper.size() && isIdentChar(upper[i])) i++;
        info.server = upper.substr(start, i - start);
    } else {
        size_t start = i;
        while (i < upper.size() && isIdentChar(upper[i])) i++;
        info.server = upper.substr(start, i - start);
    }

    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;

    // Optional USER clause
    if (upper.compare(i, 4, "USER") == 0) {
        i += 4;
        while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
        if (i < upper.size() && upper[i] == ':') {
            i++;
            size_t start = i;
            while (i < upper.size() && isIdentChar(upper[i])) i++;
            info.user = upper.substr(start, i - start);
        }
        while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;

        // USING password
        if (upper.compare(i, 5, "USING") == 0) {
            i += 5;
            while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
            if (i < upper.size() && upper[i] == ':') {
                i++;
                size_t start = i;
                while (i < upper.size() && isIdentChar(upper[i])) i++;
                info.password = upper.substr(start, i - start);
            }
        }
    }
    return info;
}

std::string parseSetConnection(const std::string& sql) {
    std::string upper = toUpper(sql);
    size_t i = 0;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Skip "SET CONNECTION"
    if (upper.compare(i, 14, "SET CONNECTION") == 0) i += 14;
    else if (upper.compare(i, 13, "SET CONNECTIO") == 0) i += 13; // fallback
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;

    // Read connection name (host var or literal)
    if (i < upper.size() && upper[i] == ':') {
        i++;
        size_t start = i;
        while (i < upper.size() && isIdentChar(upper[i])) i++;
        return upper.substr(start, i - start);
    }
    size_t start = i;
    while (i < upper.size() && isIdentChar(upper[i])) i++;
    return upper.substr(start, i - start);
}

bool parseFetchForRows(const std::string& sql, std::string& rows_var) {
    std::string upper = toUpper(sql);
    // Look for "FOR :var ROWS" pattern
    // Pattern: after cursor name, before INTO
    auto for_pos = upper.find("FOR");
    if (for_pos == std::string::npos) return false;
    // Make sure FOR is not part of another word
    if (for_pos > 0 && isIdentChar(upper[for_pos - 1])) return false;

    size_t i = for_pos + 3;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Expect :hostvar
    if (i >= upper.size() || upper[i] != ':') return false;
    i++;
    size_t start = i;
    while (i < upper.size() && isIdentChar(upper[i])) i++;
    rows_var = upper.substr(start, i - start);
    // Skip whitespace
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    // Expect "ROWS"
    if (upper.compare(i, 4, "ROWS") != 0) return false;
    return true;
}

bool parseInsertForRows(const std::string& sql, std::string& rows_var, std::string& stripped_sql) {
    std::string upper = toUpper(sql);
    // Look for "FOR :var ROWS" at the end of the statement
    // Search backwards for "ROWS"
    auto rows_pos = upper.rfind("ROWS");
    if (rows_pos == std::string::npos) return false;

    // Work backwards from ROWS to find ":var"
    size_t i = rows_pos;
    // Skip whitespace before ROWS
    while (i > 0 && std::isspace(static_cast<unsigned char>(upper[i-1]))) i--;
    // Read host var backwards
    size_t var_end = i;
    while (i > 0 && isIdentChar(upper[i-1])) i--;
    size_t var_start = i;
    // Expect ':' before var
    if (i == 0 || upper[i-1] != ':') return false;
    rows_var = upper.substr(var_start, var_end - var_start);
    i--; // skip ':'
    // Skip whitespace before ':'
    while (i > 0 && std::isspace(static_cast<unsigned char>(upper[i-1]))) i--;
    // Expect "FOR" before
    if (i < 3 || upper.compare(i - 3, 3, "FOR") != 0) return false;
    size_t for_start = i - 3;
    // Make sure FOR is not part of another word
    if (for_start > 0 && isIdentChar(upper[for_start - 1])) return false;

    // Strip "FOR :var ROWS" from the SQL
    stripped_sql = sql.substr(0, for_start);
    // Trim trailing whitespace
    while (!stripped_sql.empty() && std::isspace(static_cast<unsigned char>(stripped_sql.back()))) {
        stripped_sql.pop_back();
    }
    return true;
}

SqlStmtKind classifySqlStmt(const std::string& sql) {
    // Skip leading whitespace
    std::string upper = toUpper(sql);
    size_t i = 0;
    while (i < upper.size() && std::isspace(static_cast<unsigned char>(upper[i]))) i++;
    std::string rest = upper.substr(i);

    if (rest.compare(0, 11, "SELECT INTO") == 0 ||
        (rest.compare(0, 6, "SELECT") == 0 && upper.find("INTO") != std::string::npos))
        return SqlStmtKind::SELECT_INTO;
    if (rest.compare(0, 6, "INSERT") == 0) return SqlStmtKind::INSERT;
    if (rest.compare(0, 6, "UPDATE") == 0) return SqlStmtKind::UPDATE;
    if (rest.compare(0, 6, "DELETE") == 0) return SqlStmtKind::DELETE_SQL;
    if (rest.compare(0, 6, "COMMIT") == 0) return SqlStmtKind::COMMIT;
    if (rest.compare(0, 8, "ROLLBACK") == 0) {
        // "ROLLBACK TO SAVEPOINT" is passthrough SQL, not a simple rollback
        size_t rb = 8;
        while (rb < rest.size() && std::isspace(static_cast<unsigned char>(rest[rb]))) rb++;
        if (rest.compare(rb, 2, "TO") == 0) return SqlStmtKind::OTHER;
        return SqlStmtKind::ROLLBACK;
    }
    if (rest.compare(0, 7, "DECLARE") == 0) return SqlStmtKind::DECLARE_CURSOR;
    if (rest.compare(0, 4, "OPEN") == 0) return SqlStmtKind::OPEN_CURSOR;
    if (rest.compare(0, 5, "FETCH") == 0) return SqlStmtKind::FETCH;
    if (rest.compare(0, 5, "CLOSE") == 0) return SqlStmtKind::CLOSE_CURSOR;
    if (rest.compare(0, 7, "CONNECT") == 0) return SqlStmtKind::CONNECT;
    if (rest.compare(0, 10, "DISCONNECT") == 0) return SqlStmtKind::DISCONNECT;
    if (rest.compare(0, 14, "SET CONNECTION") == 0) return SqlStmtKind::SET_CONNECTION;
    if (rest.compare(0, 7, "PREPARE") == 0) return SqlStmtKind::PREPARE;
    if (rest.compare(0, 17, "EXECUTE IMMEDIATE") == 0) return SqlStmtKind::EXECUTE_IMMEDIATE;
    if (rest.compare(0, 7, "EXECUTE") == 0) return SqlStmtKind::EXECUTE;
    if (rest.compare(0, 15, "GET DIAGNOSTICS") == 0 || rest.compare(0, 14, "GET DIAGNOSTIC") == 0)
        return SqlStmtKind::GET_DIAGNOSTICS;
    if (rest.compare(0, 4, "CALL") == 0) return SqlStmtKind::CALL;
    if (rest.compare(0, 3, "SET") == 0) return SqlStmtKind::SET;
    return SqlStmtKind::OTHER;
}

} // namespace rpg
