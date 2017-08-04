/*
** inventory.c for inventory in /home/skanx/rendu/PSU_2016_zappy/server/source
**
** Made by Lucas Michalski
** Login   <lucas.michalski@epitech.eu>
**
** Started on  Fri Jun 30 12:59:34 2017 Lucas Michalski
** Last update Mon Jul  3 01:31:06 2017 Antoine Zaczyk
*/

#include	"my_server.h"
#include	"inventory.h"

void		drop_item(t_inv	*inv, t_inv *item)
{
  t_inv		*curs;

  if ((item->nb_item -= 1) <= 0)
    {
      curs = inv;
      while (curs->next->item != item->item)
	curs = curs->next;
      curs->next = item->next;
      free(item);
    }
}

void		add_item_next(t_list *p, enum type item)
{
  t_inv		*curs;
  t_inv		*new;

  curs = p->inventory;
  while (curs->next != NULL)
    {
      if (curs->item == item)
	{
	  curs->nb_item += 1;
	  return ;
	}
      curs = curs->next;
    }
  if ((new = malloc(sizeof(t_inv))) ==  NULL)
    throw_error("Malloc failed\n");
  new->item = item;
  new->nb_item = 1;
  curs->next = new;
  new->next = NULL;
}

void		add_item(t_list *p, enum type item)
{
  if (p->inventory == NULL)
    {
      if ((p->inventory = malloc(sizeof(t_inv))) ==  NULL)
	throw_error("Malloc failed\n");
      p->inventory->item = item;
      p->inventory->next = NULL;
      p->inventory->nb_item = 1;
      return ;
    }
  add_item_next(p, item);
}

void		add_item_to_map_next(t_inv *inv, enum type item)
{
  t_inv		*curs;
  t_inv		*new;

  curs = inv;
  while (curs->next != NULL)
    {
      if (curs->item == item)
	{
	  curs->nb_item += 1;
	  return ;
	}
      curs = curs->next;
    }
  if ((new = malloc(sizeof(t_inv))) ==  NULL)
    throw_error("Malloc failed\n");
  new->item = item;
  new->nb_item = 1;
  curs->next = new;
  new->next = NULL;
}

t_inv		*add_item_to_map(t_inv *inv, enum type item)
{
  if (inv == NULL)
    {
      if ((inv = malloc(sizeof(t_inv))) ==  NULL)
	throw_error("Malloc failed\n");
      inv->item = item;
      inv->next = NULL;
      inv->nb_item = 1;
      return (inv);
    }
  add_item_to_map_next(inv, item);
  return (inv);
}
