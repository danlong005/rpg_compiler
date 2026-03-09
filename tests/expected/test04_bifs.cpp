#include "rpg_runtime.h"
#include <iostream>
#include <string>
int main() {
    std::string padded(20, ' ');
    std::string trimmed;
    int length = 0;
    std::string part;
    padded = "  Hello  ";
    trimmed = rpg_trim(padded);
    std::cout << trimmed << std::endl;
    trimmed = rpg_triml(padded);
    std::cout << trimmed << std::endl;
    trimmed = rpg_trimr(padded);
    std::cout << trimmed << std::endl;
    length = static_cast<int>(padded.size());
    std::cout << std::to_string(length) << std::endl;
    part = padded.substr(3 - 1, 5);
    std::cout << part << std::endl;
    return 0;
}
