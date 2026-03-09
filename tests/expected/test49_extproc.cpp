#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
extern int sharedVal;
int add(int a, int b);
int main() {
    bool rpg_indicators[100] = {};
    std::cout << rpg_to_char(add(10, 20)) << std::endl;
    std::cout << rpg_to_char(sharedVal) << std::endl;
    return 0;
}
