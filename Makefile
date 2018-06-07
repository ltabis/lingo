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

CFLAGS=	-W -Wall -Wextra -g -Iinclude

NAME=	lingo

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(NAME)

fclean:	clean
		rm -f $(OBJ)

re:	fclean all
