#include "main.h"

/**
 * l_token - locates the delimeter index
 * @s : string to be searched
 * @del: delimiter
 *
 * Return: the delimter index marking the end of
 * the initial token pointed to s
 */
int l_token(char *s, char *del)
{
	int i = 0, l = 0;

	while (*(s + i) && *(s + i) != *del)
	{
		l++;
		i++;
	}

	return (l);

}

/**
 * token_count - counts tokens
 * @s: string to be searched
 * @del: delimter char
 *
 * Return: No. of word within s
 */
int token_count(char *s, char *del)
{
	int i, tok = 0, l = 0;

	for (i = 0; *(s + i); i++)
		l++;

	for (i = 0; i < l; i++)
	{
		if (*(s + i) != *del)
		{
			tok++;
			i += l_token(s + i, d);
		}
	}

	return (tok);

}

/**
 * str_tok - tokenizes a string
 * @s: the string
 * @del: the delimiter character
 *
 * Return: a ptr to an array containing the tokenized words.
 */
char **str_tok(char *s, char *del)
{
	char **p;
	int i = 0, tok, t, chars, l;

	tok = token_count(s, del);
	if (tok == 0)
		return (NULL);

	for (t = 0; t < tok; t++)
	{
		while (s[i] == *del)
			i++;
		chars = l_token(s + i, del);
		p[t] = malloc(sizeof(char) * (chars + 1));
		if (!p[t])
		{
			for (i -= 1; i >= 0; i--)
				free(p[i]);
			free(p);
			return (NULL);
		}

		for (l = 0; l < chars; l++)
		{
		p[t][l] = s[i];
	i++;
		}

	p[t][l] = '\0';
	}
p[t] = NULL;
P[t + 1] = NULL;

return (p);
}

