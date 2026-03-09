#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int DAY = 0;
    std::string NAME;
    DAY = 3; // line 5
    if (DAY == 1) {
        NAME = "Monday"; // line 8
    } else if (DAY == 2) {
        NAME = "Tuesday"; // line 10
    } else if (DAY == 3) {
        NAME = "Wednesday"; // line 12
    } else {
        NAME = "Other"; // line 14
    }
    std::cout << NAME << std::endl;
    DAY = 99; // line 18
    if (DAY == 1) {
        NAME = "Monday"; // line 21
    } else {
        NAME = "Unknown"; // line 23
    }
    std::cout << NAME << std::endl;
    return 0;
}
