/*
** my_rand.c for zappy in /home/zaczyk_a/PSU_2016_zappy/server
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Thu Jun 29 19:28:22 2017 Antoine Zaczyk
** Last update Sun Jul  2 20:41:48 2017 Lucas Michalski
*/

#include	"my_server.h"

int		my_rand_pos(int x)
{
  return (rand() % x);
}

position	my_rand()
{
  int		pos;

  pos = rand() % 4 + 1;
  if (pos == 1)
    return (TOP);
  else if (pos == 2)
    return (LEFT);
  else if (pos == 3)
    return (RIGHT);
  else
    return (BOTTOM);
}

int		number_loot()
{
  int		number;

  number = rand() % 4 + 1;
  return (number);
}

int		rand_loot()
{
  int		loot;

  loot = rand() % 100;
  if (loot < 5)
    return (PHIRAS);
  else if (loot >= 5 && loot < 10)
    return (THYSTAME);
  else if (loot >= 10 && loot < 20)
    return (DERAUMERE);
  else if (loot >= 20 && loot < 30)
    return (MENDIANE);
  else if (loot >= 30 && loot < 50)
    return (SIBUR);
  else if (loot >= 50 && loot < 70)
    return (LINEMATE);
  else
    return (APPLE);
}

bool		loot_ornot()
{
  int		loot;

  loot = rand() % 3 + 1;
  return ((loot == 3 ? false : true));
}
