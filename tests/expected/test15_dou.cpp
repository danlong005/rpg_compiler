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
    i = 1; // line 6
    sum = 0; // line 7
    do {
        sum = (sum + i); // line 9
        i = (i + 1); // line 10
    } while (!(i > 5));
    std::cout << rpg_to_char(sum) << std::endl;
    i = 10; // line 15
    sum = 0; // line 16
    do {
        sum = (sum + i); // line 18
        i = (i + 1); // line 19
        if (i > 12) {
            break;
        }
    } while (!(i > 5));
    std::cout << rpg_to_char(sum) << std::endl;
    return 0;
}
