#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int X = 0;
    std::string RESULT;
    X = 75; // line 4
    if (X >= 90) {
        RESULT = "A"; // line 6
    } else if (X >= 80) {
        RESULT = "B"; // line 8
    } else if (X >= 70) {
        RESULT = "C"; // line 10
    } else {
        RESULT = "F"; // line 12
    }
    std::cout << RESULT << std::endl;
    if ((X > 50) && (X < 100)) {
        std::cout << "In range" << std::endl;
    }
    if ((X < 10) || (X > 50)) {
        std::cout << "Outside 10-50" << std::endl;
    }
    if (!((X == 0))) {
        std::cout << "Not zero" << std::endl;
    }
    return 0;
}
