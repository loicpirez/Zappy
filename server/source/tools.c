/*
** isnumber.c for zappy in /home/zaczyk_a/TEK2/server_zappy
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Tue Jun 27 16:44:32 2017 Antoine Zaczyk
** Last update Mon Jul  3 01:27:27 2017 Antoine Zaczyk
*/

#include	"my_server.h"

int		usage()
{
  printf("USAGE: ./zappy_server -p port -x width -y height -n ");
  printf("name1 name2 ... -c clientsNb -f freq\n");
  return (0);
}

int		my_isnumber(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] > '9' || str[i] < '0')
	return (1);
      i++;
    }
  return (0);
}

void		is_complete(t_server *server)
{
  if (server->port == 0 || server->width == 0 || server->height == 0)
    throw_error("ERROR : missing arguments");
  else if (server->number_max == 0 || server->frequence == 0)
    throw_error("ERROR : missing arguments");
  else if (server->teams == NULL)
    throw_error("ERROR : missing arguments");
}

void		init_server(t_server *server)
{
  server->port = 0;
  server->width = 0;
  server->height = 0;
  server->number_max = 0;
  server->frequence = 0;
  server->fd = 42;
  server->teams = NULL;
}

void		print_ko(int freq, int life, int fd, char *str)
{
  pid_t		pid;

  if ((pid = fork()) == 0)
    {
      sleep(life / freq);
      dprintf(fd, "%s", str);
      exit (0);
    }
}
