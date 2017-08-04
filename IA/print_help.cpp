//
// print_help.cpp for zappy in /home/vallae_h/Epitech/TEK2/CPP/PSU_2016_zappy/IA
// 
// Made by vallae_h
// Login   <vallae_h@epitech.net>
// 
// Started on  Wed Jun 28 18:10:46 2017 vallae_h
// Last update Wed Jun 28 18:49:16 2017 vallae_h
//

#include	<iostream>
#include	<stdlib.h>
#include	<stdio.h>

void		print_help()
{
  std::cout << "USAGE:\t./zappy_ai -p port -n name -h machine\n\tport\tis the port number\n\tname\tis the name of the team\n\tmachine\tis the name of the machine; localhost by default" << std::endl;
  exit(0);
}
