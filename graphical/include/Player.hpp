//
// Created by charles on 02/07/17.
//

#ifndef PSU_2016_ZAPPY_PLAYER_HPP
#define PSU_2016_ZAPPY_PLAYER_HPP

enum orientation {
    NONE,
    UP,
    RIGHT,
    DOWN,
    LEFT
};

class Player {
public:
    Player(int, int);

    ~Player();

    int x;
    int y;
    int nb;
    orientation playerOrientation;
};

#endif //PSU_2016_ZAPPY_PLAYER_HPP
