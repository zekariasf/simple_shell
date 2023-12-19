#include "main.h"
/**
 * hshell_env - Prints environmet
 * @av: array of arguments
 * @start: a double pointer to the beggining of av
 *
 * Return: -1 for error, 0 otherwise
 */
int hshell_env(char **av, char __attribute__((__unused__)) **start)
{
	int i;
	char c = '\n';

	if (!environ)
		return (-1);
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], str_len(environ[i]));
		write(STDOUT_FILENO, &c, 1);
	}
	(void)av;
	return (0);
}

/**
 * hshell_setenv - Changs/adds envtal var to the PATH
 * @av: array of arguments
 * @start: a double pointer to the beggining of av
 *
 * Return: -1 for error, 0 otherwise
 */
int hshell_setenv(char **av, char __attribute__((__unused__)) **start)
{
	char **env_v = NULL, **new_env, *new_val;
	size_t size;
	int i;

	if (!av[0] || !av[1])
		return (throw_error(av, -1));

	new_val = malloc(str_len(av[0]) + 1 + str_len(av[1]) + 1);
	if (!new_val)
		return (throw_error(av, -1));
	str_cpy(new_val, av[0]);
	str_cpy(new_val, "=");
	str_cpy(new_val, av[1]);

	env_v = get_env(av[0]);
	if (env_v)
	{
		free(*env_v);
		*env_v = new_val;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;

	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
	{
		free(new_val);
		return (throw_error(av, -1));
	}

	for (i = 0; environ[i]; i++)
		new_env[i] = environ[i];

	free(environ);
	environ = new_env;
	environ[i] = new_val;
	environ[i + 1] = NULL;

	return (0);
}
/**
 * hshell_unsetenv - Removes an enirtal var from the PATH
 * @av: array of argumrents
 * @start: a double pointer to the beggining of av
 *
 * Return: -1 for error, 0 otherwise
 */
int hshell_unsetenv(char **av, char __attribute__((__unused__)) **start)
{
	char **env_v, **new_env;
	size_t size;
	int i, j;

	if (!av[0])
		return (throw_error(av, -1));
	env_v = get_env(av[0]);
	if (!env_v)
		return (0);

	for (size = 0; environ[size]; size++)
		;
	new_env = malloc(sizeof(char *) * size);
	if (!new_env)
		return (throw_error(av, -1));

	for (i = 0, j = 0; environ[i]; i++)
	{
		if (*env_v == environ[i])
		{
			free(*env_v);
			continue;
		}
		new_env[i] = environ[i];
		j++;
	}
	free(environ);
	environ = new_env;
	environ[size - 1] = NULL;

	return (0);
}
