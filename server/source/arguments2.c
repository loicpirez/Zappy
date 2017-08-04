/*
** arguments2.c for zappy in /home/zaczyk_a/TEK2/server_zappy
** 
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
** 
** Started on  Tue Jun 27 17:31:55 2017 Antoine Zaczyk
** Last update Wed Jun 28 15:18:20 2017 Antoine Zaczyk
*/

#include	"my_server.h"

int		my_frequence(t_server *my_server, char **tab, int i)
{
 if (tab[i + 1] == NULL)
    throw_error("-f : missing value");
  else if (my_isnumber(tab[i + 1]) == 1)
    throw_error("-f : positive number is required.");
 my_server->frequence = atoi(tab[i + 1]);
 return (i + 1);
}

int		my_help(t_server *my_server, char **tab, int i)
{
  usage();
  my_free(my_server);
  (void)tab;
  (void)i;
  exit(EXIT_SUCCESS);
}
