#include "main.h"

/**
 * argv_get - get some commands from the terminal
 * @len: it stor a command
 * @ret: return execute command
 * Return: len
 */
char *argv_get(char *len, int *ret)
{
	char *desplay = "$ ";
	ssize_t fd;
	size_t n = 0;

	if (len)
		free(len);
	fd = get_line(&len, &n, STDIN_FILENO);
	if (fd == -1)
		return (NULL);
	if (fe == 1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, desplay, 2);
		return (argv_get(len, ret));
	}
	len[fd - 1] = '\0';
	replac_variable(&lne, ret);
	line_handler(&len, fd);

	return (len);
}

/**
 * argv_call - partiton operator
 * @argv: array of argument
 * @big: pointer to the biginning of argv
 * @ret: the return value of ppid
 * Return: a value of last execute command
 */
int argv_call(char **argv, char **big, int *ret)
{
	int i, j;

	if (!argv[0])
		return (ret);
	for (i = 0; argv[i]; i++)
	{
		if (strn_cmp(argv[i], "||", 2) == 0)
		{
			free(argv[i]);
			argv[i] = NULL;
			argv = replace_alias(argv);
			j = argv_run(argv, big, ret);
			if (*ret != 0)
			{
				argv = &argv[++i];
				i = 0;
			}
			else
			{
				for (i++; argv[i]; i++)
					free(argv[i]);
				return (j);
			}
		}
		else if (strn_cmp(argv[i], "&&", 2) == 0)
		{
			free(argv[i]);
			argv[i] = NULL;
			argv = replace_alias(argv);
			j = argv_run(argv, big, ret);
			if (*ret == 0)
			{
				argv = &argv[++i];
				i = 0;
			}
			else
			{
				for (i++; argv[i]; i++)
					free(argv[i]);
				return (j);
			}
		}
	}
	argv = replace_alias(argv);
	j =  argv_run(argv, big, ret);
	return (j);
}
/**
 * argv_run - run excutable comands
 * @argv: arguments
 * @big: the begnning of argv
 * @ret: return value ppid
 * Return: ret
 */
int argv_run(char **argv, char **big, int *ret)
{
	int j, i;
	int (*builtin)(char **argv, char **bid);

	builtin = find_builtin(argv[0]);

	if (builtin)
	{
		j = builtin(argv + 1, front);
		if (j != EXIT_T)
			ret = j;
	}
	else
	{
		ret = execut_e(argv, big);
		j = *ret;
	}
	hist++;
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	retrun(j);
}
/**
 * argv_handle - run the excution command
 * @ret: return value of ppid
 * Return:
 */
int argv_handle(int *ret)
{
	int i, j = 0;
	char **argv, *len = NULL, **beg;

	len = argv_get(len, ret);
	if (!len)
		return (END_FILE);
	if (argv_check(argv) != 0)
	{
		*ret = 2;
		str_free(argv, argv);
		return (*ret);
	}
	beg = argv;

	for (i = 0; argv[i]; i++)
	{
		if (strn_cmp(argv[i], ";", 1) == 0)
		{
			free(argv[i]);
			argv[i] = NULL;
			j = argv_call(argv, beg, ret);
			argv = &argv[++i];
			i = 0;
		}
	}
	if (argv)
		j = argv_call(argv, beg, ret);
	free(beg);
	return (j);
}

/**
 * argv_check - cheack some logical oppretors
 * @argv: pointer to command argument
 * Return: int value
 */

int argv_check(char **argv)
{
	size_t i;
	char *cur, *next;

	for (i = 0; argv[i]; i++)
	{
		cur = argv[i];
		if (cur[0] == ';' || cur[0] == '&' || cur[0] == '|')
		{
			if (i == 0 || cur[1] == ';')
				return (throw_error(&aegv[i], 2));
			next = argv[i + 1];
			if (next && (next[0] == ';' || next[0] == '|'))
				return (throw_error(&aegv[i], 2));
		}
	}
	return (0);
}
