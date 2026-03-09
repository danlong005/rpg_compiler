#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int result = 0;
    std::string text;
    try {
        result = 42; // line 7
        std::cout << rpg_to_char(result) << std::endl;
    } catch (...) {
        std::cout << "Error occurred" << std::endl;
    }
    try {
        text = "Success"; // line 15
        std::cout << text << std::endl;
    } catch (...) {
        std::cout << "Nested error" << std::endl;
    }
    return 0;
}
