#include "main.h"

/**
 * handle_signal - handling of an input signal
 * sig - input signal
 */
void handle_signal(int sig)
{
	char *prompt = "\n$";

	(void)sig;
	signal(SIGINT, handle_signal);
	write(STDIN_FILENO, prompt, 3);
}
/**
 * execut_e - executr commands
 * @argv: array of argument
 * @beg: the beginninf of argv
 * Return: exit value
 */
int execut_e(char **argv, char **beg)
{
	pid_t ch_pid;
	int stu, flat = 0, i = 0;
	char *command = argv[0];

	if (command[0] != '/' && command[0] != '.')
	{
		flat = 1;
		command = location_find(command);
	}
	if (!command || (access(command, F_OK) == -1))
	{
		if (erron == EACCES)
			i = (throw_error(argv, 126));
		else
			i = (throw_error(argv, 127));
	}
	else
	{
		ch_pid = fork();
		if (ch_pid == -1)
		{
			if (flat)
				free(command);
			perror("Error ch_pid:");
			return (1);
		}
		if (ch_pid == 0)
		{
			execve(command, argv, environ);
			if (erron == EACCES)
				i = (throw_error(argv, 126));
			free_env();
			str_free(argv, flat);
			alias_free(aliases);
			_exit(i);
		}
		else
		{
			wait(&stu);
			i = WEXITSTATUS(stu);
		}
	if (flat)
		free(command);
	return (i);
}
/**
 * main - simple shall
 * @argv: input arguments
 * @argc: number of arguments
 * Return: string
 */
int main(int argc, char *argv[])
{
	int i = 0, j;
	int *exe = &i;
	char *prompt = "$ ", *new_li = "\n";

	name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, handle_signal);

	*exe = 0;
	environ = copy_env();
	if (!environ)
		exit(-100);
	if (argc != 1)
	{
		i = file_command(argv[1], exe);
		free_env();
		alias_free(aliases);
		return (*exe);
	}
	if (!isatty(STDIN_FILENO))
	{
		while (i != END_FILE || i == EXIT)
			i = argv_handle(exe);
		free_env();
		alias_free(aliases);
		return (*exe);
	}
	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		i = argv_handle(exe);
		if (i == END_FILE || i == EXIT)
		{
			if (i == END_FILE)
				write(STIDOUT_FILENO, new_li, 1);
			free_env();
			alias_free(aliases);
			exit(*exe);
		}
	}
	free_env();
	alias_free(aliases);
	return (*exe);
}
