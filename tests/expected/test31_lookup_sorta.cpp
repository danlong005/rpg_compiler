#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::array<int, 5> NUMS;
    std::array<std::string, 4> NAMES;
    int POS = 0;
    int I = 0;
    NUMS[1 - 1] = 30; // line 8
    NUMS[2 - 1] = 10; // line 9
    NUMS[3 - 1] = 50; // line 10
    NUMS[4 - 1] = 20; // line 11
    NUMS[5 - 1] = 40; // line 12
    POS = rpg_lookup(50, NUMS); // line 15
    std::cout << rpg_to_char(POS) << std::endl;
    POS = rpg_lookup(99, NUMS); // line 18
    std::cout << rpg_to_char(POS) << std::endl;
    std::sort(NUMS.begin(), NUMS.end());
    for (I = 1; I <= 5; I += 1) {
        std::cout << rpg_to_char(NUMS[I - 1]) << std::endl;
    }
    POS = rpg_lookup(30, NUMS); // line 28
    std::cout << rpg_to_char(POS) << std::endl;
    NAMES[1 - 1] = "Charlie"; // line 32
    NAMES[2 - 1] = "Alice"; // line 33
    NAMES[3 - 1] = "Bob"; // line 34
    NAMES[4 - 1] = "Dave"; // line 35
    std::sort(NAMES.begin(), NAMES.end());
    for (I = 1; I <= 4; I += 1) {
        std::cout << NAMES[I - 1] << std::endl;
    }
    return 0;
}
