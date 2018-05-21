/*
** EPITECH PROJECT, 2018
** duostumer
** File description:
** display rules of the game
*/

void main(void)
{
	printf("*: invalid letter\n");
	printf("?: incorrectly placed letter\n");
	printf("Will you find the secret word?\n");
	printf("%c", word[0]);
	for (int i = 1; i < strlen(word); i++)
		printf("*");
	printf("\n");
}
