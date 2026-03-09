#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int total = 0;
    int x = 0;
    auto sr_addTen = [&]() {
        total = (total + 10); // line 9
    };
    auto sr_showTotal = [&]() {
        std::cout << rpg_to_char(total) << std::endl;
    };
    auto sr_doubleIfSmall = [&]() {
        if (x < 10) {
            x = (x * 2); // line 26
        }
    };
    total = 0; // line 5
    sr_addTen();
    sr_addTen();
    sr_addTen();
    sr_showTotal();
    x = 5; // line 23
    sr_doubleIfSmall();
    std::cout << rpg_to_char(x) << std::endl;
    return 0;
}
