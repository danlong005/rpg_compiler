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
    std::string MYSTR;
    void* PTR1 = nullptr;
    void* PTR2 = nullptr;
    int PTRSIZE = 0;
    MYINT = 42; // line 8
    PTR1 = static_cast<void*>(&MYINT); // line 9
    if (PTR1 != nullptr) {
        std::cout << "ptr1 not null" << std::endl;
    }
    PTR2 = nullptr; // line 16
    if (PTR2 == nullptr) {
        std::cout << "ptr2 is null" << std::endl;
    }
    PTR2 = PTR1; // line 22
    if (PTR2 != nullptr) {
        std::cout << "ptr2 copied" << std::endl;
    }
    MYSTR = "Hello Pointer"; // line 28
    PTR1 = static_cast<void*>(&MYSTR); // line 29
    if (PTR1 != nullptr) {
        std::cout << "String pointer ok" << std::endl;
    }
    PTRSIZE = static_cast<int>(sizeof(PTR1)); // line 36
    std::cout << rpg_to_char(PTRSIZE) << std::endl;
    return 0;
}
