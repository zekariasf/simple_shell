#include "main.h"

/**
 * re_alloc - used to reallocate a given located memory
 * @str: pointer that point to the privously dynamicl allcated mempry
 * @old: it tels how may biter str allcoated in the privously
 * @news: the nwe size that we went reallocat
 * Return: if news = 0 && str is not NULL return NULL, if news = old return str
 *		else return newly reallocated memory.
 */

void *re_alloc(void *str, unsigned int old, unsigned int news)
{
	char *cop_str, *filter;
	void *mer;
	unsigned int i;

	if (news == old)
		return (str);
	if (str == NULL)
	{
		mer = malloc(news);
		if (mer == NULL)
			return (NULL);
		return (mer);
	}
	if (news == 0 && str != NULL)
	{
		free(str);
		return (NULL);
	}
	cop_str = str;
	mer = malloc(sizeof(*cop_str) * news);
	if (mer == NULL)
	{
		free(str);
		return (NULL);
	}
	filter = mer;
	for (i = 0; i < old && i < news; i++)
		filter[i] = *cop_str++;
	free(str);
	return (mer);
}

/**
 * asi_lineptr - the lineptr variabel reassign to get_line
 * @lineptr: an input string
 * @n: sizeof line ptr
 * @buf:srings to assign to line ptr
 * @b: size of buf
 */

void asi_lineptr(char **lineptr, size_t *n, char *buf, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buf;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buf;
	}
	else
	{
		str_cpy(*lineptr, buf);
		free(buf);
	}
}

/**
 * get_line - read from the file str
 * @lineptr: a string store the input from str
 * @n: size of lineptr
 * @str: stream to read from the input
 * Return: the number of bytes read
 */

ssize_t get_line(char **lineptr, size_t *n, FILE *str)
{
	static ssize_t i;
	ssize_t con;
	char s = 'x', *buf;
	int j;

	if (i == 0)
		fflush(str);
	else
		return (-1);
	i = 0;

	buf = malloc(sizeof(char) * 120);
	if (!buf)
		return (-1);
	while (s != '\n')
	{
		j = read(STDIN_FILENO, &s, 1);
		if (j == -1 || (j == 0 && i == 0))
		{
			free(buf);
			return (-1);
		}
		if (j == 0 && i != 0)
		{
			i++;
			break;
		}
		if (i >= 120)
			buf = re_alloc(buf, i, i + 1);
		buf[i] = s;
		i++;
	}
	buf[i] = '\0';
	asi_lineptr(lineptr, n, buf, i);
	con = i;
	if (j != 0)
		i = 0;
	return (con);
}
