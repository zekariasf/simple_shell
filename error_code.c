#include "main.h"
/**
 * env_err - creates an error message for hshell env errors
 * @av: array of arguments to the command
 *
 * Return: Error string
 */
char *env_err(char **av)
{
	char **err, *h_str;
	int l;

	h_str = _itoa(hist);
	if (!h_str)
		return (NULL);

	av--;
	l = str_len(name) + str_len(h_str) + str_len(args[0]) + 45;
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
	str_cat(err, ": Unable to add/remove from environment\n");

	free(h_str);
	return (err);

}
/**
 * ali_err - creates an error message for the hshell alias errors
 * @av: array of arguments to the command
 *
 * Return: Error string
 */
char ali_err(char **av)
{
	char **err;
	int l;

	l = str_len(name) + str_len(av[0]) + 13;
	err = malloc(sizeof(char) * (l + 1));
	if (!err)
		return (NULL);


	str_cpy(err, "alias: ");
	str_cat(err, av[0]);
	str_cat(err, " not found\n");

	return (error);
}
/**
 * exit_err - creates an error message for the hshell alias errors
 * @av: array of arguments to the command
 *
 * Return: Error string
 */
char *exit_err(char **av)
{
	char *err, *h_str;
	int l;

	h_str = _itoa(hist);
	if (!h_str)
		return (NULL);

	l = str_len(name) + str_len(h_str) + str_len(av[0]) + 27;
	err = malloc(sizeof(char) * (l + 1));
	if (!err)
	{
		free(h_str);
		return (NULL);
	}


	str_cpy(err, name);
	str_cat(err, ": ");
	str_cat(err, h_str);
	str_cat(err, ": exit: Illegal number: ");
	str_cat(err, av[0]);
	str_cat(err, "\n");

	free(h_str);
	return (err);
}

/**
 * cd_err - creates an error message for the hshell alias errors
 * @av: array of arguments to the command
 *
 * Return: Error string
 */
char *cd_err(char **av)
{
	char **err, *h_str;
	int l;

	h_str = _itoa(hist);
	if (!h_str)
		return (NULL);

	if (av[0][0] == '-')
		av[0][2] = '\0';
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
	if (av[0][0] == '-')
		str_cat(err, ": cd: Invalid option ");
	else
		str_cat(err, ": cd: can't cd to ");
	str_cat(err, av[0]);
	str_cat(err, "\n");

	free(h_str);
	return (err);
}
/**
 * syn_err - creates an error message for the hshell alias errors
 * @av: array of arguments to the command
 *
 * Return: Error string
 */
char *syn_err(char **av)
{

	char **err, *h_str;
	int l;

	h_str = _itoa(hist);
	if (!h_str)
		return (NULL);

	l = str_len(name) + str_len(h_str) + str_len(av[0]) + 33;
	err = malloc(sizeof(char) * (l + 1));
	if (!err)
	{
		free(h_str);
		return (NULL);
	}

	str_cpy(err, name);
	str_cat(err, ": ");
	str_cat(err, h_str);
	str_cat(err, ": Syntax error: \"");
	str_cat(err, av[0]);
	str_cat(err, "\" unexpected\n");

	free(h_Str);
	return (err);
}
