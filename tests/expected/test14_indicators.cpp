#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int x = 0;
    rpg_indicators[1] = 1; // line 5
    rpg_indicators[2] = 0; // line 6
    rpg_indicators[50] = 1; // line 7
    if (rpg_indicators[1]) {
        std::cout << "IN01 is on" << std::endl;
    }
    if (!(rpg_indicators[2])) {
        std::cout << "IN02 is off" << std::endl;
    }
    x = 0; // line 19
    if (rpg_indicators[50] && !(rpg_indicators[2])) {
        x = 100; // line 21
    }
    std::cout << rpg_to_char(x) << std::endl;
    rpg_indicators[1] = 0; // line 26
    if (!(rpg_indicators[1])) {
        std::cout << "IN01 now off" << std::endl;
    }
    return 0;
}
