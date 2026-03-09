#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::array<int, 5> nums;
    int total = 0;
    nums[1 - 1] = 10; // line 6
    nums[2 - 1] = 20; // line 7
    nums[3 - 1] = 30; // line 8
    nums[4 - 1] = 40; // line 9
    nums[5 - 1] = 50; // line 10
    total = rpg_xfoot(nums); // line 13
    std::cout << rpg_to_char(total) << std::endl;
    return 0;
}
