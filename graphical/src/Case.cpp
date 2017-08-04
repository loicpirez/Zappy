//
// Created by charles on 02/07/17.
//

#include <iostream>
#include "../include/Case.hpp"
#include "../include/Player.hpp"

Case::Case() {

}

Case::~Case() {

}

void Case::addPlayeratPos(int x, int y, orientation o) {
    Player p(x, y);
    p.playerOrientation = o;
    this->players.push_back(p);
}

//ctrl+c