/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** compare the string in the file with the string we write
*/

void compare_strings(char *word, char *input)
{
	int lenght_word = strlen(word);
	int lenght_input = strlen(input);
	char *update = strdup(word);
	int i = 0;

	for (unsigned int i = 1; input[i]; i++)
		update[i] = '*';
	if (lenght_word > lenght_input)
		write(2, "Word too short. Retry.\n", 23);
	else if (lenght_word < lenght_input)
		write(2, "Word too long. Retry.\n", 22);
	for (unsigned int i = 0; word[i]; i++)
		if (word[i] == input[i])
			update[i] = word[i];
}