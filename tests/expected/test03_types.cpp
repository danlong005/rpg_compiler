#include "rpg_runtime.h"
#include <iostream>
#include <string>
int main() {
    double price = 0.0;
    int qty = 0;
    double total = 0.0;
    std::string name;
    const int MAX_SIZE = 100;
    std::string greeting = "Hi there";
    int counter = 5;
    price = 19.99;
    qty = 3;
    total = (price * qty);
    name = "RPG Program";
    std::cout << name << std::endl;
    std::cout << std::to_string(total) << std::endl;
    std::cout << greeting << std::endl;
    std::cout << std::to_string(MAX_SIZE) << std::endl;
    std::cout << std::to_string(counter) << std::endl;
    return 0;
}
