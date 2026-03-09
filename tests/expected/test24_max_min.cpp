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
    int c = 0;
    int result = 0;
    std::string s1;
    std::string s2;
    std::string sResult;
    a = 10; // line 11
    b = 25; // line 12
    result = std::max(a, b); // line 13
    std::cout << rpg_to_char(result) << std::endl;
    result = std::min(a, b); // line 17
    std::cout << rpg_to_char(result) << std::endl;
    c = 15; // line 21
    result = std::max({a, b, c}); // line 22
    std::cout << rpg_to_char(result) << std::endl;
    result = std::min({a, b, c}); // line 26
    std::cout << rpg_to_char(result) << std::endl;
    result = std::max({3, 7, 1, 9, 4}); // line 30
    std::cout << rpg_to_char(result) << std::endl;
    result = std::min({3, 7, 1, 9, 4}); // line 32
    std::cout << rpg_to_char(result) << std::endl;
    s1 = "Apple"; // line 36
    s2 = "Banana"; // line 37
    sResult = std::max(s1, s2); // line 38
    std::cout << sResult << std::endl;
    sResult = std::min(s1, s2); // line 40
    std::cout << sResult << std::endl;
    return 0;
}
