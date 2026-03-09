#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int myInt = 0;
    std::string myStr;
    void* ptr1 = nullptr;
    void* ptr2 = nullptr;
    int ptrSize = 0;
    myInt = 42; // line 8
    ptr1 = static_cast<void*>(&myInt); // line 9
    if (ptr1 != nullptr) {
        std::cout << "ptr1 not null" << std::endl;
    }
    ptr2 = nullptr; // line 16
    if (ptr2 == nullptr) {
        std::cout << "ptr2 is null" << std::endl;
    }
    ptr2 = ptr1; // line 22
    if (ptr2 != nullptr) {
        std::cout << "ptr2 copied" << std::endl;
    }
    myStr = "Hello Pointer"; // line 28
    ptr1 = static_cast<void*>(&myStr); // line 29
    if (ptr1 != nullptr) {
        std::cout << "String pointer ok" << std::endl;
    }
    ptrSize = static_cast<int>(sizeof(ptr1)); // line 36
    std::cout << rpg_to_char(ptrSize) << std::endl;
    return 0;
}
