#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string str(10, ' ');
    std::string result;
    auto sr_mySR = [&]() {
        result = "entered"; // line 18
        return;
        result = "should not reach"; // line 20
    };
    str = std::string(10, ' '); // line 6
    str = rpg_evalr(str, "Hi");
    std::cout << str << std::endl;
    result = "before"; // line 11
    sr_mySR();
    std::cout << result << std::endl;
    return 0;
}
