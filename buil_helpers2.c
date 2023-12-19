#include "main.h"
/**
 * call_env - displays information on the hshell builtin cmd 'env'
 */
void call_env(void)
{
	char *info = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, info, str_len(info));
}
/**
 * call_setenv - displays information on the hshell builtin cmd 'setenv'
 */
void call_setenv(void)
{
	char *info = "setenv: setenv [VARIABLE] [VALUE] \n\tInitia;lizes anew";

	write(STDOUT_FILENO, info, str_len(info));
	info = "environment variable, or modifies an existing one.\n";
	write(STDOUT_FILENO, info, str_len(info));
	info = "\tOn failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, info, str_len(info));
}
/**
 * call_unsetenv - displays information on the hshell builtin cmd 'unseten
 * v'
 */
void call_unsetenv(void)
{
	char *info = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, info, str_len(info));
	info = "environmental variable.\n\n\ton failure prints ";
	write(STDOUT_FILENO, info, str_len(info));
	info = "message to stderr.\n";
	write(STDOUT_FILENO, info, str_len(info));
}
