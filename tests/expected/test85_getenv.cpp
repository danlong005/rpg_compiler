#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    std::string HOMEPATH;
    std::string USERNAME;
    std::string MISSING;
    std::string DBURL;
    HOMEPATH = rpg_getenv("HOME"); // line 12
    std::cout << HOMEPATH << std::endl;
    USERNAME = rpg_getenv("USER"); // line 15
    std::cout << USERNAME << std::endl;
    MISSING = rpg_getenv("DOES_NOT_EXIST_XYZ"); // line 19
    if (MISSING == "") {
        std::cout << "Variable not set" << std::endl;
    }
    if (rpg_getenv("HOME") != "") {
        std::cout << "HOME is set" << std::endl;
    }
    DBURL = rpg_getenv("DATABASE_URL"); // line 30
    if (DBURL != "") {
        std::cout << DBURL << std::endl;
    } else {
        std::cout << "No DATABASE_URL configured" << std::endl;
    }
    return 0;
    return 0;
}
