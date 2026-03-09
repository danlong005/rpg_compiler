#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int RESULT = 0;
    std::string TEXT;
    try {
        RESULT = 42; // line 7
        std::cout << rpg_to_char(RESULT) << std::endl;
    } catch (...) {
        std::cout << "Error occurred" << std::endl;
    }
    try {
        TEXT = "Success"; // line 15
        std::cout << TEXT << std::endl;
    } catch (...) {
        std::cout << "Nested error" << std::endl;
    }
    return 0;
}
