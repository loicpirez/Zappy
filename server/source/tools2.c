/*
** tools2.c for tools2.c in /home/duprey_c/rendu/PSU_2016_zappy/server/source
**
** Made by Clément Duprey
** Login   <duprey_c@epitech.net>
**
** Started on  Thu Jun 29 16:36:57 2017 Clément Duprey
** Last update Sun Jul  2 15:36:51 2017 Lucas Michalski
*/

#include	"my_server.h"

void		my_epur_str(char *str)
{
  int		cpt;

  cpt = 0;
  while (str[cpt])
    {
      if (str[cpt] != '\n')
	write(1, &str[cpt], 1);
      cpt++;
    }
}

int		*get_tab(int x, int y, int fd, int vision)
{
  int		*tab;

  if ((tab = malloc(sizeof(int) * 4)) == NULL)
    throw_error("Malloc failed");
  tab[0] = x;
  tab[1] = y;
  tab[2] = fd;
  tab[3] = vision;
  return (tab);
}
