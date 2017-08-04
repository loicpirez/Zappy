//
// Window.cpp for Window in /home/charles/Développement/PSU_2016_zappy/graphical/src
// 
// Made by Charles Lavalard
// Login   <charles.lavalard@epitech.eu>
// 
// Started on  Thu Jun 29 17:33:10 2017 Charles Lavalard
// Last update Thu Jun 29 17:33:10 2017 Charles Lavalard
//

#include "../include/Window.hpp"
#include <mutex>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <typeinfo>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


Window::Window(int height, int width, int mapX, int mapY)
        : window(sf::VideoMode(width, height), "Client", sf::Style::Titlebar | sf::Style::Close),
          map(mapX, mapY) {

}

Window::~Window() {

}

void Window::killGame() {
    system("killall mplayer");
    system("reset");
    kill(getpid(), SIGKILL);
}
