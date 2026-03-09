#include "rpg_runtime.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
void doWork();
void doWork() {
    auto _on_exit_fn = rpg_make_scope_guard([&]() {
        std::cout << "Cleanup" << std::endl;
    });
    std::cout << "Working" << std::endl;
}
int main() {
    bool rpg_indicators[100] = {};
    doWork();
    std::cout << "Done" << std::endl;
    return 0;
}
