/*
** my_server.h for my_server in /home/zaczyk_a/TEK2/server_zappy
**
** Made by Antoine Zaczyk
** Login   <antoine.zaczyk@epitech.eu>
**
** Started on  Tue Jun 27 16:18:08 2017 Antoine Zaczyk
** Last update Mon Jul  3 01:39:57 2017 Antoine Zaczyk
*/

#ifndef		_MY_SERVER_H_
# define	_MY_SERVER_H_

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<dirent.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netdb.h>
#include	<unistd.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<string.h>
#include	<stdlib.h>
#include	<time.h>
#include	"team.h"
#include	"inventory.h"

#define		MAX_FD 255
#define		FD_FREE 0
#define		FD_CLIENT 1
#define		FD_SERVER 2
#define		FD_GRAPHIC 3

typedef	int	bool;

#define		true 1
#define		false 0

typedef enum	{
  TOP,
  LEFT,
  RIGHT,
  BOTTOM
}		position;

typedef	struct	s_server
{
  int		fd;
  int		port;
  int		width;
  int		height;
  int		number_max;
  int		frequence;
  t_team	*teams;
  struct s_map	**map;
}		t_server;

typedef	struct	s_client
{
  int		fd;
}		t_client;

typedef		void(*fct)();

typedef	struct	s_player
{
  char		fd_type[MAX_FD];
  fct		fct_read[MAX_FD];
  fct		fct_write[MAX_FD];
  int		port;
  int		fd;
  int		posX;
  int		posY;
  char		*name;
  t_inv		*inventory;
  int		vision;
  int		level;
  int		life;
}		t_player;

typedef struct	s_list
{
  char		*name;
  int		fd;
  int		posX;
  int		posY;
  t_inv		*inventory;
  int		level;
  int		life;
  int		vision;
  struct s_list	*next;
}		t_list;

typedef	struct	s_command
{
  char		*cmd;
  int		(*ptr)(t_server *my_server, char **tab, int i);
}		t_command;

typedef	struct	s_action
{
  char		*act;
  int		(*ptr)(t_list *player, t_server *server, char *buf, int fd);
}		t_action;

int		throw_error(char *err);
int		my_port(t_server *my_server, char **tab, int i);
int		my_help(t_server *my_server, char **tab, int i);
int		my_width(t_server *my_server, char **tab, int i);
int		my_height(t_server *my_server, char **tab, int i);
int		my_frequence(t_server *my_server, char **tab, int i);
int		my_isnumber(char *str);
int		usage();
t_player	init_co(t_server *);
t_server	*parse_args(char **tab);
void		is_complete(t_server *server);
void		init_server(t_server *server);
void		my_free(t_server *server);
void		server_read(t_player *e, int fd, t_server *serv, t_list *player);
int		my_rand_pos(int x);
position	my_rand();
int		*get_tab(int, int, int, int);
t_list		*init_list();
void		move(int fd, t_list *player);
int		get_vision(position p);

/* CLIENT */

int		number_client(t_server *my_server, char **tab, int i);
int		client_accept(t_server *server, t_player e);
void		client_disconnect(t_list*, t_server*, t_list *);
void		client_graphic(int fd, t_server *serv);
int		is_dead(t_list *player);

/* INVENTORY */

void		remove_item_from_map(t_inv*, enum type);
void		free_inventory(t_inv*);
void		drop_item(t_inv*, t_inv*);
void		add_item(t_list*, enum type);
t_inv		*add_item_to_map(t_inv*, enum type);

/* TEAM */

int		name_team(t_server *my_server, char **tab, int i);
void		malloc_team(t_server *, char*);
int		check_team_name(t_server*, char*);
void		set_nb_client_to_team(t_server*);
int		get_remaining_client(t_server*, char*);

/* COMMANDS */

int		check_cmd(t_list *player, t_server *server,  char *buf, int fd);
int		move_forward(t_list *player, t_server *server,  char *buf, int fd);
int		turn_right(t_list *player, t_server *server,  char *buf, int fd);
int		turn_left(t_list *player, t_server *server,  char *buf, int fd);
int		look_around(t_list *player, t_server *server,  char *buf, int fd);
int		check_inventory(t_list *player, t_server *server,  char *buf, int fd);
int		speaking(t_list *player, t_server *server,  char *buf, int fd);
int		unused_slots(t_list *player, t_server *server,  char *buf, int fd);
int		fork_player(t_list *player, t_server *server,  char *buf, int fd);
int		eject_player(t_list *player, t_server *server,  char *buf, int fd);
int		death(t_list *player, t_server *server,  char *buf, int fd);
int		start_incantation(t_list *player, t_server *server,  char *buf, int fd);
void		print_ko(int, int, int, char*);

/* TAKE_SET */

int		take_linemate(t_list *player, t_server *server,  char *buf, int fd);
int		take_deraumere(t_list *player, t_server *server,  char *buf, int fd);
int		take_sibur(t_list *player, t_server *server,  char *buf, int fd);
int		take_mendiane(t_list *player, t_server *server,  char *buf, int fd);
int		take_phiras(t_list *player, t_server *server,  char *buf, int fd);
int		take_thystame(t_list *player, t_server *server,  char *buf, int fd);
int		take_apple(t_list *player, t_server *server,  char *buf, int fd);
int		set_linemate(t_list *player, t_server *server,  char *buf, int fd);
int		set_deraumere(t_list *player, t_server *server,  char *buf, int fd);
int		set_sibur(t_list *player, t_server *server,  char *buf, int fd);
int		set_mendiane(t_list *player, t_server *server,  char *buf, int fd);
int		set_phiras(t_list *player, t_server *server,  char *buf, int fd);
int		set_thystame(t_list *player, t_server *server,  char *buf, int fd);
int		set_apple(t_list *player, t_server *server,  char *buf, int fd);

#endif		/* !MY_SERVER_H_ */
