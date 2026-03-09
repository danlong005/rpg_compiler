#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
std::string GREET(std::string NAME, std::string TITLE = std::string(), int _rpg_parms = 1);
std::string GREET(std::string NAME, std::string TITLE, int _rpg_parms) {
    if (_rpg_parms >= 2) {
        return ((TITLE + " ") + NAME);
    } else {
        return ("Hello " + NAME);
    }
}
int main() {
    bool rpg_indicators[100] = {};
    std::cout << GREET("Alice", std::string(), 1) << std::endl;
    std::cout << GREET("Bob", "Mr.", 2) << std::endl;
    return 0;
}
