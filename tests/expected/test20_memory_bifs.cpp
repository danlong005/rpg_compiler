#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int MYINT = 0;
    std::string MYCHAR(20, ' ');
    double MYPACKED = 0.0;
    int SIZERESULT = 0;
    void* PTR = nullptr;
    SIZERESULT = static_cast<int>(sizeof(MYINT)); // line 9
    std::cout << rpg_to_char(SIZERESULT) << std::endl;
    SIZERESULT = static_cast<int>(sizeof(MYCHAR)); // line 12
    std::cout << rpg_to_char(SIZERESULT) << std::endl;
    SIZERESULT = static_cast<int>(sizeof(MYPACKED)); // line 15
    std::cout << rpg_to_char(SIZERESULT) << std::endl;
    MYINT = 42; // line 19
    PTR = static_cast<void*>(&MYINT); // line 20
    std::cout << "Got pointer" << std::endl;
    if (PTR != nullptr) {
        std::cout << "Pointer not null" << std::endl;
    }
    return 0;
}
