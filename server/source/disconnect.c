/*
** disconnect.c for disconnect in /home/duprey_c/rendu/PSU_2016_zappy/server
**
** Made by Clément Duprey
** Login   <duprey_c@epitech.net>
**
** Started on  Fri Jun 30 16:30:22 2017 Clément Duprey
** Last update Mon Jul  3 01:30:00 2017 Antoine Zaczyk
*/

#include		"my_server.h"
#include		"map.h"

t_list			*remove_client_from_list(t_list *clients,
						 t_list *to_find)
{
  t_list		*curs;
  t_list		*curs2;

  if (clients == to_find)
    {
      if (clients->next == NULL)
	{
	  free(clients);
	  return (NULL);
	}
      curs = clients;
      clients = clients->next;
      free(curs);
      return (clients);
    }
  curs = clients;
  while (curs != NULL && curs->next->fd != to_find->fd)
    curs = curs->next;
  if (curs == NULL)
    throw_error("An error occured with clients list");
  curs2 = curs->next;
  curs->next = curs->next->next;
  free(curs2);
  return (clients);
}

void			client_disconnect(t_list *e,
					  t_server *server, t_list *player)
{
  t_team	       *tmp;

  tmp = server->teams;
  remove_player_from_map(server->map[e->posX][e->posY].player, e);
  close(e->fd);
  while (strcmp(e->name, tmp->name) != 0 && tmp != NULL)
    tmp = tmp->next;
  tmp->current_nb_client += 1;
  free(e->name);
  if (e->inventory != NULL)
    free_inventory(e->inventory);
  remove_client_from_list(player, e);
  printf("Connection closed\n");
}
