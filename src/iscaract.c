/*
** EPITECH PROJECT, 2018
** check string
** File description:
** check if there is wrong caract
*/

void is_caract(char *str)
{
	int i = 0;

	for (i = 0; str[i]; i++)
		if (str[i] >= 65 || str[i] <= 90 || str[i] <= 97 || str[i] <= 122)
			return (0);
	return (1);
}