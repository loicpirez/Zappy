/*
1;4803;0c1;4803;0c** map.h for zappy in /home/zaczyk_a/PSU_2016_zappy/server
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Fri Jun 30 17:01:47 2017 Antoine Zaczyk
** Last update Sun Jul  2 21:59:33 2017 Antoine Zaczyk
*/

#ifndef			_MAP_H_
# define		_MAP_H_

#include		"my_server.h"

typedef	struct		s_list_p
{
  t_list		*p;
  struct s_list_p	*next;
}			t_list_p;

typedef	struct		s_map
{
  int			number_loot;
  t_list_p		*player;
  t_inv			*inv;
}			t_map;

void			init_map(t_server *serv);
int			number_loot();
int			rand_loot();
bool			loot_ornot();
t_list_p		*add_player_to_map(t_list_p *player, t_list *p);
t_list_p		*remove_player_from_map(t_list_p *player, t_list *p);
void			init_tab(int *tab);
void			which_loot(int *tab, t_inv *inv);
void			player_case(t_list_p *tmp, int fd);

#endif			/* !MAP_H_ */
