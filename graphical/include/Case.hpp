//
// Created by charles on 02/07/17.
//

#ifndef PSU_2016_ZAPPY_CASE_HPP
#define PSU_2016_ZAPPY_CASE_HPP

#include <vector>
#include "Player.hpp"
#include "Loot.hpp"

class Case {
public:
    Case();

    ~Case();

    std::vector <Player> players;
    std::vector <Loot> loots;

    void addPlayeratPos(int x, int y, orientation o);
};


#endif //PSU_2016_ZAPPY_CASE_HPP
