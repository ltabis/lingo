/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** game loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proto.h"

char *choose_random_word(char **av)
{
	FILE *stream = fopen(av[1], "r");
	char *line = NULL;
	size_t len = 0;
	unsigned int nbr_words = 0;

	if (!stream)
		return (NULL);
	for (; getline(&line, &len, stream) != -1; nbr_words++)
		if (is_caract(line) == -1)
			return (NULL);
	free(line);
	line = NULL;
	fclose(stream);
	if (!(stream = fopen(av[1], "r")) || nbr_words == 0)
		return (NULL);
	nbr_words = rand() % nbr_words;
	for (unsigned int i = 0; getline(&line, &len, stream) != -1 &&
	i < nbr_words; i++);
	fclose(stream);
	return (line);
}

void start_game_loop(char *word)
{
	char *line = NULL;
	size_t len = 0;
	const unsigned int word_len = strlen(word);
	unsigned int i = 1;
	int ret = 0;

	display_first_lines(word);
	for (size_t rd = 1; i < word_len && rd > 0 &&
	ret < 1 && ret != -2; i++) {
		display_prompt(ret, i);
		rd = getline(&line, &len, stdin);
		ret = compare_strings(word, line);
		i -= ret == -1 ? 1 : 0;
	}
	if (line)
		free(line);
	if (ret != 1)
		printf("You lost!\n");
	else if (ret == 1)
		printf("You won!\n");
}

void display_prompt(int ret, unsigned int i)
{
	if (ret != -1)
		printf("Round %i\n>", i);
	else
		printf(">");
}
