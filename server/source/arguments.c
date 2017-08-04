/*
** arguments.c for zappy in /home/zaczyk_a/TEK2/server_zappy
** 
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
** 
** Started on  Tue Jun 27 16:33:59 2017 Antoine Zaczyk
** Last update Sun Jul  2 20:38:11 2017 Antoine Zaczyk
*/

#include	"my_server.h"

int		number_client(t_server *my_server, char **tab, int i)
{
  if (tab[i + 1] == NULL)
    throw_error("-c : missing value");
  else if (my_isnumber(tab[i + 1]) == 1)
    throw_error("-c : positive number is required.");
  my_server->number_max = atoi(tab[i + 1]);
  set_nb_client_to_team(my_server);
  return (i + 1);
}

int		my_port(t_server *my_server, char **tab, int i)
{
  if (tab[i + 1] == NULL)
    throw_error("-p : missing value");
  else if (my_isnumber(tab[i + 1]) == 1)
    throw_error("-p : positive number is required.");
  my_server->port = atoi(tab[i + 1]);
  return (i + 1);
}

int		my_width(t_server *my_server, char **tab, int i)
{
  if (tab[i + 1] == NULL)
    throw_error("-x : missing value");
  else if (my_isnumber(tab[i + 1]) == 1)
    throw_error("-x : positive number is required.");
  my_server->width = atoi(tab[i + 1]);
  if (my_server->width < 3 || my_server->width > 50)
    throw_error("-x : 3 minimun and 50 maximun !");
  return (i + 1);
}

int		my_height(t_server *my_server, char **tab, int i)
{
  if (tab[i + 1] == NULL)
    throw_error("-y : missing value");
  else if (my_isnumber(tab[i + 1]) == 1)
    throw_error("-y : positive number is required.");
  my_server->height = atoi(tab[i + 1]);
  if (my_server->height < 3 || my_server->height > 50)
    throw_error("-y : 3 minimun and 50 maximun !");
  return (i + 1);
}

int		name_team(t_server *my_server, char **tab, int i)
{
  int		max;
  int		j;

  j = 0;
  if (my_server->teams != NULL)
    throw_error("ERROR : -n already set.");
  if (tab[i + 1] == NULL)
    throw_error("-n : missing value");
  while (tab[i + j + 1] != NULL && tab[i + j + 1][0] != '-')
    j++;
  max = j;
  if (max == 0)
    throw_error("-n : missing value");
  j = 0;
  while (j < max)
    {
      if (tab[i + 1 + j] == NULL)
	throw_error("-n : missing value");
      malloc_team(my_server, strdup(tab[i + j + 1]));
      j++;
    }
  return (i + j);
}
