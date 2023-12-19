#include "main.h"

/**
 * line_handler - paritions of the given stdio
 * @argv: a pointer to read form stdin
 * @len: lengh of the line
 */
void line_handler(char **argv, ssize_t len)
{
	char *line_old, *line_new;
	char prev, cur, next;
	size_t n, b;
	ssize_t len_new;

	len_new = new_line(*argv);
	if (len_new == len - 1)
		return;
	line_new = malloc(len_new + 1);
		if (line_new == NULL)
			return;
	b = 0;
	line_old = *argv;
	for (n = 0; line_old[n]; n++)
	{
		cur = line_old[n];
		next = line_old[n + 1];
		if (n != 0)
		{
			prev = line_old[n - 1];
			if (cur == ';')
			{
				if (next == ';' && prev != ' ' && prev != ';')
				{
					line_new[b++] = ' ';
					line_new[b++] = ';';
					continue;
				}
				else if (prev == ';' && next != ' ')
				{
					line_new[b++] = ';';
					line_new[b++] = ' ';
					continue;
				}
				if (prev != ' ')
					line_new[b++] = ' ';
				line_new[b++] = ';';
				if (next != ' ')
					line_new[b++] = ' ';
				continue;
			}
			else if (cur == '&')
			{
				if (next == '&' && prev != ' ')
					line_new[b++] = ' ';
				else if (prev == '&' && next != ' ')
				{
					line_new[b++] = '&';
					line_new[b++] = ' ';
					continue;
				}
			}
			else if (cur == '|')
			{
				if (next == '|' && prev != ' ')
					line_new[b++] = ' ';
				else if (prev == '|' && next != ' ')
				{
					line_new[b++] = '|';
					line_new[b++] = ' ';
					continue;
				}
			}
		}
		else if (cur == ';')
		{
			if (n != 0 && line_old[n - 1] != ' ')
				line_new[b++] = ' ';
			line_new[b++] = ';';
			if (next != ' ' && next != ';')
				line_new[b++] = ' ';
			continue;
		}
		line_new[b++] = line_old[n];
	}
	line_new[b] = '\0';
	free(*argv);
	*argv = line_new;
}

/**
 * opretors_log - check "||" or "&&"
 * @len: pointer
 * @len_new: pointer
 */
void opretors_log(char *len, ssize_t *len_new)
{
	char prev, cur, next;

	prev = *(len - 1);
	cur = *len;
	next = *(len + 1);


	if (cur == '&')
	{
		if (next == '&' && prev != ' ')
			(*len_new)++;
		else if (prev == '|' && next != ' ')
			(*len_new)++;
	}
	else if (cur == '|')
	{
		if (next == '|' && prev != ' ')
			(*len_new)++;
		else if (prev == '|' && next != ' ')
			(*len_new)++;
	}
}
/**
 * new_line - grt thr new length
 * @len: line to check
 * Return: the ne length
 */
ssize_t new_line(char *len)
{
	size_t i;
	ssize_t len_new = 0;
	char cur, next;

	for (i = 0; len[i]; i++)
	{
		cur = len[i];
		next = len[i + 1];
		if (cur == '#')
		{
			if (i == 0 || len[i - 1] == ' ')
			{
				len[i] = '\0';
				break;
			}
		}
		else if (i != 0)
		{
			if (cur == ';')
			{
				if (next == ';' && len[i - 1] != ' ' &&
					len[i - 1] != ';')
				{
					len_new += 2;
					continue;
				}
				else if (len[i - 1] == ';' && next != ' ')
				{
					len_new += 2;
					continue;
				}
				if (len[i - 1] != ' ')
					len_new++;
				if (next != ' ')
					len_new++;
			}
			else
				opretors_log(&len[i], &len_new);
		}
		else if (cur == ';')
		{
			if (i != 0 && len[i - 1] != ' ')
				len_new++;
			if (next != ' ' && next != ';')
				len_new++;
		}
		len_new++;
	}
	return (len_new);
}
