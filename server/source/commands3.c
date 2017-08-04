/*
** commands3.c for commands3 in /home/duprey_c/rendu/PSU_2016_zappy/server/source
**
** Made by Clément Duprey
** Login   <duprey_c@epitech.net>
**
** Started on  Thu Jun 29 14:32:46 2017 Clément Duprey
** Last update Mon Jul  3 01:29:36 2017 Antoine Zaczyk
*/

#include	"map.h"
#include	"my_server.h"

int		is_dead(t_list *player)
{
  if (player->life <= 0)
    {
      return (-1);
    }
  return (0);
}

void		print_enum(int fd, t_inv *curs)
{
  if (curs->item == LINEMATE)
    dprintf(fd, "LINEMATE : %d", curs->nb_item);
  else if (curs->item == DERAUMERE)
    dprintf(fd, "DERAUMERE : %d", curs->nb_item);
  else if (curs->item == SIBUR)
    dprintf(fd, "SIBUR : %d", curs->nb_item);
  else if (curs->item == MENDIANE)
    dprintf(fd, "MENDIANE : %d", curs->nb_item);
  else if (curs->item == PHIRAS)
    dprintf(fd, "PHIRAS : %d", curs->nb_item);
  else if (curs->item == THYSTAME)
    dprintf(fd, "THYSTAME : %d", curs->nb_item);
  else if (curs->item == APPLE)
    dprintf(fd, "APPLE : %d", curs->nb_item);
  if (curs->next != NULL)
    dprintf(fd, ", ");
  else
    dprintf(fd, "\n");
}

int		check_inventory(t_list *player, t_server *server, char *buf, int fd)
{
  t_inv		*curs;
  pid_t		pid;

  curs = player->inventory;
  if ((pid = fork()) == 0)
    {
      sleep(1/server->frequence);
      player->life -= 1;
      while (curs != NULL)
	{
	  print_enum(player->fd, curs);
	  curs = curs->next;
	}
      exit (0);
    }
  if (is_dead(player) == -1)
    return (-1);
  return (0);
}

int		unused_slots(t_list *player, t_server *server,
			      char *buf, int fd)
{
  t_team	*team;

  team = server->teams;
  while ((strcmp(team->name, player->name)) != 0 && team != NULL)
    team = team->next;
  if (team == NULL)
    throw_error("Team unknown");
  dprintf(player->fd, "%d\n", team->current_nb_client);
  return (0);
}

int		start_incantation(t_list *player, t_server *server,
				  char *buf, int fd)
{
  pid_t		pid;

  player->life -= 300/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  else
    player->level += 1;
  if ((pid = fork()) == 0)
    {
      sleep(300/server->frequence);
      dprintf(player->fd, "BIG BANG KAMEHAMEHA\n");
      exit(0);
    }
  return (0);
}
