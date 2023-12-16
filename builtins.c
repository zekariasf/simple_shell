#include "main.h"
/**
 * find_builtin - matches a command with a corresponding
 *			shell_buil function
 * @cmd: The command to match
 * Return: A function pointer
 */
int (*find_builtin(char *cmd))(char **args, char **start)
{
	builtin_t func[] = {
		{ "exit", shell_exit },
		{ "env", shell_env },
		{ "setenv", shell_env },
		{ "unsetenv", shell_unsetenv },
		{ "cd", shell_cd },
		{ "alias", shell_alias },
		{ "help", shell_help },
		{ NULL, NULL }
	};
	int a;

	for (a = 0; func[a].name; a++)
	{
		if (str_cmp(funcs[a].name, cmd) == 0)
			break;
	}
	return (func[a].f);
}
/**
 * hshell_exit - normal termination
 * @args: array of arguments containing the exit value
 * @start: a double pointer to the begining of args.
 *
 * Return: -3 for no arguments
 * -2 for invalid exit value
 * o/w - exits with the given status value
 */
int hshell_exit(char **args, char **start)
{
	int a, len_i = 10;
	unsigned int n = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			a = 1;
			len_i++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= len_i && args[0][a] >= '0' && args[0][a] <= '9')
				n = (n * 10) + (args[0][a] - '0');
			else
				return (create_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (n > max - 1)
		return (create_error(--args, 2));
	args -= 1;
	free_args(args, front);
	free_env();
	free_alias_list(aliases);
	exit(n);
}
/**
 * hshell_cd - changes the current director of the shell process.
 * @args: an array of arguments
 * @start: a double poiter to the begining of args
 *
 * Return: -2 if the given string is not a directory
 * -1 if an error occurs
 * otherwise 0
 */
int hshell_cd(char **args, char __attribute__((__unused__)) **start)
{
	char **dir_i, *new_line = "\n";
	char *prpwd = NULL, *pwd = NULL;
	struct stat dir;

	prpwd = getcwd(prpwd, 0);
	if (!prpwd)
		return (-1);

	if (args[0])
	{
		if (*(args[0]) == '-' || str_cmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (get_env("OLDPWD") != NULL)
					(chdir(*get_env("OLDPWD") + 7));
			}
			else
			{
				free(prpwd);
				return (create_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(prpwd);
				return (create_error(args, 2));
			}
		}
	}
	else
	{
		if (get_env("HOME") != NULL)
			chdir(*(get_env("HOME")) + 5);
	}

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);
	dir_i = malloc(sizeof(char *) * 2);
	if (!dir_i)
		return (-1);

	dir_i[0] = "OLDPWD";
	dir_i[1] = prpwd;
	if (shell_setenv(dir_i, dir_i) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, pwd, str_len(pwd));
		write(STDOUT_FILENO, new_line, 1);
	}
	free(prpwd);
	free(pwd);
	free(dir_i);
	return (0);
}
/**
 * hshell_help - displays info about builtin shell commands
 * @args: array of arguments
 * @start: a pointer to the begining of args
 *
 * Return: -1 if an error occurs, 0 otherwise
 */
int hshell_help(char **args, char __attribute__((__unused__)) **start)
{
	if (!args[0])
		call_hall();
	else if (str_cmp(args[0], "alias") == 0)
		call_alias();
	else if (str_cmp(args[0], "cd") == 0)
		call_cd();
	else if (str_cmp(args[0], "exit") == 0)
		call_exit();
	else if (str_cmp(args[0], "env") == 0)
		call_env();
	else if (str_cmp(args[0], "setenv") == 0)
		call_setenv();
	else if (str_cmp(args[0], "unsetenv") == 0)
		call_unsetenv();
	else if (str_cmp(args[0], "help") == 0)
		call_help();
	else
		write(STDERR_FILENO, name, str_len(name));

	return (0);
}
