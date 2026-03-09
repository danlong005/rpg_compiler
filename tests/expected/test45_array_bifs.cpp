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
    int TOTAL = 0;
    NUMS[1 - 1] = 10; // line 6
    NUMS[2 - 1] = 20; // line 7
    NUMS[3 - 1] = 30; // line 8
    NUMS[4 - 1] = 40; // line 9
    NUMS[5 - 1] = 50; // line 10
    TOTAL = rpg_xfoot(NUMS); // line 13
    std::cout << rpg_to_char(TOTAL) << std::endl;
    return 0;
}
