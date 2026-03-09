#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
void myMain() {
    std::string msg;
    msg = "Hello from MAIN proc"; // line 9
    std::cout << msg << std::endl;
    std::cout << "Done" << std::endl;
}
int main() {
    myMain();
    return 0;
}
