//
// Created by charles on 02/07/17.
//

#ifndef PSU_2016_ZAPPY_LOOT_HPP
#define PSU_2016_ZAPPY_LOOT_HPP

enum type {
    APPLE,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

class Loot {
public:
    Loot(type);

    ~Loot();

    type lootType;
};

#endif //PSU_2016_ZAPPY_LOOT_HPP
