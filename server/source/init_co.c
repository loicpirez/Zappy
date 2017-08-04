/*
** launch_server.c for zappy in /home/zaczyk_a/TEK2/server_zappy
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Wed Jun 28 15:01:42 2017 Antoine Zaczyk
** Last update Sun Jul  2 03:33:21 2017 Lucas Michalski
*/

#include		"my_server.h"
#include		"map.h"

static int		get_protocole()
{
  struct protoent	*pe;

  if ((pe = getprotobyname("TCP")) == NULL)
    throw_error("ERROR : Can not find protocole");
  return (pe->p_proto);
}

static void		create_socket(int protocole, t_server *server)
{
  if ((server->fd = socket(AF_INET, SOCK_STREAM, protocole)) == -1)
    throw_error("Error : can not create socket");
}

static	int		init_bind(t_server *my_server)
{
  struct sockaddr_in	s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(my_server->port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(my_server->fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      fprintf(stderr, "%s\n", "ERROR bind, please select an other port.");
      my_free(my_server);
    }
  return (0);
}

static	void		add_server(t_player *e, int fd)
{
  e->fd_type[fd] = FD_SERVER;
  e->fct_read[fd] = server_read;
  e->fct_write[fd] = NULL;
  e->fd = fd;
  e->posX = 0;
  e->posY = 0;
  e->name = NULL;
  e->inventory = NULL;
  e->vision = 0;
  e->level = 0;
}

t_player		init_co(t_server *my_server)
{
  int			proto;
  t_player		e;

  proto = get_protocole();
  create_socket(proto, my_server);
  init_bind(my_server);
  if (listen(my_server->fd, 42) == -1)
    {
      fprintf(stderr, "%s\n", "ERROR : can not listen");
      my_free(my_server);
    }
  memset(e.fd_type, FD_FREE, MAX_FD);
  e.port = my_server->port;
  add_server(&e, my_server->fd);
  return (e);
}
