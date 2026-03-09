#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    constexpr int MAX_SIZE = 100;
    const std::string GREETING = "Hello from constant";
    constexpr double TAX_RATE = 0.08;
    int ITEMS = 0;
    std::string MSG;
    double TOTAL = 0.0;
    ITEMS = MAX_SIZE; // line 10
    std::cout << rpg_to_char(ITEMS) << std::endl;
    MSG = GREETING; // line 13
    std::cout << MSG << std::endl;
    TOTAL = (500.0 * TAX_RATE); // line 16
    std::cout << rpg_to_char(TOTAL) << std::endl;
    ITEMS = (MAX_SIZE - 10); // line 20
    std::cout << rpg_to_char(ITEMS) << std::endl;
    return 0;
}
