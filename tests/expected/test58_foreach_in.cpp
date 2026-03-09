#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::array<std::string, 3> NAMES;
    std::string NAME(10, ' ');
    int VAL = 0;
    NAMES[1 - 1] = "Alice"; // line 7
    NAMES[2 - 1] = "Bob"; // line 8
    NAMES[3 - 1] = "Charlie"; // line 9
    for (auto& NAME : NAMES) {
        std::cout << rpg_trim(NAME) << std::endl;
    }
    VAL = 5; // line 17
    if (rpg_in_list(VAL, rpg_list(1, 3, 5, 7))) {
        std::cout << "Found in list" << std::endl;
    }
    VAL = 15; // line 23
    if (rpg_in_range(VAL, rpg_range(10, 20))) {
        std::cout << "In range" << std::endl;
    }
    VAL = 99; // line 29
    if (!(rpg_in_list(VAL, rpg_list(1, 2, 3)))) {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}
