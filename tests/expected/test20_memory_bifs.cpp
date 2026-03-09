#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int myInt = 0;
    std::string myChar(20, ' ');
    double myPacked = 0.0;
    int sizeResult = 0;
    void* ptr = nullptr;
    sizeResult = static_cast<int>(sizeof(myInt)); // line 9
    std::cout << rpg_to_char(sizeResult) << std::endl;
    sizeResult = static_cast<int>(sizeof(myChar)); // line 12
    std::cout << rpg_to_char(sizeResult) << std::endl;
    sizeResult = static_cast<int>(sizeof(myPacked)); // line 15
    std::cout << rpg_to_char(sizeResult) << std::endl;
    myInt = 42; // line 19
    ptr = static_cast<void*>(&myInt); // line 20
    std::cout << "Got pointer" << std::endl;
    if (ptr != nullptr) {
        std::cout << "Pointer not null" << std::endl;
    }
    return 0;
}
