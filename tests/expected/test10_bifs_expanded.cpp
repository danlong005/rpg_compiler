#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
int main() {
    bool rpg_indicators[100] = {};
    std::string text;
    int pos = 0;
    std::string result;
    std::string upper;
    double num = 0.0;
    int whole = 0;
    text = "Hello World"; // line 10
    pos = rpg_scan("World", text); // line 11
    std::cout << rpg_to_char(pos) << std::endl;
    pos = rpg_scan("xyz", text); // line 14
    std::cout << rpg_to_char(pos) << std::endl;
    result = rpg_scanrpl("World", "RPG", text); // line 18
    std::cout << result << std::endl;
    upper = rpg_xlate("abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", text); // line 22
    std::cout << upper << std::endl;
    num = 42.75; // line 26
    whole = static_cast<int>(num); // line 27
    std::cout << rpg_to_char(whole) << std::endl;
    num = static_cast<double>(whole); // line 30
    std::cout << rpg_to_char(num) << std::endl;
    result = text.substr(1 - 1, 5); // line 34
    std::cout << result << std::endl;
    return 0;
}
