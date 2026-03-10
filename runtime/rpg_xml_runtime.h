#ifndef RPG_XML_RUNTIME_H
#define RPG_XML_RUNTIME_H

// Lightweight XML parser for RPG XML-INTO support
// Parses XML strings into a simple DOM for field extraction

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

struct RpgXmlNode {
    std::string name;
    std::string text;
    std::vector<RpgXmlNode> children;
    std::vector<std::pair<std::string, std::string>> attributes;
};

struct RpgXmlDoc {
    RpgXmlNode root;
};

namespace rpg_xml_detail {

inline void skip_ws(const std::string& s, size_t& pos) {
    while (pos < s.size() && std::isspace(static_cast<unsigned char>(s[pos]))) pos++;
}

inline void skip_xml_decl(const std::string& s, size_t& pos) {
    skip_ws(s, pos);
    if (pos + 1 < s.size() && s[pos] == '<' && s[pos + 1] == '?') {
        auto end = s.find("?>", pos);
        if (end != std::string::npos) pos = end + 2;
    }
}

inline std::string decode_entity(const std::string& text) {
    std::string result;
    result.reserve(text.size());
    for (size_t i = 0; i < text.size(); i++) {
        if (text[i] == '&') {
            if (text.compare(i, 4, "&lt;") == 0) { result += '<'; i += 3; }
            else if (text.compare(i, 4, "&gt;") == 0) { result += '>'; i += 3; }
            else if (text.compare(i, 5, "&amp;") == 0) { result += '&'; i += 4; }
            else if (text.compare(i, 6, "&apos;") == 0) { result += '\''; i += 5; }
            else if (text.compare(i, 6, "&quot;") == 0) { result += '"'; i += 5; }
            else result += text[i];
        } else {
            result += text[i];
        }
    }
    return result;
}

inline std::string parse_attr_value(const std::string& s, size_t& pos) {
    char quote = s[pos++]; // consume opening quote
    std::string val;
    while (pos < s.size() && s[pos] != quote) {
        val += s[pos++];
    }
    if (pos < s.size()) pos++; // consume closing quote
    return decode_entity(val);
}

inline RpgXmlNode parse_element(const std::string& s, size_t& pos) {
    RpgXmlNode node;
    skip_ws(s, pos);

    if (pos >= s.size() || s[pos] != '<') return node;
    pos++; // skip '<'

    // Parse tag name
    while (pos < s.size() && !std::isspace(static_cast<unsigned char>(s[pos]))
           && s[pos] != '>' && s[pos] != '/') {
        node.name += s[pos++];
    }

    // Parse attributes
    while (pos < s.size() && s[pos] != '>' && s[pos] != '/') {
        skip_ws(s, pos);
        if (pos < s.size() && s[pos] != '>' && s[pos] != '/') {
            std::string attr_name;
            while (pos < s.size() && s[pos] != '=' && s[pos] != '>'
                   && !std::isspace(static_cast<unsigned char>(s[pos]))) {
                attr_name += s[pos++];
            }
            skip_ws(s, pos);
            if (pos < s.size() && s[pos] == '=') {
                pos++; // skip '='
                skip_ws(s, pos);
                if (pos < s.size() && (s[pos] == '"' || s[pos] == '\'')) {
                    node.attributes.push_back({attr_name, parse_attr_value(s, pos)});
                }
            }
        }
    }

    // Self-closing tag?
    if (pos < s.size() && s[pos] == '/') {
        pos++; // skip '/'
        if (pos < s.size() && s[pos] == '>') pos++; // skip '>'
        return node;
    }

    if (pos < s.size() && s[pos] == '>') pos++; // skip '>'

    // Parse content (text and child elements)
    while (pos < s.size()) {
        skip_ws(s, pos);
        if (pos >= s.size()) break;

        // End tag?
        if (pos + 1 < s.size() && s[pos] == '<' && s[pos + 1] == '/') {
            pos += 2; // skip '</'
            // Skip tag name
            while (pos < s.size() && s[pos] != '>') pos++;
            if (pos < s.size()) pos++; // skip '>'
            break;
        }

        // Child element?
        if (s[pos] == '<') {
            // Skip comments
            if (pos + 3 < s.size() && s[pos+1] == '!' && s[pos+2] == '-' && s[pos+3] == '-') {
                auto end = s.find("-->", pos);
                if (end != std::string::npos) { pos = end + 3; continue; }
            }
            // Skip CDATA
            if (pos + 8 < s.size() && s.compare(pos, 9, "<![CDATA[") == 0) {
                auto end = s.find("]]>", pos);
                if (end != std::string::npos) {
                    node.text += s.substr(pos + 9, end - pos - 9);
                    pos = end + 3;
                    continue;
                }
            }
            node.children.push_back(parse_element(s, pos));
        } else {
            // Text content
            std::string text;
            while (pos < s.size() && s[pos] != '<') {
                text += s[pos++];
            }
            // Trim trailing whitespace
            while (!text.empty() && std::isspace(static_cast<unsigned char>(text.back())))
                text.pop_back();
            if (!text.empty())
                node.text += decode_entity(text);
        }
    }

    return node;
}

} // namespace rpg_xml_detail

