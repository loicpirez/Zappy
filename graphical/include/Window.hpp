//
// Window.hpp for Window in /home/charles/Développement/PSU_2016_zappy/graphical/include
// 
// Made by Charles Lavalard
// Login   <charles.lavalard@epitech.eu>
// 
// Started on  Thu Jun 29 17:33:22 2017 Charles Lavalard
// Last update Thu Jun 29 17:33:23 2017 Charles Lavalard
//

#ifndef        WINDOW_HPP_
# define    WINDOW_HPP_

#include <SFML/Graphics.hpp>
#include "Map.hpp"

class Window {
public:
    Window(int height, int width, int mapX, int mapY);

    ~Window();

    sf::RenderWindow window;
    int sizeCube;
    Map map;
    void killGame(void);
};

Window *init_Window(int mapX, int mapY);

#endif        /* !WINDOW_HPP_ */
