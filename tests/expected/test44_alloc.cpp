#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    void* ptr = nullptr;
    void* numPtr = nullptr;
    ptr = std::malloc(100); // line 6
    if (ptr != nullptr) {
        std::cout << "Allocated" << std::endl;
    }
    std::free(ptr);
    ptr = nullptr;
    std::cout << "Deallocated" << std::endl;
    numPtr = std::malloc(10); // line 16
    numPtr = std::realloc(numPtr, 200); // line 17
    if (numPtr != nullptr) {
        std::cout << "Reallocated" << std::endl;
    }
    std::free(numPtr);
    numPtr = nullptr;
    return 0;
}
