#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    double price = 0.0;
    int qty = 0;
    double total = 0.0;
    std::string name;
    const int MAX_SIZE = 100;
    const auto _init_MAX_SIZE = MAX_SIZE;
    std::string greeting = "Hi there";
    const auto _init_greeting = greeting;
    int counter = 5;
    const auto _init_counter = counter;
    price = 19.99; // line 9
    qty = 3; // line 10
    total = (price * qty); // line 11
    name = "RPG Program"; // line 12
    std::cout << name << std::endl;
    std::cout << rpg_to_char(total) << std::endl;
    std::cout << greeting << std::endl;
    std::cout << rpg_to_char(MAX_SIZE) << std::endl;
    std::cout << rpg_to_char(counter) << std::endl;
    return 0;
}
