#include "main.h"

/**
 * location_find - locate commands
 * @command: command
 * Return: path name of thee command
 */
char *location_find(char *command)
{
	char **path, *temp;
	list_t *dire, *input;
	struct stat st;

	path = get_env("PATH");
	if (!path || !(*path))
		return (NULL);
	dire = path_get(*path + 5);
	input = dire;
	while (dire)
	{
		temp = malloc(str_len(dire->dir) + str_len(command) + 2);
		if (!temp)
			return (NULL);
		str_cpy(temp, dire->dir);
		str_cat(temp, "/");
		str_cat(temp, command);
		if (stat(temp, &st) == 0)
		{
			list_free(input);
			return (temp);
		}
		dire = dire->next;
		free(temp);
	}
	list_free(input);
	return (NULL);
}
/**
 * path_finde - replace trailing colons with PWD
 * @command: direction
 * Return: copy of path
 */
char *path_finde(char *command)
{
	char *pwd, com_copy;
	int i, len = 0;

	pwd = *(get_env("PWD")) + 4;
	for (i = 0; command[i]; i++)
	{
		if (command[i] == ':')
		{
			if (command[i + 1] == ':' || i == 0
				|| path[i + 1] == '\0')
				len += str_len(pwd) + 1;
			else
				len++;
		}
		else
			len++;
	}
	com_copy = malloc(sizeof(char) * (leen + 1));
	if (com_copy == NULL)
		return (NULL);
	com_copy[0] = '\0';
	for (i = 0; command[i]; i++)
	{
		if (command[i] == ':')
		{
			if (i == 0)
			{
				str_cat(com_copy, pwd);
				str_cat(com_copy, ":");
			}
			else if (command[i + 1] == ':' ||
					command[i + 1] == '\0')
			{
				str_cat(com_copy, ":");
				str_cat(com_copy, pwd);
			}
			else
				str_cat(com_copy, ":");
		}
		else
		{
			strn_cat(com_copy, &command[i], 1);
		}
	}
	return (com_copy);
}

/**
 * path_get - tokinze colon separetor
 * @command: list of direction
 * Return: intialized linked list
 */
list_t *path_get(char *command)
{
	int i;
	list_t *input = NULL;
	char *com_copy, **dire;

	com_copy = path_finde(command);
	if (!com_copy)
		return (NULL);
	dire = str_tok(com_copy, ":");
	free(com_copy);
	if (!dire)
		return (NULL);
	for (i = 0; dire[i]; i++)
	{
		if (node_add(&input, dire[i]) == NULL)
		{
			list_free(input);
			free(dire);
			return (NULL);
		}
	}
	free(dire);
	return (input);
}
}
