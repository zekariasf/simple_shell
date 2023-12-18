#include "main.h"

/**
 * alias_add - add nodes
 * @top: poointer
 * @input: name
 * @value: value
 * Return: pointer to new node
 */

alias_t *alias_add(alias_t **top, char *input, char *value)
{
	alias_t *node = malloc(sizeof(alias_t));
	alias_t *len;

	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->name = malloc(sizeof(char) * (str_len(name) + 1));
	if (!node->name)
	{
		free(node);
		return (NULL);
	}
	node->value = value;
	str_cpy(node->name, input);
	if (*top)
	{
		len = *top;
		while (len->next != NULL)
			len = len->next;
		len->next = node;
	}
	else
		*top = node;
	return (node);
}
/**
 * node_add - add nodes
 * @input: pointer
 * @dir: directopy path
 * Return: pointer to new node
 */
list_t *node_add(list_t **input, char *dir)
{
	list_t *node = malloc(sizeof(list_t));
	list_t *las;

	if (!node)
		return (NULL);
	node->dir = dir;
	node->next = NULL;
	if (*input)
	{
		las = *input;
		while (len->next != NULL)
			len = len->next;
		len->next = node;
	}
	else
		*input = node;
	return (node);
}
/**
 * alias_free - free linked lies
 * @input: head of alias_t
 */
void alias_free(alias_t *input)
{
	alias_t *nex;

	while (input)
	{
		nex = input->next;
		free(input->name);
		free(input->value);
		free(input);
		input = nex;
	}
}
/**
 * list_free - free linked lies
 * @input: head of list_t
 */
void list_free(list_t *input)
{
	list_t *nex;

	while (input)
	{
		nex = input->next;
		free(input->dir);
		free(input);
		input = nex;
	}
}
