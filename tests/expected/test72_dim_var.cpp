#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::vector<int> NUMS;
    NUMS.reserve(100);
    std::vector<std::string> NAMES;
    NAMES.reserve(50);
    int I = 0;
    int COUNT = 0;
    NUMS.resize(5); // line 8
    for (I = 1; I <= 5; I += 1) {
        NUMS[I - 1] = (I * 10); // line 10
    }
    COUNT = static_cast<int>(NUMS.size()); // line 13
    std::cout << rpg_to_char(COUNT) << std::endl;
    std::cout << rpg_to_char(NUMS[1 - 1]) << std::endl;
    std::cout << rpg_to_char(NUMS[5 - 1]) << std::endl;
    NUMS.resize(3); // line 21
    COUNT = static_cast<int>(NUMS.size()); // line 22
    std::cout << rpg_to_char(COUNT) << std::endl;
    return 0;
}
