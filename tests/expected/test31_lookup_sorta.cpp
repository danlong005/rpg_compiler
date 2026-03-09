#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::array<int, 5> nums;
    std::array<std::string, 4> names;
    int pos = 0;
    int i = 0;
    nums[1 - 1] = 30; // line 8
    nums[2 - 1] = 10; // line 9
    nums[3 - 1] = 50; // line 10
    nums[4 - 1] = 20; // line 11
    nums[5 - 1] = 40; // line 12
    pos = rpg_lookup(50, nums); // line 15
    std::cout << rpg_to_char(pos) << std::endl;
    pos = rpg_lookup(99, nums); // line 18
    std::cout << rpg_to_char(pos) << std::endl;
    std::sort(nums.begin(), nums.end());
    for (i = 1; i <= 5; i += 1) {
        std::cout << rpg_to_char(nums[i - 1]) << std::endl;
    }
    pos = rpg_lookup(30, nums); // line 28
    std::cout << rpg_to_char(pos) << std::endl;
    names[1 - 1] = "Charlie"; // line 32
    names[2 - 1] = "Alice"; // line 33
    names[3 - 1] = "Bob"; // line 34
    names[4 - 1] = "Dave"; // line 35
    std::sort(names.begin(), names.end());
    for (i = 1; i <= 4; i += 1) {
        std::cout << names[i - 1] << std::endl;
    }
    return 0;
}
