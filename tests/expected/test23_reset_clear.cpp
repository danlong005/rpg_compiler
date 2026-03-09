#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int MYINT = 42;
    const auto _init_MYINT = MYINT;
    std::string MYSTR = "Hello";
    const auto _init_MYSTR = MYSTR;
    double MYDEC = 3.14;
    const auto _init_MYDEC = MYDEC;
    std::string MYCHAR = "RPG";
    const auto _init_MYCHAR = MYCHAR;
    std::cout << rpg_to_char(MYINT) << std::endl;
    std::cout << MYSTR << std::endl;
    MYINT = 100; // line 12
    MYSTR = "Changed"; // line 13
    MYDEC = 99.99; // line 14
    MYCHAR = "Modified"; // line 15
    std::cout << rpg_to_char(MYINT) << std::endl;
    std::cout << MYSTR << std::endl;
    MYINT = _init_MYINT;
    MYSTR = _init_MYSTR;
    std::cout << rpg_to_char(MYINT) << std::endl;
    std::cout << MYSTR << std::endl;
    MYINT = 0;
    MYSTR = "";
    MYDEC = 0.0;
    MYCHAR = "";
    std::cout << rpg_to_char(MYINT) << std::endl;
    std::cout << MYSTR << std::endl;
    std::cout << rpg_to_char(MYDEC) << std::endl;
    std::cout << MYCHAR << std::endl;
    return 0;
}
