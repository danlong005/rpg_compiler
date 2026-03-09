#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int a = 0;
    int b = 0;
    int result = 0;
    a = 10; // line 5
    b = 3; // line 6
    result = (a + b); // line 7
    std::cout << rpg_to_char(result) << std::endl;
    result = (a - b); // line 9
    std::cout << rpg_to_char(result) << std::endl;
    result = (a * b); // line 11
    std::cout << rpg_to_char(result) << std::endl;
    result = (a / b); // line 13
    std::cout << rpg_to_char(result) << std::endl;
    result = ((a + b) * 2); // line 15
    std::cout << rpg_to_char(result) << std::endl;
    return 0;
}
