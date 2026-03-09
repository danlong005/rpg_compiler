#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string STR(10, ' ');
    int NUM = 0;
    double DEC = 0.0;
    STR = std::string(10, ' '); // line 7
    std::cout << STR << std::endl;
    NUM = 0; // line 10
    std::cout << rpg_to_char(NUM) << std::endl;
    DEC = 0.0; // line 13
    std::cout << rpg_to_char(DEC) << std::endl;
    NUM = INT_MAX; // line 17
    std::cout << rpg_to_char(NUM) << std::endl;
    NUM = INT_MIN; // line 20
    std::cout << rpg_to_char(NUM) << std::endl;
    return 0;
}
