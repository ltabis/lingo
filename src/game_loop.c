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
	unsigned int i = 1;

	display_first_lines(word);
	for (size_t rd = 0; i < word_len && rd != -1; i++) {
		printf("Round %i\n>", i);
		rd = getline(&line, &len, stdin);
		compare_strings(word, line);
	}
	if (line)
		free(line);
	if (word_len == i)
		printf("You lost!\n");
	else
		printf("You won!\n");
}
