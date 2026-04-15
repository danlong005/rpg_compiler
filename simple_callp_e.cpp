#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
void NOEXIST();
// EXTPGM: BADPROC → NOEXIST
int main() {
    bool rpg_indicators[100] = {};
    rpg_error_flag() = false; rpg_status_code() = 0;
    try {
        NOEXIST();
    } catch (...) { rpg_error_flag() = true; rpg_status_code() = 202; }
    return 0;
}
