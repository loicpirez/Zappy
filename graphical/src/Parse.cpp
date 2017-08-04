//
// main.cpp for main in /home/loic/Développement/PSU_2016_zappy/graphical
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Wed Jun 28 18:34:35 2017 Loïc Pirez
// Last update Thu Jun 29 13:30:48 2017 Loïc Pirez
//

#include "../include/Create.hpp"
#include "../include/Window.hpp"
#include "../include/Draw.hpp"
#include "../include/Parse.hpp"
#include <mutex>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <typeinfo>

void none(std::vector <std::string> vec) {
//    std::cout << "unknown" << std::endl;
}

void msz(std::vector <std::string> vec, Window **win) {
    if (vec.size() == 3) {
        (*win)->map.sizeX = std::atoi(vec[1].c_str());
        (*win)->map.sizeY = std::atoi(vec[2].c_str());
    }
}

void bienvenue(std::vector <std::string> vec, Window **win) {
    std::cout << "GRAPHIC" << std::endl;
}

void bct(std::vector <std::string> vec, Window **win) {
    if (vec.size() == 10) {
        (*win)->map.addCaseAtPosition(std::atoi(vec[1].c_str()), std::atoi(vec[2].c_str()));
        if (std::atoi(vec[3].c_str()) > 0)
            (*win)->map.addLootatPos(std::atoi(vec[1].c_str()), std::atoi(vec[2].c_str()), APPLE);
        if (std::atoi(vec[4].c_str()) > 0)
            (*win)->map.addLootatPos(std::atoi(vec[1].c_str()), std::atoi(vec[2].c_str()), LINEMATE);
        if (std::atoi(vec[5].c_str()) > 0)
            (*win)->map.addLootatPos(std::atoi(vec[1].c_str()), std::atoi(vec[2].c_str()), DERAUMERE);
        if (std::atoi(vec[6].c_str()) > 0)
            (*win)->map.addLootatPos(std::atoi(vec[1].c_str()), std::atoi(vec[2].c_str()), SIBUR);
        if (std::atoi(vec[7].c_str()) > 0)
            (*win)->map.addLootatPos(std::atoi(vec[1].c_str()), std::atoi(vec[2].c_str()), MENDIANE);
        if (std::atoi(vec[8].c_str()) > 0)
            (*win)->map.addLootatPos(std::atoi(vec[1].c_str()), std::atoi(vec[2].c_str()), PHIRAS);
        if (std::atoi(vec[9].c_str()) > 0)
            (*win)->map.addLootatPos(std::atoi(vec[1].c_str()), std::atoi(vec[2].c_str()), THYSTAME);
    }
}

void pnw(std::vector <std::string> vec, Window **win) {
    int x;
    int y;
    orientation o;

    if (vec.size() == 7) {
        x = std::atoi(vec[2].c_str());
        y = std::atoi(vec[3].c_str());
        o = (orientation)std::atoi(vec[4].c_str());
        (*win)->map.cases[x][y].addPlayeratPos(x, y, o);
    }
}

void ppo(std::vector <std::string> vec, Window **win) {
    if (vec.size() == 2) {
        /* position du joureur : nb x y o */
    }
}

void pgt(std::vector <std::string> vec, Window **win) {
    if (vec.size() == 2) {
        /* joueur prend resource: nb i*/
    }
}

void pdi(std::vector <std::string> vec, Window **win) {
    if (vec.size() == 2) {
        /* joueur mort de faim : pdi nb*/
    }
}

void seg(std::vector <std::string> vec, Window **win) {
    if (vec.size() == 1) {
        (*win)->killGame();
    }
}

void parseFD(int fd, std::mutex *m, Window **win) {
    std::string line;
    std::string cut;

    while (std::getline(std::cin, line)) {
        std::vector <std::string> vec;
        std::istringstream iss(line);

        if (line.length() != 0) {
            while (std::getline(iss, cut, ' ')) {
                vec.push_back(cut);
            }
            vec[0].compare("msz") == 0 ? msz(vec, win) : none(vec);
            vec[0].compare("BIENVENUE") == 0 ? bienvenue(vec, win) : none(vec);
            vec[0].compare("bct") == 0 ? bct(vec, win) : none(vec);
            vec[0].compare("pnw") == 0 ? pnw(vec, win) : none(vec);
            vec[0].compare("ppo") == 0 ? ppo(vec, win) : none(vec);
            vec[0].compare("pgt") == 0 ? pgt(vec, win) : none(vec);
            vec[0].compare("pdi") == 0 ? pdi(vec, win) : none(vec);
            vec[0].compare("seg") == 0 ? seg(vec, win) : none(vec);
        }
    }


}
