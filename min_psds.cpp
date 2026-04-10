#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
struct PGMINFO_t {
};
int main(int argc, char* argv[]) {
    (void)argc;
    rpg_psds_init(argv[0]);
    bool rpg_indicators[100] = {};
    PGMINFO_t PGMINFO;
    std::cout << "test" << std::endl;
}
