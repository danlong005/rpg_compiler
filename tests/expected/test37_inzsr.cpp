#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int counter = 0;
    std::string greeting;
    auto sr__INZSR = [&]() {
        greeting = "Initialized!"; // line 13
        counter = 42; // line 14
    };
    sr__INZSR();
    std::cout << greeting << std::endl;
    std::cout << rpg_to_char(counter) << std::endl;
    return 0;
}
