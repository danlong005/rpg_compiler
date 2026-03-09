#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int i = 0;
    int sum = 0;
    sum = 0; // line 6
    for (i = 1; i <= 5; i += 1) {
        sum = (sum + i); // line 8
    }
    std::cout << rpg_to_char(sum) << std::endl;
    sum = 0; // line 13
    for (i = 0; i <= 10; i += 2) {
        sum = (sum + i); // line 15
    }
    std::cout << rpg_to_char(sum) << std::endl;
    sum = 0; // line 20
    for (i = 5; i >= 1; i -= 1) {
        sum = (sum + i); // line 22
    }
    std::cout << rpg_to_char(sum) << std::endl;
    i = 1; // line 27
    sum = 0; // line 28
    while (i <= 5) {
        sum = (sum + i); // line 30
        i = (i + 1); // line 31
    }
    std::cout << rpg_to_char(sum) << std::endl;
    sum = 0; // line 36
    for (i = 1; i <= 10; i += 1) {
        if (i == 3) {
            continue;
        }
        if (i == 7) {
            break;
        }
        sum = (sum + i); // line 44
    }
    std::cout << rpg_to_char(sum) << std::endl;
    return 0;
}
