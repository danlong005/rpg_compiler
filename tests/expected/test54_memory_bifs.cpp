#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int myFunc(int x);
int myFunc(int x) {
    return (x * 2);
}
std::string getMyName() {
    return std::string("getMyName");
}
int main() {
    bool rpg_indicators[100] = {};
    std::string pName;
    std::string result;
    pName = std::string("main"); // line 11
    std::cout << pName << std::endl;
    result = getMyName(); // line 16
    std::cout << result << std::endl;
    return 0;
}
