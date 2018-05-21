/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** compare the string in the file with the string we write
*/

#include "../include/proto.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int compare_strings(char *word, char *input)
{
	int lenght_word = strlen(word);
	int lenght_input = strlen(input);
	char *update = strdup(word);
	int i = 0;

	for (unsigned int i = 1; update && input[i]; i++)
		update[i] = '*';
	if (lenght_word > lenght_input) {
		fprintf(stderr, "Word too short. Retry.\n");
		return (-1);
	} else if (lenght_word < lenght_input) {
		fprintf(stderr, "Word too long. Retry.\n");
		return (-1);
	}
	for (unsigned int i = 0; update && word[i]; i++)
		if (word[i] == input[i])
			update[i] = word[i];
	return (compare_same_letters(word, input, update));
}

int compare_same_letters(char *word, char *input, char *update)
{
	if (!update)
		return (-2);
	for (unsigned int i = 0; input[i]; i++)
		for (unsigned int j = 0; word[j]; j++)
			check_letter(i, word[j], input, update);
	printf("%s\n", update);
	if (strcmp(word, update) == 0) {
		free(update);
		return (1);
	}
	free(update);
	return (0);
}

void check_letter(unsigned int i, char word,
	char *input, char *update)
{
	for (unsigned int j = 0; update[j]; j++)
		if (update[j] == input[i])
			return;
	if (input[i] == word) {
		if (update[i] == '*')
			update[i] = '?';
	}
}
