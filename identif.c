#include "main.h"
/**
 * identify - checker for the given command
 * @argv: input command
 */
void identify(char **argv)
{
	if ((str_cmp(argv[0], "exit")) == 0)
		exit_shell();
	if ((str_cmp(argv[0], "env")) == 0)
		enviro_lsit();
	else
		execut(argv, environ);
}
