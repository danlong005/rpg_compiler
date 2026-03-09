#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    bool ISACTIVE = false;
    int STATUS = 0;
    struct COLORS_t {
        const int RED = 1;
        const int GREEN = 2;
        const int BLUE = 3;
    };
    COLORS_t COLORS;
    ISACTIVE = 1; // line 12
    if (ISACTIVE) {
        std::cout << "Active" << std::endl;
    }
    ISACTIVE = 0; // line 17
    if (!(ISACTIVE)) {
        std::cout << "Inactive" << std::endl;
    }
    STATUS = 2; // line 23
    if (STATUS == COLORS.GREEN) {
        std::cout << "Green" << std::endl;
    }
    return 0;
}
