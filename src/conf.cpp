#include "conf.h"
#include <cstdlib>
#include <fstream>
#include <string>

static std::string trim(const std::string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    size_t b = s.find_last_not_of(" \t\r\n");
    return (a == std::string::npos) ? "" : s.substr(a, b - a + 1);
}

static bool loadFromPath(const std::string& path, RpgConf& conf) {
    std::ifstream f(path);
    if (!f.is_open()) return false;
    std::string line;
    while (std::getline(f, line)) {
        if (line.empty() || line[0] == '#') continue;
        auto eq = line.find('=');
        if (eq == std::string::npos) continue;
        std::string key = trim(line.substr(0, eq));
        std::string val = trim(line.substr(eq + 1));
        if (key == "DB_DSN") conf.db_dsn = val;
    }
    conf.loaded = true;
    return true;
}

RpgConf RpgConf::load() {
    RpgConf conf;
    // RPGC_DSN env var takes highest priority (useful for CI / test runners)
    const char* env_dsn = std::getenv("RPGC_DSN");
    if (env_dsn && env_dsn[0]) {
        conf.db_dsn = env_dsn;
        conf.loaded = true;
        return conf;
    }
    if (loadFromPath("rpgc.conf", conf)) return conf;
    const char* home = std::getenv("HOME");
    if (home) {
        loadFromPath(std::string(home) + "/.rpgc.conf", conf);
    }
    return conf;
}
