#include "main.h"
/**
 * letter_identify - used to change a given character by new character
 * @word: an input word or string
 * @old_let: the priveus character the user wnat to replece
 * @new_let: the new character that is replece the old character
 * Return: a string that contain the new_let
 */

char *letter_identify(char *word, char old_let, char new_let)
{
	int i, j = 0;
	char *new_word;

	while (word[j])
		j++;
	new_word = malloc(sizeof(char) * (j + 1));
	if (new_word == NULL)
		return (NULL);
	for (i = 0; word[i] != '\0'; i++)
	{
		if (word[i] == old_let)
			new_word[i] = new_let;
		else
			new_word[i] = word[i];
	}
	new_word[i] = '\0';
	return (new_word);
}
