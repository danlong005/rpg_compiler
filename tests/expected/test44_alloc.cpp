#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    void* PTR = nullptr;
    void* NUMPTR = nullptr;
    PTR = std::malloc(100); // line 6
    if (PTR != nullptr) {
        std::cout << "Allocated" << std::endl;
    }
    std::free(PTR);
    PTR = nullptr;
    std::cout << "Deallocated" << std::endl;
    NUMPTR = std::malloc(10); // line 16
    NUMPTR = std::realloc(NUMPTR, 200); // line 17
    if (NUMPTR != nullptr) {
        std::cout << "Reallocated" << std::endl;
    }
    std::free(NUMPTR);
    NUMPTR = nullptr;
    return 0;
}
