#include "main.h"
/**
 * perm_err - creates an error message for denied permissions
 * @av: array of arguments to the command
 *
 * Return: Error string
 */
char *perm_err(char **av)
{
	char *err, *h_str;
	int l;

	h_str = _itoa(hist);
	if (!h_str)
		return (NULL);

	l = str_len(name) + str_len(h_str) + str_len(av[0]) + 24;
	err = malloc(sizeof(char) * (l + 1));
	if (!err)
	{
		free(h_str);
		return (NULL);
	}

	str_cpy(err, name);
	str_cat(err, ": ");
	str_cat(err, h_str);
	str_cat(err, ": ");
	str_cat(err, av[0]);
	str_cat(err, ": Permission denied\n");

	free(h_str);
	return (err);

}
/**
 * cmd_err - creates an error message for cmd not found errors
 * @av: array of arguments to the command
 *
 * Return: Error string
 */
char *cmd_err(char **av)
{
	char *err, *h_str;
	int l;

	h_str = _itoa(hist);
	if (!h_str)
		return (NULL);

	l = str_len(name) + str_len(h_str) + str_len(av[0]) + 16;
	err = malloc(sizeof(char) * (l + 1));
	if (!err)
	{
		free(h_str);
		return (NULL);
	}


	str_cpy(err, name);
	str_cat(err, ": ");
	str_cat(err, h_str);
	str_cat(err, ": ");
	str_cat(err, av[0]);
	str_cat(err, ": not found\n");

	free(h_str);
	return (err);
}
