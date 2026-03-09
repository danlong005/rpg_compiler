#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int day = 0;
    std::string name;
    day = 3; // line 5
    if (day == 1) {
        name = "Monday"; // line 8
    } else if (day == 2) {
        name = "Tuesday"; // line 10
    } else if (day == 3) {
        name = "Wednesday"; // line 12
    } else {
        name = "Other"; // line 14
    }
    std::cout << name << std::endl;
    day = 99; // line 18
    if (day == 1) {
        name = "Monday"; // line 21
    } else {
        name = "Unknown"; // line 23
    }
    std::cout << name << std::endl;
    return 0;
}
