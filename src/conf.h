#ifndef CONF_H
#define CONF_H

#include <string>

struct RpgConf {
    std::string db_dsn;
    bool loaded = false;

    // Search ./rpgc.conf then ~/.rpgc.conf; returns default-constructed conf if neither found
    static RpgConf load();
};

#endif // CONF_H
