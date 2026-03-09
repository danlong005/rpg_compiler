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
    int IDX = 0;
    NUMS[1 - 1] = 30; // line 6
    NUMS[2 - 1] = 10; // line 7
    NUMS[3 - 1] = 50; // line 8
    NUMS[4 - 1] = 20; // line 9
    NUMS[5 - 1] = 40; // line 10
    IDX = rpg_maxarr(NUMS); // line 13
    std::cout << rpg_to_char(IDX) << std::endl;
    IDX = rpg_minarr(NUMS); // line 17
    std::cout << rpg_to_char(IDX) << std::endl;
    IDX = rpg_lookup_ge(25, NUMS); // line 21
    std::cout << rpg_to_char(IDX) << std::endl;
    IDX = rpg_lookup_lt(25, NUMS); // line 25
    std::cout << rpg_to_char(IDX) << std::endl;
    return 0;
}
