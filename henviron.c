#include "main.h"
/**
 * env_copy - create copy of the env't
 *
 * Return: NULL for error, o/w - a double ptr to the new copy
 */
char **env_copy(void)
{
	char **new_env;
	size_t size;
	int i;

	for (size = 0; environ[size]; size++)
		;
	new_env = malloc(sizeof(char *) * (size + 1));
	if (!new_env)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		new_env[i] = malloc(str_len(environ[i]) + 1);

		if (!new_env[i])
		{
			for (i--; i >= 0; i--)
				free(new_env[i]);
			free(new_env);
			return (NULL);
		}
		str_cpy(new_env[i], environ[i]);
	}
	new_env[i] = NULL;

	return (new_env);
}
/**
 * free_env - frees the copy of the env't
 */
void free_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		free(environ[i]);
	free(environ);
}
/**
 * get_env - gets an env'tal var from the path
 * @v: the name of the env var to get
 *
 * Return: Null if the car does not exist, otherwise a ptr to the var
 */
char **get_env(const char *v)
{
	int i, len;

	len = str_len(v);
	for (i = 0, environ[i]; i++)
	{
		if (strn_cmp(var, environ[i], len) == 0)
			return (&environ[i]);
	}

	return (NULL);
}

