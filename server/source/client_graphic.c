/*
** client_graphic.c for zappy in /home/zaczyk_a/PSU_2016_zappy/server
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Sat Jul  1 18:32:00 2017 Antoine Zaczyk
** Last update Mon Jul  3 01:30:24 2017 Antoine Zaczyk
*/

#include	"my_server.h"
#include	"map.h"

void		loot_case(int fd, t_server *serv, int x, int y)
{
  t_inv		*curs;
  int		tab[7];

  curs = serv->map[x][y].inv;
  init_tab(tab);
  if (curs == NULL)
    dprintf(fd, "bct %d %d 0 0 0 0 0 0 0\n", x, y);
  else
    {
      while (curs != NULL)
	{
	  which_loot(tab, curs);
	  curs = curs->next;
	}
      dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
	      tab[0], tab[1],tab[2], tab[3], tab[4], tab[5], tab[6]);
    }
}

void		send_loot(int fd, t_server *serv)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (x < serv->width)
    {
      while (y < serv->height)
	{
	  loot_case(fd, serv, x, y);
	  y++;
	}
      y = 0;
      x++;
    }

}

void		send_team(int fd, t_server *serv)
{
  t_team	*curs;

  curs = serv->teams;
  if (curs == NULL)
    dprintf(fd, "tna NULL\n");
  else
    {
      while (curs != NULL)
	{
	  dprintf(fd, "tna %s\n", curs->name);
	  curs = curs->next;
	}
    }
}

void		send_player(int fd, t_server *serv)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (x < serv->width)
    {
      while (y < serv->height)
	{
	  if (serv->map[x][y].player != NULL)
	    player_case(serv->map[x][y].player, fd);
	  y++;
	}
      y = 0;
      x++;
    }
}

void		client_graphic(int fd, t_server *serv)
{
  pid_t		pid;

  if ((pid = fork()) == 0)
    {
      dprintf(fd, "msz %d %d\n", serv->width, serv->height);
      dprintf(fd, "sgt %d\n", serv->frequence);
      send_loot(fd, serv);
      send_team(fd, serv);
      send_player(fd, serv);
      close(fd);
      exit (EXIT_SUCCESS);
    }
  else if (pid == -1)
    throw_error("ERROR : malloc failled");
}
