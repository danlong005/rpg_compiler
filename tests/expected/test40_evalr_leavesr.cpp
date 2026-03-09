#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string STR(10, ' ');
    std::string RESULT;
    auto sr_MYSR = [&]() {
        RESULT = "entered"; // line 18
        return;
        RESULT = "should not reach"; // line 20
    };
    STR = std::string(10, ' '); // line 6
    STR = rpg_evalr(STR, "Hi");
    std::cout << STR << std::endl;
    RESULT = "before"; // line 11
    sr_MYSR();
    std::cout << RESULT << std::endl;
    return 0;
}
