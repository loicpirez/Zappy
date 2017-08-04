/*
** main.c for zappy in /home/zaczyk_a/TEK2/server_zappy
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Tue Jun 27 16:01:50 2017 Antoine Zaczyk
** Last update Sun Jul  2 03:32:47 2017 Lucas Michalski
*/

#include	"my_server.h"
#include	"map.h"

int		main(int ac, char **av)
{
  t_server	*se;
  t_player	e;

  srand(time(NULL));
  if (ac == 1)
    usage();
  else
    {
      se = parse_args(av);
      is_complete(se);
      e = init_co(se);
      init_map(se);
      client_accept(se, e);
      my_free(se);
    }
  return (0);
}
