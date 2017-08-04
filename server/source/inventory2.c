/*
** inventory2.c for inventory2 in /home/skanx/rendu/PSU_2016_zappy/server
**
** Made by Lucas Michalski
** Login   <lucas.michalski@epitech.eu>
**
** Started on  Sat Jul  1 16:01:49 2017 Lucas Michalski
** Last update Sat Jul  1 23:15:49 2017 Lucas Michalski
*/

#include	"my_server.h"

void		remove_item_from_map(t_inv *inv, enum type item)
{
  t_inv		*curs;
  t_inv		*curs2;

  curs = inv;
  while (curs != NULL && item != curs->next->item)
    curs = curs->next;
  curs2 = curs->next->next;
  free(curs->next);
  curs->next = curs2;
}
