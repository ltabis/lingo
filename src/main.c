/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../include/proto.h"

int main(int ac, char **av)
{
	char *word = NULL;

	if (ac != 2) {
		fprintf(stderr, "Wrong set of arguments, "\
			"retry with ./lingo [filename]\n");
		return (84);
	}
	srand(time(NULL));
	if (!((word = choose_random_word(av))))
		return (84);
	printf("word = %s\n", word);
	return (0);
}
