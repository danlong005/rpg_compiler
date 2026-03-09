#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    double PRICE = 0.0;
    int QTY = 0;
    double TOTAL = 0.0;
    std::string NAME;
    const int MAX_SIZE = 100;
    const auto _init_MAX_SIZE = MAX_SIZE;
    std::string GREETING = "Hi there";
    const auto _init_GREETING = GREETING;
    int COUNTER = 5;
    const auto _init_COUNTER = COUNTER;
    PRICE = 19.99; // line 9
    QTY = 3; // line 10
    TOTAL = (PRICE * QTY); // line 11
    NAME = "RPG Program"; // line 12
    std::cout << NAME << std::endl;
    std::cout << rpg_to_char(TOTAL) << std::endl;
    std::cout << GREETING << std::endl;
    std::cout << rpg_to_char(MAX_SIZE) << std::endl;
    std::cout << rpg_to_char(COUNTER) << std::endl;
    return 0;
}
