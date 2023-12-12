#include "main.h"
/**
 * full_path - return the full path of the str(command)
 * @str: input command
 * Return: the full path of str
 */
char *full_path(char *str)
{
	char *path, *cpy_environ, *token, *file_path;
	int i = 0, j = 0, k = 0;
	struct stat buffer;

	path = getenv("PATH");
	while (path[k])
		k++;
	cpy_environ = malloc(sizeof(char) * (k + 1));
	if (cpy_environ == NULL)
		return (NULL);
	str_cpy(cpy_environ, path);
	while (str[i])
		i++;
	token = strtok(cpy_environ, ":");
	while (token)
	{
		while (token[j])
			j++;
		file_path = malloc(i + j + 2);
		str_cpy(file_path, token);
		str_cat(file_path, "/");
		str_cat(file_path, str);
		str_cat(file_path, "\0");
		if (stat(file_path, &buffer) == 0)
		{
			free(cpy_environ);
			return (file_path);
		}
		else
		{
			free(file_path);
			token = strtok(NULL, ":");
		}
	}
	free(cpy_environ);
	if (stat(str, &buffer) == 0)
		return (str);
	return (NULL);
}
