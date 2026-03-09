#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int X = 0;
    int Y = 0;
    int RESULT = 0;
    double DECVAL = 0.0;
    X = (0 - 42); // line 8
    RESULT = std::abs(X); // line 9
    std::cout << rpg_to_char(RESULT) << std::endl;
    X = 17; // line 13
    RESULT = std::abs(X); // line 14
    std::cout << rpg_to_char(RESULT) << std::endl;
    X = 17; // line 18
    Y = 5; // line 19
    RESULT = (X / Y); // line 20
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = (X % Y); // line 24
    std::cout << rpg_to_char(RESULT) << std::endl;
    DECVAL = (0 - 3.14); // line 28
    DECVAL = std::abs(DECVAL); // line 29
    std::cout << rpg_to_char(DECVAL) << std::endl;
    RESULT = (100 / 7); // line 33
    std::cout << rpg_to_char(RESULT) << std::endl;
    RESULT = (100 % 7); // line 35
    std::cout << rpg_to_char(RESULT) << std::endl;
    return 0;
}
