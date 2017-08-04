//
// PARSE.hpp for PARSE in /home/loic/Développement/PSU_2016_zappy/graphical/include
//
// Made by Loïc Pirez
// Login   <loic.pirez@epitech.eu>
//
// Started on  Thu Jun 29 16:57:14 2017 Loïc Pirez
// Last update Thu Jun 29 16:57:15 2017 Loïc Pirez
//

#ifndef    PARSE_HPP_
# define  PARSE_HPP_

#include <mutex>

void parseFD(int fd, std::mutex *m, Window **win);

#endif    /* !PARSE_HPP_ */