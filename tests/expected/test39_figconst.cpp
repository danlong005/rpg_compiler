#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string str(10, ' ');
    int num = 0;
    double dec = 0.0;
    str = std::string(10, ' '); // line 7
    std::cout << str << std::endl;
    num = 0; // line 10
    std::cout << rpg_to_char(num) << std::endl;
    dec = 0.0; // line 13
    std::cout << rpg_to_char(dec) << std::endl;
    num = INT_MAX; // line 17
    std::cout << rpg_to_char(num) << std::endl;
    num = INT_MIN; // line 20
    std::cout << rpg_to_char(num) << std::endl;
    return 0;
}
