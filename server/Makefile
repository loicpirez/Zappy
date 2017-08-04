##
## Makefile for zappy in /home/zaczyk_a/TEK2/server_zappy
##
## Made by Antoine Zaczyk
## Login   <antoine.zaczyk@epitech.eu>
##
## Started on  Tue Jun 27 16:00:58 2017 Antoine Zaczyk
## Last update Mon Jul  3 01:36:54 2017 Antoine Zaczyk
##

NAME	= 	zappy_server

CC	= 	gcc

RM	= 	rm -f

SRCS	= 	source/main.c		\
		source/error.c		\
		source/parsing.c	\
		source/arguments.c	\
		source/arguments2.c	\
		source/tools.c		\
		source/my_free.c	\
		source/client_accept.c	\
		source/init_co.c	\
		source/teams.c		\
		source/disconnect.c	\
		source/my_rand.c	\
		source/list_map.c	\
		source/map.c		\
		source/commands.c	\
		source/commands2.c	\
		source/commands3.c	\
		source/inventory.c	\
		source/inventory2.c	\
		source/take_set.c	\
		source/take_set2.c	\
		source/take_set3.c	\
		source/client_graphic.c	\
		source/tools_graphic.c	\
		source/move.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS 	= 	-Iinclude
CFLAGS 	+= 	-W -g

all	:	$(NAME)	$(NAME2)

$(NAME)	: 	$(OBJS)
	 	$(CC) $(OBJS) -o $(NAME)

clean	:
		$(RM) $(OBJS)
		$(RM) $(OBJS2)

fclean	: 	clean
		$(RM) $(NAME)
		$(RM) $(NAME2)

re	:	fclean all

.PHONY	: 	all clean fclean re
