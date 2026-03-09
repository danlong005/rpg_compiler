#include "rpg_runtime.h"
#include <iostream>
#include <string>
int main() {
    std::string greeting(20, ' ');
    int count = 0;
    greeting = "Hello, world!";
    count = 42;
    std::cout << greeting << std::endl;
    std::cout << std::to_string(count) << std::endl;
    return 0;
}
