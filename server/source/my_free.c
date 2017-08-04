/*
** my_free.c for zappy in /home/zaczyk_a/TEK2/server_zappy
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Tue Jun 27 18:26:47 2017 Antoine Zaczyk
** Last update Fri Jun 30 17:40:59 2017 Lucas Michalski
*/

#include	"my_server.h"

void		free_inventory(t_inv *inv)
{
  t_inv		*curs;

  while (inv->next != NULL)
    {
      curs = inv;
      inv = curs->next;
      free(curs);
    }
  free(inv);
}

void		free_team(t_team *team)
{
  t_team	*curs;

  while (team->next != NULL)
    {
      curs = team;
      free(team->name);
      team = curs->next;
      free(curs);
    }
  free(team);
}

void		my_free(t_server *server)
{
  if (server)
    {
      if (server->fd != 42)
	{
	  if (close(server->fd) == -1)
	    throw_error("ERROR : Can not close socket");
	}
      free_team(server->teams);
      free(server);
    }
  exit(EXIT_SUCCESS);
}
