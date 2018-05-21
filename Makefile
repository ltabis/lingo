##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile for follow up stumper
##

SRC=	src/main.c	\
		src/display_rules.c	\
		src/iscaract.c	\
		src/compare_strings.c	\
		src/game_loop.c

OBJ=	$(SRC:.c=.o)

NAME=	lingo

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -W -Wall -Wextra -g

clean:
	rm -f $(NAME)

fclean:	clean
		rm -f $(OBJ)

re:	fclean all
