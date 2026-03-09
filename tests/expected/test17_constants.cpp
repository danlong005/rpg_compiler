#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    constexpr int MAX_SIZE = 100;
    const std::string GREETING = "Hello from constant";
    constexpr double TAX_RATE = 0.08;
    int items = 0;
    std::string msg;
    double total = 0.0;
    items = MAX_SIZE; // line 10
    std::cout << rpg_to_char(items) << std::endl;
    msg = GREETING; // line 13
    std::cout << msg << std::endl;
    total = (500.0 * TAX_RATE); // line 16
    std::cout << rpg_to_char(total) << std::endl;
    items = (MAX_SIZE - 10); // line 20
    std::cout << rpg_to_char(items) << std::endl;
    return 0;
}
