#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int COUNTER = 0;
    std::string GREETING;
    auto sr__INZSR = [&]() {
        GREETING = "Initialized!"; // line 13
        COUNTER = 42; // line 14
    };
    sr__INZSR();
    std::cout << GREETING << std::endl;
    std::cout << rpg_to_char(COUNTER) << std::endl;
    return 0;
}
