/*
** take_set.c for takeset in /home/duprey_c/rendu/PSU_2016_zappy/server/source
**
** Made by Clément Duprey
** Login   <duprey_c@epitech.net>
**
** Started on  Sat Jul  1 19:00:33 2017 Clément Duprey
** Last update Mon Jul  3 01:36:23 2017 Antoine Zaczyk
*/

#include	"my_server.h"
#include	"map.h"

int		take_linemate(t_list *player, t_server *server,
			     char *buf, int fd)
{
  t_inv         *curs;
  t_inv         *curs2;
  pid_t		pid;

  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  curs2 = server->map[player->posX][player->posY].inv;
  curs = server->map[player->posX][player->posY].inv;
  while (curs != NULL && curs->item != LINEMATE)
    curs = curs->next;
  if (curs != NULL)
    {
      add_item(player, curs->item);
      remove_item_from_map(curs2, curs->item);
      if ((pid = fork()) == 0)
	{
	  sleep(7 / server->frequence);
	  dprintf(player->fd, "ok\n");
	  exit (0);
	}
    }
  else
    print_ko(server->frequence, 7, player->fd, "ko\n");
  return (0);
}

int		set_linemate(t_list *player, t_server *server,
			    char *buf, int fd)
{
  t_inv         *curs;
  t_inv         *curs2;
  pid_t		pid;

  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  curs2 = server->map[player->posX][player->posY].inv;
  curs = player->inventory;
  while (curs != NULL && curs->item != LINEMATE)
    curs = curs->next;
  if (curs != NULL)
    {
      curs2 = add_item_to_map(curs2, curs->item);
      drop_item(player->inventory, curs);
      if ((pid = fork()) == 0)
	{
	  sleep(7 / server->frequence);
	  dprintf(player->fd, "ok\n");
	  exit (0);
	}
    }
  else
    print_ko(server->frequence, 7, player->fd, "ko\n");
  return (0);
}

int		take_deraumere(t_list *player, t_server *server,
			      char *buf, int fd)
{
  t_inv         *curs;
  t_inv         *curs2;
  pid_t		pid;

  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  curs2 = server->map[player->posX][player->posY].inv;
  curs = server->map[player->posX][player->posY].inv;
  while (curs != NULL && curs->item != DERAUMERE)
    curs = curs->next;
  if (curs != NULL)
    {
      add_item(player, curs->item);
      remove_item_from_map(curs2, curs->item);
      if ((pid = fork()) == 0)
	{
	  sleep(7 / server->frequence);
	  dprintf(player->fd, "ok\n");
	  exit (0);
	}
    }
  else
    print_ko(server->frequence, 7, player->fd, "ko\n");
  return (0);
}

int		set_deraumere(t_list *player, t_server *server,
			      char *buf, int fd)
{
  t_inv         *curs;
  t_inv         *curs2;
  pid_t		pid;

  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  curs2 = server->map[player->posX][player->posY].inv;
  curs = player->inventory;
  while (curs != NULL && curs->item != DERAUMERE)
    curs = curs->next;
  if (curs != NULL)
    {
      curs2 = add_item_to_map(curs2, curs->item);
      drop_item(player->inventory, curs);
      if ((pid = fork()) == 0)
	{
	  sleep(7 / server->frequence);
	  dprintf(player->fd, "ok\n");
	  exit (0);
	}
    }
  else
    print_ko(server->frequence, 7, player->fd, "ko\n");
  return (0);
}

int		take_sibur(t_list *player, t_server *server,
			   char *buf, int fd)
{
  t_inv         *curs;
  t_inv         *curs2;
  pid_t		pid;

  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  curs2 = server->map[player->posX][player->posY].inv;
  curs = server->map[player->posX][player->posY].inv;
  while (curs != NULL && curs->item != SIBUR)
    curs = curs->next;
  if (curs != NULL)
    {
      add_item(player, curs->item);
      remove_item_from_map(curs2, curs->item);
      if ((pid = fork()) == 0)
	{
	  sleep(7 / server->frequence);
	  dprintf(player->fd, "ok\n");
	  exit (0);
	}
    }
  else
    print_ko(server->frequence, 7, player->fd, "ko\n");
  return (0);
}
