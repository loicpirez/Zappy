/*
** commands2.c for commands2 in /home/duprey_c/rendu/PSU_2016_zappy/server/source
**
** Made by Clément Duprey
** Login   <duprey_c@epitech.net>
**
** Started on  Thu Jun 29 14:30:11 2017 Clément Duprey
** Last update Mon Jul  3 01:29:16 2017 Antoine Zaczyk
*/

#include	"my_server.h"

int		death(t_list *player, t_server *server,  char *buf, int fd)
{
  (void)player;
  (void)server;
  (void)buf;
  fd = fd;
  dprintf(player->fd, "dead\n");
  return (-1);
}

int		speaking(t_list *player, t_server *server, char *buf, int fd)
{
  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  dprintf(player->fd, "ok\n");
  return (0);
}

int		fork_player(t_list *player, t_server *server, char *buf, int fd)
{
  player->life -= 42/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  dprintf(player->fd, "ok\n");
  return (0);
}

int		eject_player(t_list *player, t_server *server, char *buf, int fd)
{
  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  dprintf(player->fd, "ok\n");
  return (0);
}
