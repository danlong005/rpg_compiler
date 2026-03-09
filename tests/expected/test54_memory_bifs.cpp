#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int MYFUNC(int X);
int MYFUNC(int X) {
    return (X * 2);
}
std::string GETMYNAME() {
    return std::string("GETMYNAME");
}
int main() {
    bool rpg_indicators[100] = {};
    std::string PNAME;
    std::string RESULT;
    PNAME = std::string("main"); // line 11
    std::cout << PNAME << std::endl;
    RESULT = GETMYNAME(); // line 16
    std::cout << RESULT << std::endl;
    return 0;
}
