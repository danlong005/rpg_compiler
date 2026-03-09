#include "rpg_runtime.h"
#include <iostream>
#include <string>
int main() {
    int a = 0;
    int b = 0;
    int result = 0;
    a = 10;
    b = 3;
    result = (a + b);
    std::cout << std::to_string(result) << std::endl;
    result = (a - b);
    std::cout << std::to_string(result) << std::endl;
    result = (a * b);
    std::cout << std::to_string(result) << std::endl;
    result = (a / b);
    std::cout << std::to_string(result) << std::endl;
    result = ((a + b) * 2);
    std::cout << std::to_string(result) << std::endl;
    return 0;
}
