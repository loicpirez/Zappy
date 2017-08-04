//
// Created by charles on 02/07/17.
//

#include "../include/Map.hpp"

Map::Map(int mapX, int mapY) {
    this->sizeX = mapX;
    this->sizeY = mapY;
}

Map::~Map() {

}

void Map::addCaseAtPosition(int x, int y) {
    cases[x][y] = Case();
}

void Map::resizeMapCases(int sizeX, int sizeY) {
    int i = 0;
    cases.resize(sizeY);
    while (i < sizeY) {
        cases[i].resize(sizeY);
        i++;
    }
}

void Map::addLootatPos(int x, int y, type lootType) {
    this->cases[x][y].loots.push_back(lootType);
}

