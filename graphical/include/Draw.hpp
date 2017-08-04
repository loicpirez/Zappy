//
// Draw.hpp for Draw in /home/loic/Développement/PSU_2016_zappy/graphical/include
// 
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
// 
// Started on  Thu Jun 29 16:57:14 2017 Loïc Pirez
// Last update Thu Jun 29 16:57:15 2017 Loïc Pirez
//

#ifndef        DRAW_HPP_
# define    DRAW_HPP_

#include    <SFML/Graphics.hpp>

void
DrawMap(sf::RenderWindow *window, sf::RectangleShape shape, int height, int width, int sizeX, int sizeY, int sizeCube);
void drawObjectAtPos(Window **win, int x, int y, type lootType);
void drawPlayerAtPos(Window **win, int x, int y, Player p);

#endif        /* !DRAW_HPP_ */
