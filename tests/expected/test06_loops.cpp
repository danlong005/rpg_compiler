#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int I = 0;
    int SUM = 0;
    SUM = 0; // line 6
    for (I = 1; I <= 5; I += 1) {
        SUM = (SUM + I); // line 8
    }
    std::cout << rpg_to_char(SUM) << std::endl;
    SUM = 0; // line 13
    for (I = 0; I <= 10; I += 2) {
        SUM = (SUM + I); // line 15
    }
    std::cout << rpg_to_char(SUM) << std::endl;
    SUM = 0; // line 20
    for (I = 5; I >= 1; I -= 1) {
        SUM = (SUM + I); // line 22
    }
    std::cout << rpg_to_char(SUM) << std::endl;
    I = 1; // line 27
    SUM = 0; // line 28
    while (I <= 5) {
        SUM = (SUM + I); // line 30
        I = (I + 1); // line 31
    }
    std::cout << rpg_to_char(SUM) << std::endl;
    SUM = 0; // line 36
    for (I = 1; I <= 10; I += 1) {
        if (I == 3) {
            continue;
        }
        if (I == 7) {
            break;
        }
        SUM = (SUM + I); // line 44
    }
    std::cout << rpg_to_char(SUM) << std::endl;
    return 0;
}
