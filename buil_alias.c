#include "main.h"
/**
 * alias_shell - Builtin cmd that prints aliases, specific aliases, or
 * sets alias
 * @args: array of argumnets
 * @start: a pointer to the begingi  of args
 *
 * Return: -1 for error, 0 otherwise
 */
int alias_shell(char **args, char __attribute__((__unused__)) **start)
{
	alias_t *tmp = aliases;
	int a, ret = 0;
	char *val;

	if (!args[0])
	{
		while (tmp)
		{
			write_alias(tmp);
			tmp = tmp->next;
		}
		return (ret);
	}
	for (a = 0; args[a]; a++)
	{
		tmp = aliases;
		val = str_chr(args[a], '=')
		if (!val)
		{
		while (tmp)
				{
		if (str_cmp(args[a], tmp->name) == 0)
					{
			write_alias(tmp);
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		ret = create_error(args + i, 1);
		}
		else
			set_alias(args[a], val);
	}
	return (ret);
}
/**
 * set_alias - creates a new alais with or sets an existing alias wit
 * name and value
 * @v_name: name of the alias
 * @val: value of the alias
 */
void set_alias(char *v_name, char *val)
{
	alias_t *tmp = aliases;
	int l, x, y;
	char *new_val;

	*val = '\0';
	value++;
	l = str_len(value) - str_spn(val, "'\"");
	new_val = malloc(sizeof(char) * (l + 1));
	if (!new_val)
		return;
	for (x = 0, y = 0; val[x]; x++)
	{
		if (value[x] != '\'' && value[x] != '"')
			new_val[y++] = val[x];
	}
	new_val[y] = '\0';
	while (tmp)
	{
		if (str_cmp(v_name, tmp->name) == 0)
		{
			free(tmp->value);
			tmp->value = new_val;
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		add_alias_end(&aliases, v_name, new_val);
}
/**
 * write_alias - Writes the alias
 * @alias: Pointer to an alias
 *
 */
void write_alias(alias_t *alias)
{
	char *alias_str;
	int l = str_len(alias->name) + str_len(alias->value) + 4;

	alias_str = malloc(sizeof(char) * (l + 1));
	if (!alias_str)
		return;
	str_cpy(alias_str, alias->name);
	str_cat(alias_str, "=");
	str_cat(alias_str, alias->value);
	str_cat(alias_str, "'\n");

	write(STDOUT_FILENO, alias_str, l);
	free(alias_str);
}
/**
 * replace_alias - Scans through arguments and replace any matching al
 * iases with their value
 * @args: pointer to the arguments
 *
 * Return: 2 dimensional pointer to the arguments
 */
char **replace_alias(char **args)
{
	alias_t *tmp;
	int a;
	char *new_val;

	if (str_cmp(args[0], "alias") == 0)
		return (args);
	for (a = 0; args[a]; a++)
	{
		tmp = aliases;
		while (tmp)
		{
			if (str_cmp(args[a], tmp->name) == 0)
			{
				new_val = malloc(sizeof(char) * (str_len(temp->value) + 1));
				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				str_cpy(new_val, tmp->value);
				free(args[a]);
				args[a] = new_val;
				i--;
				break;
			}
			tmp = tmp->next;
		}
	}
	return (args);
}

