#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    int myInt = 42;
    const auto _init_myInt = myInt;
    std::string myStr = "Hello";
    const auto _init_myStr = myStr;
    double myDec = 3.14;
    const auto _init_myDec = myDec;
    std::string myChar = "RPG";
    const auto _init_myChar = myChar;
    std::cout << rpg_to_char(myInt) << std::endl;
    std::cout << myStr << std::endl;
    myInt = 100; // line 12
    myStr = "Changed"; // line 13
    myDec = 99.99; // line 14
    myChar = "Modified"; // line 15
    std::cout << rpg_to_char(myInt) << std::endl;
    std::cout << myStr << std::endl;
    myInt = _init_myInt;
    myStr = _init_myStr;
    std::cout << rpg_to_char(myInt) << std::endl;
    std::cout << myStr << std::endl;
    myInt = 0;
    myStr = "";
    myDec = 0.0;
    myChar = "";
    std::cout << rpg_to_char(myInt) << std::endl;
    std::cout << myStr << std::endl;
    std::cout << rpg_to_char(myDec) << std::endl;
    std::cout << myChar << std::endl;
    return 0;
}
