#include "main.h"

/**
 * open_fel - lacks proper permissions
 * @path_file: path name of the command
 * Return:  127
 */
int open_fel(char *path_file)
{
	char *hist_str, *ero;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (127);
	len = str_len(name) + str_len(hist_str) + str_len(path_file) + 16;
	ero = malloc(sizeof(char) * (len + 1));
	if (ero == NULL)
	{
		free(hist_str);
		return (127);
	}
	str_cpy(ero, name);
	str_cat(ero, ":");
	str_cat(ero, hist_str);
	str_cat(ero, ": can't open");
	str_cat(ero, path_file);
	str_cat(ero, "\n");

	free(hist_str);
	write(STDERR_FILENO, ero, len);
	free(ero);
	return (127);
}
/**
 * file_command - run commands
 * @path_file: file name
 * @exe:  return value
 * Return: the value of last command reun or exe
 */
int file_command(char *path_file, int *exe)
{
	ssize_t fd_o, fd_r, i;
	unsigned int len_new = 0, len_old = 120;
	char *len, **argv, **beg;
	char buf[120];
	int j;

	hist = 0;
	fd_o = open(path_file, O_RDONLY);
	if (fd_o == -1)
	{
		*exe = open_fel(path_file);
		return (*exe);
	}
	len = malloc(sizeof(char) * len_old);
	if (!len)
		return (-1);
	do {
		fd_r = read(fd_o, buf, 119);
		if (fd_r == 0 && len_new == 0)
			return (*exe);
		buf[fd_r] = '\0';
		len_new += fd_r;
		len = re_alloc(len, len_old, len_new);
		str_cat(len, buf);
		len_old = len_new;
	} while (fd_r);
	for (i = 0; len[i] == '\n'; i++)
		len[i] = ' ';
	for (; i < len_new; i++)
	{
		if (len[i] == '\n')
		{
			len[i] = ';';
			for (i += 1; i < len_new && len[i] == '\n'; i++)
				len[i] = ' ';
		}
	}
	replac_variable(&len, exe);
	line_handler(&len, len_new);
	argv = str_tok(len, " ");
	free(len);
	if (!argv)
		return (0);
	if (check_argv(argv) != 0)
	{
		*exe = 2;
		str_free(argv, argv);
		return (*exe);
	}
	beg = argv;

	for (i = 0; argv[i]; i++)
	{
		if (strn_cmp(argv[i], ";", 1) == 0)
		{
			free(argv[i]);
			argv[i] = NULL;
			j = argv_call(argv, beg, exe);
			argv = &argv[++i];
			i = 0;
		}
	}
	j = argv_call(argv, beg, exe);

	free(beg);
	return (j);
}
