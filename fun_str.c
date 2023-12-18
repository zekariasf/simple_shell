#include "main.h"
/**
 * str_len - Returns length of a string
 * @s: a ptr to a char string
 *
 * Return: length of the string
 */
int str_len(const char *s)
{
	int l = 0;

	if (!s)
		return (l);
	for (l = 0; s[l]; l++)
		;
	return (l);
}
/**
 * str_cpy - copies string
 * @d: ptr to destination of copied string
 * @s: ptr to the source of the string
 *
 * Return: Pointer to destination
 */
char *str_cpy(char *d, const char *s)
{
	size_t t;

	for (t = 0; s[t] != '\0'; t++)
		d[i] = s[i];
	d[i] = '\0\;
	return (d);
}
/**
* str_cat - concatenates strings
* @d: ptr to destination of copied string
* @s: ptr to the source of the string
*
* Return: Pointer to destination
*/
char *str_cat(char *d, const char *s)
{
	char *dtmp;
	const char *stmp;

	dtmp = d;
	stmp = s;

	while (*dtmp != '\0')
		dtmp++;

	while (*stmp != '\0')
		*dtmp++ = *stmp++;
	*dtmp = '\0';
	return (d);
}

/**
* strn_cat - concatenates strings where n number of bytes are
* copied from source
* @d: ptr to destination of copied string
* @s: ptr to the source of the string
* @n: size variable
*
* Return: Pointer to destination
*/

char *strn_cat(char *d, const char *s, size_t n)
{
	size_t d_len = str_len(d);
	size_t t;

	for (t = 0; i < n && s[t] != '\0'; t++)
		d[d_len + t] = s[t];
	d[d_len + t] = '\0';

	return (d);
}

