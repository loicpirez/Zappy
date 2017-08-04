/*
** client_accept.c for client_accept in /home/duprey_c/rendu/PSU_2016_zappy/server/source
**
** Made by Clément Duprey
** Login   <duprey_c@epitech.net>
**
** Started on  Wed Jun 28 18:36:23 2017 Clément Duprey
** Last update Mon Jul  3 01:18:27 2017 Antoine Zaczyk
*/

#include		"my_server.h"
#include		"map.h"

int			fd_graphic = 540;

void			client_read(t_player *e, int fd,
				    t_server *server, t_list *players)
{
  int			r;
  char			buf[4096];
  t_list		*curs;

  r = read(fd, buf, 4096);
  curs = players;
  while (curs != NULL && curs->fd != fd)
    curs = curs->next;
  if (r > 0)
    {
      buf[r] = '\0';
      if (curs != NULL)
	if (check_cmd(curs, server, buf, fd_graphic) == -1)
	  {
	    e->fd_type[fd] = FD_FREE;
	    client_disconnect(curs, server, players);
	  }
    }
  else
    {
      e->fd_type[fd] = FD_FREE;
      client_disconnect(curs, server, players);
    }
}

int			add_client(t_list *e, int fd,
				   t_server *serv, char *name)
{
  int			x;
  t_list_p		*curs;
  t_list		*tmp;
  t_list		*new;

  tmp = e;
  if ((x = get_remaining_client(serv, name)) < 0)
    return (-1);
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  if ((new = malloc(sizeof(t_list))) == NULL)
    throw_error("ERROR : malloc");
  new->name = strdup(name);
  new->fd = fd;
  new->posX = my_rand_pos(serv->width);
  new->posY = my_rand(serv->height);
  new->inventory = NULL;
  new->vision = my_rand();
  new->level = 0;
  new->life = 1260 / serv->frequence;
  new->next = NULL;
  curs = serv->map[new->posX][new->posY].player;
  serv->map[new->posX][new->posY].player = add_player_to_map(curs, new);
  tmp->next = new;
  dprintf(fd, "%d\n", x);
  dprintf(fd, "%d %d\n", serv->width, serv->height);
  return (0);
}

int			check_client(t_player *e, int fd, t_server *serv, t_list *player)
{
  char			buf[4096];
  int			r;

  r = read(fd, buf, 4096);
  buf[r - 1] = '\0';
  if (r != 0 && strcmp(buf, "GRAPHIC") == 0)
    {
      fd_graphic = fd;
      client_graphic(fd, serv);
      return (0);
    }
  else if (r == 0 || check_team_name(serv, buf) != 0)
    return (-1);
  if (add_client(player, fd, serv, buf) == -1)
    return (-1);
  else
    {
      e->fd_type[fd] = FD_CLIENT;
      e->fct_read[fd] = client_read;
      e->fd = fd;
    }
  return (0);
}

void			server_read(t_player *e, int fd, t_server *serv, t_list *player)
{
  int			cs;
  struct sockaddr_in	client_sin;
  socklen_t		client_sin_len;

  printf("NEW CLIENT\n");
  client_sin_len = sizeof(client_sin);
  cs = accept(fd, (struct sockaddr *)&client_sin, &client_sin_len);
  if (cs == -1)
    printf("ERROR : client can not be connected\n");
  else
    {
      dprintf(cs, "WELCOME\n");
      if (check_client(e, cs, serv, player) == -1)
	{
	  dprintf(cs, "Unknow team, disconnected.\n");
	  close(cs);
	}
    }
}

int			client_accept(t_server *server, t_player e)
{
  int			i;
  int			fd_max;
  fd_set		fd_read;
  t_list		*player;
  struct timeval	tv;

  player = init_list();
  tv.tv_sec = 20;
  tv.tv_usec = 0;
  while (1)
    {
      i = -1;
      FD_ZERO(&fd_read);
      fd_max = 0;
      while (++i < MAX_FD)
	if (e.fd_type[i] != FD_FREE)
	  {
	    FD_SET(i, &fd_read);
	    fd_max = i;
	  }
      i = -1;
      if (select(fd_max + 1, &fd_read, NULL, NULL, &tv) == -1)
	perror("ERROR on select\n");
      while (++i < MAX_FD)
	if (FD_ISSET(i, &fd_read))
	  e.fct_read[i](&e, i, server, player);
    }
  return (0);
}
