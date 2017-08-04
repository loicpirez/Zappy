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
#include "../include/Window.hpp"
#include <iostream>

void none(void)
{

}


sf::Texture *getTextureByType(type lootType)
{
    sf::Texture *ret = new sf::Texture;

    if (lootType == APPLE)
        ret->loadFromFile("./texture/apple_.png");
    if (lootType == LINEMATE)
        ret->loadFromFile("./texture/linemate.png");
    if (lootType == DERAUMERE)
        ret->loadFromFile("./texture/deraumere.png");
    if (lootType == SIBUR)
        ret->loadFromFile("./texture/sibur.png");
    if (lootType == MENDIANE)
        ret->loadFromFile("./texture/mendiane.png");
    if (lootType == PHIRAS)
        ret->loadFromFile("./texture/phiras.png");
    if (lootType == THYSTAME)
        ret->loadFromFile("./texture/thystame.png");
    return (ret);
}


sf::Texture *getPlayerTexture(Player p)
{
    sf::Texture *ret = new sf::Texture;
    if (p.playerOrientation == UP)
        ret->loadFromFile("./texture/bmaniup_.png");
    if (p.playerOrientation == DOWN)
        ret->loadFromFile("./texture/bmani_.png");
    if (p.playerOrientation == LEFT)
        ret->loadFromFile("./texture/bmanileft_.png");
    if (p.playerOrientation == RIGHT)
        ret->loadFromFile("./texture/bmaniright_.png");
    return (ret);
}

void setPosByType(sf::Sprite *shape, type lootType, Window **win, int x, int y)
{
    lootType == APPLE ? shape->setPosition(x * (*win)->sizeCube, y * (*win)->sizeCube) : none();
    lootType == LINEMATE ? shape->setPosition(x * (*win)->sizeCube + (*win)->sizeCube / 3, y * (*win)->sizeCube ) : none();
    lootType == DERAUMERE ? shape->setPosition(x * (*win)->sizeCube + 2 * (*win)->sizeCube / 3, y * (*win)->sizeCube) : none();
    lootType == SIBUR ? shape->setPosition(x * (*win)->sizeCube + (*win)->sizeCube / 3, y * (*win)->sizeCube + (*win)->sizeCube / 3) : none();
    lootType == MENDIANE ? shape->setPosition(x * (*win)->sizeCube + 2 * (*win)->sizeCube / 3, y * (*win)->sizeCube + (*win)->sizeCube / 3) : none();
    lootType == PHIRAS ? shape->setPosition(x * (*win)->sizeCube, y * (*win)->sizeCube + (*win)->sizeCube / 3) : none();
    lootType == THYSTAME ? shape->setPosition(x * (*win)->sizeCube, y * (*win)->sizeCube + 2 * (*win)->sizeCube / 3) : none();
}

void drawObjectAtPos(Window **win, int x, int y, type lootType)
{
    sf::Texture *tex;
    sf::Sprite *sprite = new sf::Sprite();
    float ratioXY = (float)((*win)->sizeCube) / 100 / 3;

    tex = getTextureByType(lootType);
    sprite->setScale(ratioXY, ratioXY);
    setPosByType(sprite, lootType, win, x, y);
    sprite->setTexture(*tex);
    (*win)->window.draw(*sprite);
}

void drawPlayerAtPos(Window **win, int x, int y, Player p)
{
    sf::Texture *tex;
    sf::Sprite *sprite = new sf::Sprite();
    float ratioXY = (float)((*win)->sizeCube) / 100;

    tex = getPlayerTexture(p);
    sprite->setScale(ratioXY, ratioXY);
    sprite->setPosition(x * (*win)->sizeCube, y * (*win)->sizeCube);
    sprite->setTexture(*tex);
    (*win)->window.draw(*sprite);
}


void
DrawMap(sf::RenderWindow *window, sf::RectangleShape shape, int height, int width, int sizeX, int sizeY, int sizeCube) {
    int x = 0;
    int y;

    while (x < sizeX) {
        y = 0;
        while (y < sizeY) {
            shape.setPosition(x * sizeCube, y * sizeCube);
            window->draw(shape);
            y++;
        }
        x++;
    }
}