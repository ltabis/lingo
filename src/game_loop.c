/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** game loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/proto.h"

char *choose_random_word(char **av)
{
	FILE *stream = fopen(av[1], "r");
	char *line = NULL;
	size_t len = 0;
	unsigned int nbr_words = 0;

	if (!stream)
		return (NULL);
	while (getline(&line, &len, stream) != -1)
		nbr_words++;
	free(line);
	line = NULL;
	fclose(stream);
	if (!(stream = fopen(av[1], "r")))
		return (NULL);
	nbr_words = rand() % nbr_words;
	for (unsigned int i = 0; getline(&line, &len, stream) != -1 &&
	i < nbr_words; i++);
	fclose(stream);
	return (line);
}

int start_game_loop(char *word)
{
	char *line = NULL;
	size_t len = 0;
	const unsigned int word_len = strlen(word);
	unsigned int i = 2;

	display_first_lines(word);
	printf("Round %i\n>", 1);
	for (; i < word_len &&
	getline(&line, &len, stdin) != -1 && line; i++) {
		printf("Round %i>\n", i);
	}
	if (word_len == i)
		printf("You lost!\n");
	else
		printf("You won!\n");
}
