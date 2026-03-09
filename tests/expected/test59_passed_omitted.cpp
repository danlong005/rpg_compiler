#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
std::string greet(std::string name, std::string title = std::string(), int _rpg_parms = 1);
std::string greet(std::string name, std::string title, int _rpg_parms) {
    std::string result;
    if (_rpg_parms >= 2) {
        result = ((title + " ") + name); // line 16
    } else {
        result = ("Hello " + name); // line 18
    }
    return result;
}
int main() {
    bool rpg_indicators[100] = {};
    std::cout << greet("World", std::string(), 1) << std::endl;
    std::cout << greet("Smith", "Dr.", 2) << std::endl;
    return 0;
}
