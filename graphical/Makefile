##
## Makefile for rush in /home/loic/EPITECH/cpp_gkrellm
## 
## Made by Loïc Pirez
## Login   <loic.pirez@epitech.eu>
## 
## Started on  Sun Jan 22 05:43:08 2017 Loïc Pirez
## Last update Sun Jul  2 23:55:37 2017 Loïc Pirez
##

CC		=	g++

NAME		=	client

SRC_DIR 	=	src/

SRC		=	$(SRC_DIR)Create.cpp \
			$(SRC_DIR)Draw.cpp \
			$(SRC_DIR)Main.cpp \
			$(SRC_DIR)Player.cpp \
			$(SRC_DIR)Map.cpp \
			$(SRC_DIR)Case.cpp \
			$(SRC_DIR)Loot.cpp \
			$(SRC_DIR)Window.cpp \
			$(SRC_DIR)Parse.cpp

OBJ		=	$(SRC:.cpp=.o)

FLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -lpthread

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean		:
			rm -f $(SRC:.cpp=.o)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all

.cpp.o	:
			$(CC) $(FLAGS) -c $< -o $@
