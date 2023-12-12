#include "main.h"
/**
 * str_cat - used to copy strings afret the null pointer by replecing it
 * @pest: the reciver of the data
 * @copy: input string it have the data we want to stor in pest
 */

void str_cat(char *pest, char *copy)
{
	int i = 0, j;

	if (pest != NULL)
	{
		while (pest[i])
			i++;
	}
	for (j = 0; copy[j] != '\0'; j++)
		pest[i + j] = copy[j];
	pest[i + j] = '\0';
}

/**
 * str_cpy - used to copy strings
 * @elem: input string that have the data
 * @cpy: THE reciver of the data
 */

void str_cpy(char *cpy, char *elem)
{
	int i;

	for (i = 0; elem[i]; i++)
		cpy[i] = elem[i];
	cpy[i] = '\0';
}
