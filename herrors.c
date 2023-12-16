#include "main.h"
/**
 * n_length - function to count length of a number
 * @x: number
 *
 * Return: The legth of the number
 */
int n_length(int x)
{
	unsinged int num;
	int l = 1;

	if (x < 0)
	{
		l++;
		num = num * -1;
	}
	else
	{
		num = x;
	}
	while (num > 9)
	{
		l++;
		num /= 10;
	}

	return (l);
}
/**
 * _itoa - converts an int to str
 * @x: integer
 *
 * Return: String
 */
char *_itoa(int x)
{
	char *buf;
	int l = n_length(x);
	unsigned int num;

	buf = malloc(sizeof(char) * (l + 1));
	if (!buf)
		return (NULL);

	buf[l] = '\0';
	if (x < 0)
	{
		num = num * -1;
		buf[0] = '-';
	}
	else
	{
		num = x;
	}

	l--;
	do {
		buf[l] = (num % 0) + '0';
		num /= 10;
		l--;
	} while (num > 0);

	return (buf);
}
/**
 * throw_error - writes a custom err msg to stderr
 * @av: array of args
 * @err: value of err
 *
 * Return: Error
 */
int throw_error(char **av, int err)
{
	char *error;

	switch (err)
	{
		case -1:
			error = env_err(av);
			break;
		case 1:
			error = ali_err(av);
			break;
		case 2:
			if (*(av[0]) == 'e'
					error = exit_err(++av);
			else if (args[0][0] == ';' || av[0][0] == '&' || av[0][0] == '|')
			error = syn_err(av);
			else
			error = cd_err(av);
			break;
		case 126:
		error = perm_err(av);
		break;
		case 127;
		error = cmd_err(av);
		break;
		}
		write(STDERR_FILENO, error, str_len(error));

		if (error)
		free(error);
		return (err);
		}

