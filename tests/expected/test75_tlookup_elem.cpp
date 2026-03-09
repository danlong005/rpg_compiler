#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::array<std::string, 4> CODES;
    std::array<std::string, 4> NAMES;
    bool FOUND = false;
    int COUNT = 0;
    std::vector<int> DYNARR;
    DYNARR.reserve(50);
    CODES[1 - 1] = "NYC"; // line 8
    CODES[2 - 1] = "LAX"; // line 9
    CODES[3 - 1] = "ORD"; // line 10
    CODES[4 - 1] = "DFW"; // line 11
    NAMES[1 - 1] = "New York"; // line 13
    NAMES[2 - 1] = "Los Angeles"; // line 14
    NAMES[3 - 1] = "Chicago"; // line 15
    NAMES[4 - 1] = "Dallas"; // line 16
    FOUND = rpg_tlookup("LAX", CODES); // line 19
    if (FOUND) {
        std::cout << "Found LAX" << std::endl;
    }
    FOUND = rpg_tlookup("SFO", CODES); // line 25
    if (!(FOUND)) {
        std::cout << "SFO not found" << std::endl;
    }
    FOUND = rpg_tlookup_ge("LAX", CODES); // line 31
    if (FOUND) {
        std::cout << "Found >= LAX" << std::endl;
    }
    DYNARR.resize(3); // line 38
    DYNARR[1 - 1] = 10; // line 39
    DYNARR[2 - 1] = 20; // line 40
    DYNARR[3 - 1] = 30; // line 41
    COUNT = static_cast<int>(DYNARR.size()); // line 42
    std::cout << rpg_to_char(COUNT) << std::endl;
    DYNARR.resize(5); // line 46
    DYNARR[4 - 1] = 40; // line 47
    DYNARR[5 - 1] = 50; // line 48
    COUNT = static_cast<int>(DYNARR.size()); // line 49
    std::cout << rpg_to_char(COUNT) << std::endl;
    return 0;
}
