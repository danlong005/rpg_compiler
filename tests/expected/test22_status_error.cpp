#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int statusCode = 0;
    int errFlag = 0;
    statusCode = rpg_status(); // line 6
    std::cout << rpg_to_char(statusCode) << std::endl;
    errFlag = rpg_error(); // line 10
    std::cout << rpg_to_char(errFlag) << std::endl;
    statusCode = 42; // line 14
    statusCode = rpg_status(); // line 15
    std::cout << rpg_to_char(statusCode) << std::endl;
    return 0;
}
