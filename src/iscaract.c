/*
** EPITECH PROJECT, 2018
** check string
** File description:
** check if there is wrong caract
*/

#include <stdio.h>

int is_caract(const char *str)
{
	for (unsigned int i = 0; str[i]; i++)
		if (str[i] != '\n' && (str[i] < 65 || (str[i] > 90 &&
		str[i] < 97) || str[i] > 122)) {
			fprintf(stderr, "%s isn't a word\n", str);
			return (-1);
		}
	return (0);
}
