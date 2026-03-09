#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int x = 0;
    std::string result;
    x = 75; // line 4
    if (x >= 90) {
        result = "A"; // line 6
    } else if (x >= 80) {
        result = "B"; // line 8
    } else if (x >= 70) {
        result = "C"; // line 10
    } else {
        result = "F"; // line 12
    }
    std::cout << result << std::endl;
    if ((x > 50) && (x < 100)) {
        std::cout << "In range" << std::endl;
    }
    if ((x < 10) || (x > 50)) {
        std::cout << "Outside 10-50" << std::endl;
    }
    if (!((x == 0))) {
        std::cout << "Not zero" << std::endl;
    }
    return 0;
}
