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
#include <iostream>
#include "../include/Create.hpp"
#include "../include/Window.hpp"
#include "../include/Draw.hpp"
#include "../include/Parse.hpp"
#include "../include/Loot.hpp"
#include <thread>
#include <string>
#include <limits.h>
#include <unistd.h>
#include <math.h>
#include <iostream>
#include <csignal>
#include <unistd.h>
#include <mutex>

std::mutex m;
Window *win = init_Window(10, 10);

Window *init_Window(int mapX, int mapY) {
    int height = 1000;
    int width = 1000;
    int lowerMapSize;
    int cubeSize;

    lowerMapSize = (mapX >= mapY) ? mapX : mapY;
    cubeSize = 1000 / lowerMapSize;
    height = (mapY > mapY) ? 1000 : cubeSize * mapY;
    width = (mapX > mapY) ? 1000 : cubeSize * mapX;
    Window *win = new Window(height, width, mapX, mapY);
    win->map.resizeMapCases(mapX, mapY);
    win->sizeCube = cubeSize;
    return win;
}

void fillImage(sf::Image *image, int value) {
    value == LINEMATE ? image->loadFromFile("texture/linemate.png") : LINEMATE;
    value == DERAUMERE ? image->loadFromFile("texture/deraumere.png") : DERAUMERE;
    value == SIBUR ? image->loadFromFile("texture/sibur.png") : SIBUR;
    value == MENDIANE ? image->loadFromFile("texture/mendiane.png") : MENDIANE;
    value == PHIRAS ? image->loadFromFile("texture/phiras.png") : PHIRAS;
    value == THYSTAME ? image->loadFromFile("texture/thystame.png") : THYSTAME;
    value == APPLE ? image->loadFromFile("texture/apple_.gif") : APPLE;
}

int getValueDivideCase(int nb_obj) {
    double result;

    result = 0;
    result = sqrt(nb_obj);
    result = ceil(result);
    return result;
}

void putImagetoWindow(Window *window, int posX, int posY, int value, int size) {
    sf::Image image;
    sf::Texture tex;
    sf::Sprite sprite;

    fillImage(&image, value);
    image.createMaskFromColor(sf::Color(), 0);
    tex.loadFromImage(image);
    sprite.setTexture(tex);
    sprite.setScale((float) window->sizeCube / 100 / size, (float) window->sizeCube / 100 / size);
    sprite.setPosition(posX * window->sizeCube, posY * window->sizeCube);
    window->window.draw(sprite);
    window->window.display();
}

void sigHandler(int s) {
    win->killGame();
}

void putAllObjectInWindow(Window *win)
{
    int x = 0;
    int y = 0;

    while (x < win->map.sizeX)
    {
        y = 0;
        while (y < win->map.sizeY)
        {
            for (Loot i : win->map.cases[x][y].loots)
            {
                drawObjectAtPos(&win, x, y, i.lootType);
            }
            for (Player p : win->map.cases[x][y].players)
            {
                drawPlayerAtPos(&win, x, y, p);
            }
            y++;
        }
        x++;
    }
}

void windowThread(void) {
    int height = 1000;
    int width = 1000;
    int mapX = 10;
    int mapY = 10;

/*    struct sigaction act;
    act.sa_handler = sigHandler;
    sigaction(SIGINT, act, NULL);*/

    sf::Texture mapTexture;
    sf::Texture mapBackground;
    sf::RectangleShape caseShape;
    sf::RectangleShape backgroundShape;

    win->map.addCaseAtPosition(0, 0);
    if (!mapTexture.loadFromFile("./texture/grass.png") || !mapBackground.loadFromFile("./texture/water.jpg"))
        std::cout << "Error: can't load texture" << std::endl;

    caseShape = CreateShape(win->sizeCube, win->sizeCube, &mapTexture);
    backgroundShape = CreateBackground(1000, 1000, &mapBackground);

    while (win->window.isOpen()) {
        m.lock();
        m.unlock();
        m.lock();
        m.unlock();
        sf::Event event;
        while (win->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win->window.close();
        }
        win->window.clear();
        win->window.draw(backgroundShape);
        DrawMap(&win->window, caseShape, height, width, 50, 50, win->sizeCube);
        putAllObjectInWindow(win);
        win->window.display();
    }
    win->killGame();
}

void parseThread(void) {
    parseFD(0, &m, &win);
}

void audioThread(void) {
    system("mplayer -loop 0 music/theme.ogg > /dev/null 2>&1 &");
}

int main(void) {
    std::thread t1(windowThread);
    std::thread t2(parseThread);
    std::thread t3(audioThread);

    t1.join();
    t2.join();
    t3.join();

    return (0);
}
