#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
extern int SHAREDVAL;
int ADD(int A, int B);
int main() {
    bool rpg_indicators[100] = {};
    std::cout << rpg_to_char(ADD(10, 20)) << std::endl;
    std::cout << rpg_to_char(SHAREDVAL) << std::endl;
    return 0;
}
