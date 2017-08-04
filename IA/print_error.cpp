//
// print_error.cpp for zappy in /home/vallae_h/Epitech/TEK2/CPP/PSU_2016_zappy/IA
// 
// Made by vallae_h
// Login   <vallae_h@epitech.net>
// 
// Started on  Wed Jun 28 20:25:21 2017 vallae_h
// Last update Wed Jun 28 21:12:54 2017 vallae_h
//

#include	<string>
#include	<stdlib.h>
#include	<iostream>

void		print_error(std::string str, int quit)
{
  std::cerr << str << std::endl;
  if (quit == 1)
    exit(1);
}
