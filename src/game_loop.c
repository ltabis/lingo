/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** game loop
*/

#include <stdio.h>
#include <stdlib.h>

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
