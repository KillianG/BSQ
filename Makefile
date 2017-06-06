##
## Makefile for Makefile in /home/gardah_k/CPool_bistro-matic
##
## Made by Killian Gardahaut
## Login   <gardah_k@epitech.net>
##
## Started on  Thu Mar 30 08:46:53 2017 Killian Gardahaut
## Last update Tue Apr  4 18:16:05 2017 Killian Gardahaut
##

NAME	= bsq

SRC	= main.c	\
	  bomb_squad.c	\
	  utils.c	\
	  my_putchar.c	\
	  set_size.c

OBJ	= $(SRC:.c=.o)

CC	= gcc -o $(NAME) -Wall -Wextra -Werror -O3

RM	= rm -f

$(NAME):
	$(CC) $(SRC)

all:	$(NAME)

debug:	$(CC) -g3

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
