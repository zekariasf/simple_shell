#include "main.h"
/**
 * tok_string - toknaiz a given string
 * @str: an input string
 * @delim: delimeter
 * Return: an array of string that contain the toknaized strins
 */
char **tok_string(char *str, char *delim)
{
	char *cop_str1 = NULL, *cop_str2 = NULL, *token;
	char **new_str;
	int count = 0, i = 0, j = 0;

	while (str[count])
		count++;
	cop_str1 = malloc(sizeof(char) * (count + 1));
	cop_str2 = malloc(sizeof(char) * (count + 1));
	if (cop_str1 == NULL || cop_str2 == NULL)
	{
		perror("cop_str");
		return (NULL);
	}
	str_cpy(cop_str1, str);
	str_cpy(cop_str2, str);
	token = strtok(cop_str1, delim);
	while (token)
	{
		i++;
		token = strtok(NULL, delim);
	}
	new_str = malloc(sizeof(char *) * (i + 1));
	if (new_str == NULL)
		return (NULL);
	token = strtok(cop_str2, delim);
	while (token)
	{
		count = 0;
		while (token[count])
			count++;
		new_str[j] = malloc(sizeof(char) * (j + 1));
		strcpy(new_str[j], token);
		j++;
		token = strtok(NULL, delim);
	}
	new_str[j] = NULL;
	free(cop_str1);
	free(cop_str2);
	return (new_str);
}
