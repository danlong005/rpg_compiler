#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
std::string greet(std::string name, std::string title = std::string(), int _rpg_parms = 1);
std::string greet(std::string name, std::string title, int _rpg_parms) {
    if (_rpg_parms >= 2) {
        return ((title + " ") + name);
    } else {
        return ("Hello " + name);
    }
}
int main() {
    bool rpg_indicators[100] = {};
    std::cout << greet("Alice", std::string(), 1) << std::endl;
    std::cout << greet("Bob", "Mr.", 2) << std::endl;
    return 0;
}
