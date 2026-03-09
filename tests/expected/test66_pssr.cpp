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
    std::string ERRMSG;
    auto sr__PSSR = [&]() {
        ERRMSG = "Error caught by *PSSR"; // line 6
        std::cout << ERRMSG << std::endl;
    };
    try {
        RESULT = 10; // line 10
        std::cout << rpg_to_char(RESULT) << std::endl;
        return 0;
    } catch (...) {
        sr__PSSR();
    }
}
