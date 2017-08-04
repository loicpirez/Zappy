/*
** commands.c for commands in /home/duprey_c/rendu/PSU_2016_zappy/server/source
**
** Made by Clément Duprey
** Login   <duprey_c@epitech.net>
**
** Started on  Thu Jun 29 13:51:40 2017 Clément Duprey
** Last update Mon Jul  3 01:23:06 2017 Antoine Zaczyk
*/

#include		"map.h"

static t_action		act_tab[26]=
  {
    {"Forward\n", &move_forward},
    {"Right\n", &turn_right},
    {"Left\n", &turn_left},
    {"Look\n", &look_around},
    {"Inventory\n", &check_inventory},
    {"Broadcast text\n", &speaking},
    {"Connect_nbr\n", &unused_slots},
    {"Fork\n", &fork_player},
    {"Eject\n", &eject_player},
    {"-\n", &death},
    {"Take linemate\n", &take_linemate},
    {"Take deraumere\n", &take_deraumere},
    {"Take sibur\n", &take_sibur},
    {"Take mendiane\n", &take_mendiane},
    {"Take phiras\n", &take_phiras},
    {"Take thystame\n", &take_thystame},
    {"Take food\n", &take_apple},
    {"Set linemate\n", &set_linemate},
    {"Set deraumere\n", &set_deraumere},
    {"Set sibur\n", &set_sibur},
    {"Set mendiane\n", &set_mendiane},
    {"Set phiras\n", &set_phiras},
    {"Set thystame\n", &set_thystame},
    {"Set food\n", &set_apple},
    {"Incantation\n", &start_incantation},
    {NULL, NULL}
  };

int			check_cmd(t_list *player, t_server *server, char *buf, int fd)
{
  int			i;
  int			check;

  i = 0;
  check = 2;
  while (act_tab[i].act != NULL)
    {
      if (strcmp(act_tab[i].act, buf) == 0)
	{
	  check = act_tab[i].ptr(player, server, buf, fd);
	}
      i++;
    }
  if (check == 2)
    dprintf(player->fd, "ko\n");
  return (check);
}

int			move_forward(t_list *player, t_server *server, char *buf, int fd)
{
  t_list_p		*curs;

  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  remove_player_from_map(server->map[player->posX][player->posY].player,
			 player);
  if (player->vision == BOTTOM)
    player->posY = (player->posY < server->height ? player->posY + 1 : 0);
  else if (player->vision == TOP)
    player->posY = (player->posY > server->height ?
		    player->posY - 1 : server->height);
  else if (player->vision == RIGHT)
    player->posX = (player->posX < server->width ?
		    player->posX + 1 : 0);
  else if (player->vision == LEFT)
    player->posX = (player->posX > server->width ?
		    player->posX - 1 : server->width);
  curs = server->map[player->posX][player->posY].player;
  server->map[player->posX][player->posY].player = add_player_to_map(curs,
								     player);
  move(fd, player);
  return (0);
}

int			turn_right(t_list *player, t_server *server, char *buf, int fd)
{
  pid_t			pid;

  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  if (player->vision == BOTTOM)
    player->vision = LEFT;
  else if (player->vision == TOP)
    player->vision = RIGHT;
  else if (player->vision == RIGHT)
    player->vision = BOTTOM;
  else if (player->vision == LEFT)
    player->vision = TOP;
  if ((pid = fork()) == 0)
    {
      sleep(7/server->frequence);
      dprintf(player->fd, "ok\n");
      exit(0);
      if (fd != 540)
	dprintf(fd, "ppo %s %d %d %d\n", player->name, player->posX, player->posY,
		get_vision(player->vision));
      exit (0);
    }
  return (0);
}

int			turn_left(t_list *player, t_server *server, char *buf, int fd)
{
  pid_t			pid;

  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  if (player->vision == BOTTOM)
    player->vision = RIGHT;
  else if (player->vision == TOP)
    player->vision = LEFT;
  else if (player->vision == RIGHT)
    player->vision = TOP;
  else if (player->vision == LEFT)
    player->vision = BOTTOM;
  if ((pid = fork()) == 0)
    {
      sleep(7/server->frequence);
      dprintf(player->fd, "ok\n");
      if (fd != 540)
	dprintf(fd, "ppo %s %d %d %d\n", player->name, player->posX, player->posY,
		get_vision(player->vision));
      exit(0);
    }
  return (0);
}

int			look_around(t_list *player, t_server *server, char *buf, int fd)
{
  player->life -= 7/server->frequence;
  if (is_dead(player) == -1)
    return (-1);
  printf("look_around");
}
