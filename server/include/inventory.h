/*
** inventory.h for inventory in /home/skanx/rendu/PSU_2016_zappy/server/include
**
** Made by Lucas Michalski
** Login   <lucas.michalski@epitech.eu>
**
** Started on  Fri Jun 30 12:37:49 2017 Lucas Michalski
** Last update Mon Jul  3 01:39:00 2017 Antoine Zaczyk
*/

#ifndef			INVENTORY_H_
# define		INVENTORY_H_

enum			type
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    APPLE
  };

typedef struct		s_inventory
{
  enum type		item;
  int			nb_item;
  struct s_inventory	*next;
}			t_inv;

#endif			/* !INVENTORY_H_ */
