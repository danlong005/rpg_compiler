#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int x = 0;
    int y = 0;
    int result = 0;
    double decVal = 0.0;
    x = (0 - 42); // line 8
    result = std::abs(x); // line 9
    std::cout << rpg_to_char(result) << std::endl;
    x = 17; // line 13
    result = std::abs(x); // line 14
    std::cout << rpg_to_char(result) << std::endl;
    x = 17; // line 18
    y = 5; // line 19
    result = (x / y); // line 20
    std::cout << rpg_to_char(result) << std::endl;
    result = (x % y); // line 24
    std::cout << rpg_to_char(result) << std::endl;
    decVal = (0 - 3.14); // line 28
    decVal = std::abs(decVal); // line 29
    std::cout << rpg_to_char(decVal) << std::endl;
    result = (100 / 7); // line 33
    std::cout << rpg_to_char(result) << std::endl;
    result = (100 % 7); // line 35
    std::cout << rpg_to_char(result) << std::endl;
    return 0;
}
