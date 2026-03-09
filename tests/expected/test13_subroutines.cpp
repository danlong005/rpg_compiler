#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int TOTAL = 0;
    int X = 0;
    auto sr_ADDTEN = [&]() {
        TOTAL = (TOTAL + 10); // line 9
    };
    auto sr_SHOWTOTAL = [&]() {
        std::cout << rpg_to_char(TOTAL) << std::endl;
    };
    auto sr_DOUBLEIFSMALL = [&]() {
        if (X < 10) {
            X = (X * 2); // line 26
        }
    };
    TOTAL = 0; // line 5
    sr_ADDTEN();
    sr_ADDTEN();
    sr_ADDTEN();
    sr_SHOWTOTAL();
    X = 5; // line 23
    sr_DOUBLEIFSMALL();
    std::cout << rpg_to_char(X) << std::endl;
    return 0;
}
