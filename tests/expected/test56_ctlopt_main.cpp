#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
void MYMAIN() {
    std::string MSG;
    MSG = "Hello from MAIN proc"; // line 9
    std::cout << MSG << std::endl;
    std::cout << "Done" << std::endl;
}
int main() {
    MYMAIN();
    return 0;
}
