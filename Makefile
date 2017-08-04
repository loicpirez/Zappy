##
## Makefile for zappy in /home/vallae_h/Epitech/TEK2/CPP/PSU_2016_zappy
## 
## Made by vallae_h
## Login   <vallae_h@epitech.net>
## 
## Started on  Wed Jun 28 17:45:34 2017 vallae_h
## Last update Thu Jun 29 13:04:36 2017 vallae_h
##

IA_NAME=	zappy_ai

IA_SRC=		IA/main.cpp			\
		IA/print_help.cpp		\
		IA/client.cpp			\
		IA/parsing_client.cpp		\
		IA/print_error.cpp		\
		IA/is_number.cpp		\
		IA/socket.cpp 			\
		IA/protocol.cpp 		\
		IA/args.cpp

IA_OBJ=		$(IA_SRC:.cpp=.o)

++FLAGS=	-W -Wall -Wextra -Werror

zappy_ai:	$(IA_OBJ)
		g++ -o $(IA_NAME) $(IA_OBJ) $(++FLAGS)

clean_ai:
		rm IA/*.o

fclean_ai:
		rm $(IA_NAME) IA/*.o
