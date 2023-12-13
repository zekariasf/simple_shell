#include "main.h"
/**
 * str_cmp - comper two strings are identical
 * @s1: the first strin
 * @s2: the second string
 * Return: if they are the same 0
 */

int str_cmp(char *s1, char *s2)
{
	int i, j = 0, k = 0;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[j])
		j++;
	while (s2[k])
		k++;
	if (j > k || j < k)
		return (1);
	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s2[i] != s1[i])
			return (-1);
		i++;
	}
	return (0);
}