// Parse an XML string into a document
inline RpgXmlDoc rpg_xml_parse(const std::string& xml) {
    RpgXmlDoc doc;
    size_t pos = 0;
    rpg_xml_detail::skip_xml_decl(xml, pos);
    rpg_xml_detail::skip_ws(xml, pos);
    if (pos < xml.size()) {
        doc.root = rpg_xml_detail::parse_element(xml, pos);
    }
    return doc;
}

// Case-insensitive string compare
inline bool rpg_xml_name_match(const std::string& a, const std::string& b, bool case_any) {
    if (!case_any) return a == b;
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (std::toupper(static_cast<unsigned char>(a[i])) !=
            std::toupper(static_cast<unsigned char>(b[i])))
            return false;
    }
    return true;
}

// Find a child element by name
inline const RpgXmlNode* rpg_xml_find(const RpgXmlNode& node, const std::string& name, bool case_any) {
    for (auto& child : node.children) {
        if (rpg_xml_name_match(child.name, name, case_any))
            return &child;
    }
    return nullptr;
}

// Extract string value from a named child element
inline std::string rpg_xml_get_str(const RpgXmlNode& node, const std::string& name, bool case_any) {
    const RpgXmlNode* child = rpg_xml_find(node, name, case_any);
    return child ? child->text : "";
}

// Extract integer value from a named child element
inline int rpg_xml_get_int(const RpgXmlNode& node, const std::string& name, bool case_any) {
    const RpgXmlNode* child = rpg_xml_find(node, name, case_any);
    if (!child || child->text.empty()) return 0;
    return std::atoi(child->text.c_str());
}

// Extract double value from a named child element
inline double rpg_xml_get_double(const RpgXmlNode& node, const std::string& name, bool case_any) {
    const RpgXmlNode* child = rpg_xml_find(node, name, case_any);
    if (!child || child->text.empty()) return 0.0;
    return std::atof(child->text.c_str());
}

// Navigate to a descendant node via slash-separated path (e.g., "data/orders/order")
// If the first path segment matches the root element name, it is consumed (RPG convention).
inline const RpgXmlNode* rpg_xml_navigate(const RpgXmlNode& root, const std::string& path, bool case_any) {
    const RpgXmlNode* cur = &root;
    size_t start = 0;
    bool first = true;
    while (start < path.size()) {
        size_t slash = path.find('/', start);
        std::string segment = (slash == std::string::npos)
            ? path.substr(start) : path.substr(start, slash - start);
        start = (slash == std::string::npos) ? path.size() : slash + 1;
        if (segment.empty()) continue;
        // If first segment matches root name, skip it (root is already current)
        if (first && rpg_xml_name_match(cur->name, segment, case_any)) {
            first = false;
            continue;
        }
        first = false;
        const RpgXmlNode* found = rpg_xml_find(*cur, segment, case_any);
        if (!found) return nullptr;
        cur = found;
    }
    return cur;
}

// Collect all children matching a name (for array DS loading)
inline std::vector<const RpgXmlNode*> rpg_xml_find_all(const RpgXmlNode& node, const std::string& name, bool case_any) {
    std::vector<const RpgXmlNode*> result;
    for (auto& child : node.children) {
        if (rpg_xml_name_match(child.name, name, case_any))
            result.push_back(&child);
    }
    return result;
}

#endif // RPG_XML_RUNTIME_H
