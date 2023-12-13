#include "main.h"
/**
 * main - a shell program
 * @av: an input strings given from the users
 * @ac: number of string tha pass from the users
 * Return: on success 0
 */

int main(int ac __attribute__((unused)), char *av[])
{
	char *lineptr = NULL, *cop_lineptr;
	size_t n = 0;
	int mode = 1;

	while (mode)
	{
		mode = isatty(STDIN_FILENO);
		write(1, "($) ", 5);
		if (getline(&lineptr, &n, stdin) == -1)
			perror("./hsh");
		cop_lineptr = letter_identify(lineptr, '\n', '\0');
		av = tok_string(cop_lineptr, " ");
		identify(av);
		free(av);
		free(cop_lineptr);
	}

	free(lineptr);
	return (0);
}
