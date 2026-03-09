#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::array<std::string, 3> names;
    std::string name(10, ' ');
    int val = 0;
    names[1 - 1] = "Alice"; // line 7
    names[2 - 1] = "Bob"; // line 8
    names[3 - 1] = "Charlie"; // line 9
    for (auto& name : names) {
        std::cout << rpg_trim(name) << std::endl;
    }
    val = 5; // line 17
    if (rpg_in_list(val, rpg_list(1, 3, 5, 7))) {
        std::cout << "Found in list" << std::endl;
    }
    val = 15; // line 23
    if (rpg_in_range(val, rpg_range(10, 20))) {
        std::cout << "In range" << std::endl;
    }
    val = 99; // line 29
    if (!(rpg_in_list(val, rpg_list(1, 2, 3)))) {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}
