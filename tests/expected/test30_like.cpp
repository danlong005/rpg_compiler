#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
int main() {
    bool rpg_indicators[100] = {};
    int BASEINT = 0;
    std::string BASESTR;
    double BASEDEC = 0.0;
    int COPYINT = 0;
    std::string COPYSTR;
    double COPYDEC = 0.0;
    BASEINT = 42; // line 11
    COPYINT = BASEINT; // line 12
    std::cout << rpg_to_char(COPYINT) << std::endl;
    BASESTR = "Hello LIKE"; // line 15
    COPYSTR = BASESTR; // line 16
    std::cout << COPYSTR << std::endl;
    BASEDEC = 3.14; // line 19
    COPYDEC = BASEDEC; // line 20
    std::cout << rpg_to_char(COPYDEC) << std::endl;
    return 0;
}
