//
// Created by charles on 02/07/17.
//

#ifndef PSU_2016_ZAPPY_MAP_HPP
#define PSU_2016_ZAPPY_MAP_HPP

#include "Case.hpp"
#include  <vector>

class Map {
public:
    Map(int, int);

    ~Map();

    int sizeX;
    int sizeY;

    std::vector <std::vector<Case>> cases;

    void addCaseAtPosition(int x, int y);

    void resizeMapCases(int, int);

    void addLootatPos(int x, int y, type lootType);
};

#endif //PSU_2016_ZAPPY_MAP_HPP
