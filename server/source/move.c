/*
** move.c for zappy in /home/zaczyk_a/PSU_2016_zappy/server
** 
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
** 
** Started on  Sun Jul  2 21:41:44 2017 Antoine Zaczyk
** Last update Mon Jul  3 01:21:53 2017 Antoine Zaczyk
*/

#include	"my_server.h"

void		move(int fd, t_list *player)
{
  pid_t		pid;

  if ((pid = fork()) == 0)
    {
      dprintf(player->fd, "ok\n");
      if (fd != 540)
	dprintf(fd, "ppo %s %d %d %d\n", player->name, player->posX, player->posY,
		get_vision(player->vision));
      exit(0);
    }
}
