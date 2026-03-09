#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int STATUSCODE = 0;
    int ERRFLAG = 0;
    STATUSCODE = rpg_status(); // line 6
    std::cout << rpg_to_char(STATUSCODE) << std::endl;
    ERRFLAG = rpg_error(); // line 10
    std::cout << rpg_to_char(ERRFLAG) << std::endl;
    STATUSCODE = 42; // line 14
    STATUSCODE = rpg_status(); // line 15
    std::cout << rpg_to_char(STATUSCODE) << std::endl;
    return 0;
}
