/*
** tools_graphic.c for zappy in /home/zaczyk_a/PSU_2016_zappy/server
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Sun Jul  2 00:14:06 2017 Antoine Zaczyk
** Last update Sun Jul  2 20:54:20 2017 Antoine Zaczyk
*/

#include	"map.h"

void		init_tab(int *tab)
{
  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  tab[3] = 0;
  tab[4] = 0;
  tab[5] = 0;
  tab[6] = 0;
}

void		which_loot(int *tab, t_inv *inv)
{
  if (inv->item == LINEMATE)
    tab[1] = inv->nb_item;
  if (inv->item == DERAUMERE)
    tab[2] = inv->nb_item;
  if (inv->item == SIBUR)
    tab[3] = inv->nb_item;
  if (inv->item == MENDIANE)
    tab[4] = inv->nb_item;
  if (inv->item == PHIRAS)
    tab[5] = inv->nb_item;
  if (inv->item == THYSTAME)
    tab[6] = inv->nb_item;
  if (inv->item == APPLE)
    tab[0] = inv->nb_item;
}

int		get_vision(position p)
{
  int		pos;

  pos = 0;
  if (p == TOP)
    pos = 1;
  else if (p == RIGHT)
    pos = 2;
  else if (p == LEFT)
    pos = 3;
  else if (p == BOTTOM)
    pos = 4;
  return (pos);
}

void		player_case(t_list_p *tmp, int fd)
{
  int		pos;

  pos = 0;
  while (tmp != NULL)
    {
      pos = get_vision(tmp->p->vision);
      dprintf(fd, "ppo %s %d %d %d\n", tmp->p->name,
      	      tmp->p->posX, tmp->p->posY, pos);
      tmp = tmp->next;
    }
}

t_list		*init_list()
{
  t_list	*new;

  new = malloc(sizeof(t_list));
  if (new == NULL)
    throw_error("ERROR : malloc");
  new->fd = 3000;
  new->name = NULL;
  new->posX = 0;
  new->posY = 0;
  new->inventory = NULL;
  new->vision = 0;
  new->level = 0;
  new->life = 0;
  new->next = NULL;
  return (new);
}
