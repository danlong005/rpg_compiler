#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int GETCOUNT();
int GETCOUNT() {
    static int COUNTER = 0;
    COUNTER = (COUNTER + 1); // line 9
    return COUNTER;
}
int main() {
    bool rpg_indicators[100] = {};
    std::cout << rpg_to_char(GETCOUNT()) << std::endl;
    std::cout << rpg_to_char(GETCOUNT()) << std::endl;
    std::cout << rpg_to_char(GETCOUNT()) << std::endl;
    return 0;
}
