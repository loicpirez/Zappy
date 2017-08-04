//
// main.cpp for main in /home/loic/Développement/PSU_2016_zappy/graphical
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Wed Jun 28 18:34:35 2017 Loïc Pirez
// Last update Thu Jun 29 13:30:48 2017 Loïc Pirez
//

#include <SFML/Graphics.hpp>

sf::RectangleShape CreateShape(int sizeX, int sizeY, sf::Texture *mapTexture) {
    sf::RectangleShape shape(sf::Vector2f(sizeX, sizeY));
    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color(255, 255, 255));
    shape.setPosition(0, 0);
    shape.setTexture(mapTexture);
    shape.setTextureRect(sf::IntRect(100, 100, 100, 100));
    return (shape);
}

sf::RectangleShape CreateBackground(int x, int y, sf::Texture *mapTexture) {
    sf::RectangleShape shape(sf::Vector2f(x, y));
    shape.setPosition(0, 0);
    shape.setTexture(mapTexture);
    shape.setTextureRect(sf::IntRect(0, 0, 1000, 1000));
    return (shape);
}