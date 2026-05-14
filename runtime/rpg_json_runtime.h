#ifndef RPG_JSON_RUNTIME_H
#define RPG_JSON_RUNTIME_H

// Lightweight JSON parser/generator for RPG DATA-INTO / DATA-GEN support

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <sstream>

struct RpgJsonNode {
    enum Type { Null, String, Number, Bool, Object, Array } type = Null;
    std::string str_val;
    double num_val = 0.0;
    bool bool_val = false;
    std::vector<std::pair<std::string, RpgJsonNode>> fields; // for Object
    std::vector<RpgJsonNode> items;                          // for Array
};

namespace rpg_json_detail {

inline void skip_ws(const std::string& s, size_t& pos) {
    while (pos < s.size() && std::isspace(static_cast<unsigned char>(s[pos]))) pos++;
}

inline std::string parse_string(const std::string& s, size_t& pos) {
    // pos points at opening '"'
    pos++; // skip '"'
    std::string result;
    while (pos < s.size() && s[pos] != '"') {
        if (s[pos] == '\\' && pos + 1 < s.size()) {
            pos++;
            switch (s[pos]) {
                case '"':  result += '"';  break;
                case '\\': result += '\\'; break;
                case '/':  result += '/';  break;
                case 'n':  result += '\n'; break;
                case 'r':  result += '\r'; break;
                case 't':  result += '\t'; break;
                case 'b':  result += '\b'; break;
                case 'f':  result += '\f'; break;
                default:   result += s[pos]; break;
            }
        } else {
            result += s[pos];
        }
        pos++;
    }
    if (pos < s.size()) pos++; // skip closing '"'
    return result;
}

inline RpgJsonNode parse_value(const std::string& s, size_t& pos);

inline RpgJsonNode parse_object(const std::string& s, size_t& pos) {
    RpgJsonNode node;
    node.type = RpgJsonNode::Object;
    pos++; // skip '{'
    skip_ws(s, pos);
    if (pos < s.size() && s[pos] == '}') { pos++; return node; }
    while (pos < s.size()) {
        skip_ws(s, pos);
        if (pos >= s.size() || s[pos] != '"') break;
        std::string key = parse_string(s, pos);
        skip_ws(s, pos);
        if (pos < s.size() && s[pos] == ':') pos++; // skip ':'
        skip_ws(s, pos);
        RpgJsonNode val = parse_value(s, pos);
        node.fields.push_back({key, std::move(val)});
        skip_ws(s, pos);
        if (pos < s.size() && s[pos] == ',') { pos++; continue; }
        if (pos < s.size() && s[pos] == '}') { pos++; break; }
        break;
    }
    return node;
}

inline RpgJsonNode parse_array(const std::string& s, size_t& pos) {
    RpgJsonNode node;
    node.type = RpgJsonNode::Array;
    pos++; // skip '['
    skip_ws(s, pos);
    if (pos < s.size() && s[pos] == ']') { pos++; return node; }
    while (pos < s.size()) {
        skip_ws(s, pos);
        node.items.push_back(parse_value(s, pos));
        skip_ws(s, pos);
        if (pos < s.size() && s[pos] == ',') { pos++; continue; }
        if (pos < s.size() && s[pos] == ']') { pos++; break; }
        break;
    }
    return node;
}

inline RpgJsonNode parse_value(const std::string& s, size_t& pos) {
    skip_ws(s, pos);
    if (pos >= s.size()) return RpgJsonNode{};
    char c = s[pos];
    if (c == '{') return parse_object(s, pos);
    if (c == '[') return parse_array(s, pos);
    if (c == '"') {
        RpgJsonNode n;
        n.type = RpgJsonNode::String;
        n.str_val = parse_string(s, pos);
        return n;
    }
    if (s.compare(pos, 4, "true") == 0) {
        RpgJsonNode n; n.type = RpgJsonNode::Bool; n.bool_val = true; pos += 4; return n;
    }
    if (s.compare(pos, 5, "false") == 0) {
        RpgJsonNode n; n.type = RpgJsonNode::Bool; n.bool_val = false; pos += 5; return n;
    }
    if (s.compare(pos, 4, "null") == 0) {
        RpgJsonNode n; n.type = RpgJsonNode::Null; pos += 4; return n;
    }
    // Number
    if (c == '-' || std::isdigit(static_cast<unsigned char>(c))) {
        size_t start = pos;
        if (s[pos] == '-') pos++;
        while (pos < s.size() && std::isdigit(static_cast<unsigned char>(s[pos]))) pos++;
        if (pos < s.size() && s[pos] == '.') {
            pos++;
            while (pos < s.size() && std::isdigit(static_cast<unsigned char>(s[pos]))) pos++;
        }
        if (pos < s.size() && (s[pos] == 'e' || s[pos] == 'E')) {
            pos++;
            if (pos < s.size() && (s[pos] == '+' || s[pos] == '-')) pos++;
            while (pos < s.size() && std::isdigit(static_cast<unsigned char>(s[pos]))) pos++;
        }
        RpgJsonNode n;
        n.type = RpgJsonNode::Number;
        n.num_val = std::atof(s.substr(start, pos - start).c_str());
        n.str_val = s.substr(start, pos - start);
        return n;
    }
    return RpgJsonNode{};
}

} // namespace rpg_json_detail

