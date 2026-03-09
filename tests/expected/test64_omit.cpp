#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
std::string FORMATNAME(std::string FIRST, std::string* MIDDLE, std::string LAST);
std::string FORMATNAME(std::string FIRST, std::string* MIDDLE, std::string LAST) {
    std::string RESULT;
    if (MIDDLE == nullptr) {
        RESULT = ((FIRST + " ") + LAST); // line 18
    } else {
        RESULT = ((((FIRST + " ") + (*MIDDLE)) + " ") + LAST); // line 20
    }
    return RESULT;
}
int main() {
    bool rpg_indicators[100] = {};
    std::cout << FORMATNAME("John", nullptr, "Smith") << std::endl;
    return 0;
}
