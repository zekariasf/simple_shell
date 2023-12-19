#include "main.h"
/**
 * str_chr - Locates a character in a string
 * @str: The string to be searched
 * @c: The char to be located
 *
 * Return: a ptr to the 1st occurence if c is found
 * NULL otherwise
 */
char *str_chr(char *str, char c)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == c)
			return (str + i);
	}
	return (NULL);
}
/**
 * strn_cmp - compare string
 * @str1: ptr to string
 * @str2: ptr to string
 * @n: first n bytes of the string to compare
 *
 * Return: <0 if str1 is shorter than str2
 * 0 if the strings match
 * >0 if str1 is longer than str2
 */
int strn_cmp(const char *str1, const char *str2, size_t n)
{
	size_t t;

	for (t = 0; str1[t] && str2[t] && t < n; t++)
	{
		if (str1[t] > str2[t])
			return (str1[t] - str2[t]);
		else if (str1[t] - str2[t])
			return (str1[t] - str2[t]);
	}
	if (t == n)
		return (0);
	else
		return (-15);
}

/**
 * str_cmp - comapres strings
 * @str1: ptr to string
 * @str2: ptr to string
 * Return: +ve bytes diff if str1 > str2
 * 0 if str1 = str2
 * -ve diff if str1 < str2
 */
int str_cmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);

	return (0);
}

/**
* str_spn - Gets the length of a prefix substring
* @str: String to be searched
* @a: prefix to be measured
*
* Return: Number of bytes in str
*/

int str_spn(char *str, char *a)
{
	int b = 0;
	int i;

	while (*str)
	{
		for (i = 0; a[i]; i++)
		{
			if (*str == a[i])
			{
				b++;
				break;
			}
		}
		str++;
	}
	return (b);
}
