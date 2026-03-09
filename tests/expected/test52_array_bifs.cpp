#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::array<int, 5> nums;
    int idx = 0;
    nums[1 - 1] = 30; // line 6
    nums[2 - 1] = 10; // line 7
    nums[3 - 1] = 50; // line 8
    nums[4 - 1] = 20; // line 9
    nums[5 - 1] = 40; // line 10
    idx = rpg_maxarr(nums); // line 13
    std::cout << rpg_to_char(idx) << std::endl;
    idx = rpg_minarr(nums); // line 17
    std::cout << rpg_to_char(idx) << std::endl;
    idx = rpg_lookup_ge(25, nums); // line 21
    std::cout << rpg_to_char(idx) << std::endl;
    idx = rpg_lookup_lt(25, nums); // line 25
    std::cout << rpg_to_char(idx) << std::endl;
    return 0;
}
