//
// Create.hpp for Create in /home/loic/Développement/PSU_2016_zappy/graphical/include
// 
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
// 
// Started on  Thu Jun 29 16:57:22 2017 Loïc Pirez
// Last update Thu Jun 29 16:57:23 2017 Loïc Pirez
//

#ifndef        CREATE_HPP_
# define    CREATE_HPP_

#include    <SFML/Graphics.hpp>

sf::RectangleShape CreateShape(int sizeX, int sizeY, sf::Texture *mapTexture);

sf::RectangleShape CreateBackground(int x, int y, sf::Texture *mapTexture);

sf::RenderWindow CreateWindow(int height, int width);

#endif        /* !CREATE_HPP_ */