inline RpgJsonNode rpg_json_parse(const std::string& json) {
    size_t pos = 0;
    rpg_json_detail::skip_ws(json, pos);
    return rpg_json_detail::parse_value(json, pos);
}

inline bool rpg_json_name_match(const std::string& a, const std::string& b, bool case_any) {
    if (!case_any) return a == b;
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (std::toupper(static_cast<unsigned char>(a[i])) !=
            std::toupper(static_cast<unsigned char>(b[i])))
            return false;
    }
    return true;
}

inline const RpgJsonNode* rpg_json_find(const RpgJsonNode& node, const std::string& name, bool case_any) {
    if (node.type != RpgJsonNode::Object) return nullptr;
    for (auto& f : node.fields) {
        if (rpg_json_name_match(f.first, name, case_any))
            return &f.second;
    }
    return nullptr;
}

inline std::string rpg_json_get_str(const RpgJsonNode& node, const std::string& name, bool case_any) {
    const RpgJsonNode* child = rpg_json_find(node, name, case_any);
    if (!child) return "";
    if (child->type == RpgJsonNode::String) return child->str_val;
    if (child->type == RpgJsonNode::Number) return child->str_val;
    if (child->type == RpgJsonNode::Bool) return child->bool_val ? "1" : "0";
    return "";
}

inline int rpg_json_get_int(const RpgJsonNode& node, const std::string& name, bool case_any) {
    const RpgJsonNode* child = rpg_json_find(node, name, case_any);
    if (!child) return 0;
    if (child->type == RpgJsonNode::Number) return static_cast<int>(child->num_val);
    if (child->type == RpgJsonNode::String) return std::atoi(child->str_val.c_str());
    if (child->type == RpgJsonNode::Bool) return child->bool_val ? 1 : 0;
    return 0;
}

inline double rpg_json_get_double(const RpgJsonNode& node, const std::string& name, bool case_any) {
    const RpgJsonNode* child = rpg_json_find(node, name, case_any);
    if (!child) return 0.0;
    if (child->type == RpgJsonNode::Number) return child->num_val;
    if (child->type == RpgJsonNode::String) return std::atof(child->str_val.c_str());
    if (child->type == RpgJsonNode::Bool) return child->bool_val ? 1.0 : 0.0;
    return 0.0;
}

// JSON string escaping for DATA-GEN output
inline std::string rpg_json_escape(const std::string& s) {
    std::string result;
    result.reserve(s.size() + 4);
    for (unsigned char c : s) {
        if (c == '"')       result += "\\\"";
        else if (c == '\\') result += "\\\\";
        else if (c == '\n') result += "\\n";
        else if (c == '\r') result += "\\r";
        else if (c == '\t') result += "\\t";
        else                result += static_cast<char>(c);
    }
    return result;
}

#endif // RPG_JSON_RUNTIME_H
