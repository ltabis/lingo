/*
** EPITECH PROJECT, 2018
** duostumer
** File description:
** display rules of the game
*/

#include <string.h>
#include <stdio.h>

void display_first_lines(char *word)
{
	printf("*: invalid letter\n");
	printf("?: incorrectly placed letter\n");
	printf("Will you find the secret word?\n");
	printf("%c", word[0]);
	for (unsigned int i = 2; i < strlen(word); i++)
		printf("*");
	printf("\n");
}
