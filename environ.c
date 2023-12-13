#include "main.h"
/**
 * enviro_lsit - a bulit in command used to list enviromental variables
 */

void enviro_lsit(void)
{
	int i, j;
	char *env_cop;

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		while (environ[i][j])
			j++;
		env_cop = malloc(sizeof(char) * (j + 1));
		if (env_cop == NULL)
		{
			perror("NULL");
			return;
		}
		str_cpy(env_cop, environ[i]);
		write(1, env_cop, (j + 1));
		write(1, "\n", 1);
		free(env_cop);
	}
}
