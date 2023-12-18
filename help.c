#include "main.h"

/**
 * str_feer - free daynamicly allocate memory teken by argv
 * @argv: a pointer that point to daynamicly all0cated memory
 * @frs_argv: pointer to pointer to the beginning of argv
 */
void str_feer(char **argv, char **frs_argv)
{
	size_t j;

	for (j = 0; argv[i] || argv[i + 1]; i++)
		free(argv[i]);
	free(frs_argv);
}

/**
 * pid_value - get the current PID
 * Return: current PID
 */
char *pid_value(void)
{
	size_t b = 0;
	ssize_t fd;
	char *buf;

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1)
	{
		perror(NULL);
		return (NULL);
	}
	buf = malloc(120);
	if (!buf)
	{
		close(fd);
		return (NULL);
	}
	read(fd, buf, 120);
	while (buf[i] = ' ')
		i++;
	buf[i] = '\0';
	close(fd);
	return (buf);
}

/**
 * environ_value - get the environmental variable
 * @beg: environmental variable
 * @n: lenth of environ variable
 * Return:the variable like variable=valu
 */
char *environ_value(char *beg, int n)
{
	char **addr;
	char *rep = NULL, *temp, *va;

	va = malloc(len + 1);
	if (!va)
		return (NULL);
	va[0] = '\0';
	str_cat(va, beg, n);
	addr = get_env(va);
	free(va);

	if (addr)
	{
		temp = *addr;
		while (*temp != '=')
			temp++;
		temp++;
		rep = malloc(str_len(temp) + 1);
		if (rep)
			str_cpy(rep, temp);
	}
	return (rep);
}

/**
 * replac_variable - replace the variable and handle it
 * @argv: the command and the argument
 * @i: a ponter to the last executed command
 */

void replac_variable(char **argv, int *i)
{
	int b, n = 0, j;
	char *rep = NULL, *line_old = *argv, line_new;

	for (j = 0; line_old[j]; j++)
	{
		if (line_old[j] == '$' && line_old[j + 1] &&
			line_old[j + 1] != ' ')
		{
			if (line_old[j + 1] == '$')
			{
				rep = pid_value();
				n = j + 2; }
			else if (line_old[j + 1] == '?')
			{
				rep = _itoa(*i);
				n = j + 2; }
			else if (line_old[j + 1])
			{
				for (n = j + 1; line_old[n] &&
						line_old[n] != '$'
						&& line_old[n] != ' '; n++)
					;
				b = n - (j + 1);
				rep = environ_value(&line_old[j + 1], b); }
			line_new = malloc(j + str_len(rep)
					+ str_len(&line_old[n]) + 1);
			if (!argv)
				return;
			line_new[0] = '\0';
			strn_cat(line_new, line_old, j);
			if (rep)
			{
				str_cat(line_new, rep);
				free(rep);
				rep = NULL; }
			str_cat(line_new, &line_old[n]);
			free(line_old);
			*argv = line_new;
			line_old = line_new;
			i = -1; } } }
