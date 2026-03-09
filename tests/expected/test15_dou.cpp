#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int I = 0;
    int SUM = 0;
    I = 1; // line 6
    SUM = 0; // line 7
    do {
        SUM = (SUM + I); // line 9
        I = (I + 1); // line 10
    } while (!(I > 5));
    std::cout << rpg_to_char(SUM) << std::endl;
    I = 10; // line 15
    SUM = 0; // line 16
    do {
        SUM = (SUM + I); // line 18
        I = (I + 1); // line 19
        if (I > 12) {
            break;
        }
    } while (!(I > 5));
    std::cout << rpg_to_char(SUM) << std::endl;
    return 0;
}
