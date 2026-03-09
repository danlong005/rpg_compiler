#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int getCount();
int getCount() {
    static int counter = 0;
    counter = (counter + 1); // line 9
    return counter;
}
int main() {
    bool rpg_indicators[100] = {};
    std::cout << rpg_to_char(getCount()) << std::endl;
    std::cout << rpg_to_char(getCount()) << std::endl;
    std::cout << rpg_to_char(getCount()) << std::endl;
    return 0;
}
