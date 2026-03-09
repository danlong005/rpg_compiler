#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
std::string GREET(std::string NAME, std::string TITLE = std::string(), int _rpg_parms = 1);
std::string GREET(std::string NAME, std::string TITLE, int _rpg_parms) {
    std::string RESULT;
    if (_rpg_parms >= 2) {
        RESULT = ((TITLE + " ") + NAME); // line 16
    } else {
        RESULT = ("Hello " + NAME); // line 18
    }
    return RESULT;
}
int main() {
    bool rpg_indicators[100] = {};
    std::cout << GREET("World", std::string(), 1) << std::endl;
    std::cout << GREET("Smith", "Dr.", 2) << std::endl;
    return 0;
}
