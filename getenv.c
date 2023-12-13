#include "main.h"
/**
 * get_env - get an input environment
 * @env_name: name of the environment
 * Return: the valur of the input rnvironment
 */
char *get_env(char *env_name)
{
	int i, j, sta;

	for (i = 0; environ[i] != NULL; i++)
	{
		sta = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (env_name[j] != environ[i][j])
			{
				sta = 0;
				break;
			}
		}
		if (sta)
		{
			return (&environ[i][j + 1]);
		}
	}
	return (NULL);
}
