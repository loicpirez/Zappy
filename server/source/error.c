/*
** error.c for trhow_error in /home/zaczyk_a/TEK2/PSU_2016_myftp
** 
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
** 
** Started on  Wed May 10 11:21:48 2017 Antoine Zaczyk
** Last update Mon May 22 00:12:55 2017 Antoine Zaczyk
*/

#include	"my_server.h"

int		throw_error(char *err)
{
  fprintf(stderr, "%s\n", err);
  exit(EXIT_FAILURE);
}
