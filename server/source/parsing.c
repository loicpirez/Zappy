/*
** parsing.c for parsing in /home/zaczyk_a/TEK2/server_zappy
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Tue Jun 27 16:08:09 2017 Antoine Zaczyk
** Last update Sun Jul  2 20:42:23 2017 Lucas Michalski
*/

#include		"my_server.h"

static t_command        cmd_tab[8]=
  {
    {"-p", &my_port},
    {"-x", &my_width},
    {"-y", &my_height},
    {"-n", &name_team},
    {"-c", &number_client},
    {"-f", &my_frequence},
    {"-help", &my_help},
    {NULL, NULL}
  };

t_server		*parse_args(char **tab)
{
  int			i;
  int			j;
  t_server		*my_server;

  j = 0;
  i = 0;
  if ((my_server = malloc(sizeof(t_server))) == NULL)
    throw_error("ERROR malloc");
  init_server(my_server);
  while (tab[i])
    {
      while (cmd_tab[j].cmd != NULL)
	{
	  if (strcmp(cmd_tab[j].cmd, tab[i]) == 0)
	    i = cmd_tab[j].ptr(my_server, tab, i);
	  j++;
	}
      i++;
      j = 0;
    }
  return (my_server);
}
