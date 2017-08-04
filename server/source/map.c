/*
** map.h for zappy in /home/zaczyk_a/PSU_2016_zappy/server
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Fri Jun 30 17:32:10 2017 Antoine Zaczyk
** Last update Sat Jul  1 17:14:26 2017 Antoine Zaczyk
*/

#include	"map.h"

t_inv		*set_loot(t_map *map)
{
  map->number_loot += 1;
  map->inv = add_item_to_map(map->inv, rand_loot());
  return (map->inv);
}

t_inv		*multi_loot(int nb, t_map *map)
{
  int		i;

  i = 0;
  map->number_loot = nb;
  while (i < nb)
    {
      map->inv = add_item_to_map(map->inv, rand_loot());
      i++;
    }
  return (map->inv);
}

t_map		*fill_map(t_map *map, int max)
{
  int		y;
  int		rand;

  y = 0;
  rand = 0;
  while (y < max)
    {
      map[y].number_loot = 0;
      map[y].player = NULL;
      map[y].inv = NULL;
      if (loot_ornot() == true)
	{
	  rand = number_loot();
	  if (rand == 1)
	      map[y].inv = set_loot(&map[y]);
	  else
	    map[y].inv = multi_loot(rand, &map[y]);
	}
      y++;
    }
  return (map);
}

void		init_map(t_server *serv)
{
  t_map		**map;
  int		x;

  x = 0;
  if ((map = malloc(sizeof(t_map) * (serv->width + 1))) == NULL)
    throw_error("ERROR : malloc");
  while (x < serv->width)
    {
      if ((map[x] = malloc(sizeof(t_map) * (serv->height + 1))) == NULL)
	throw_error("ERROR : malloc");
      if ((map[x] = fill_map(map[x], serv->height)) == NULL)
	throw_error("ERROR : map incomplete");
      x++;
    }
  map[x] = NULL;
  serv->map = map;
}
