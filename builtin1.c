#include "shell.h"

/**
 * _myhistory - displays hist starting at 0
 * @info: Struct with potential args
 *  Return: Always a value of 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets known alias to string
 * @info: parameter of the structure
 * @str: the string alias
 *
 * Return: returns 0 else 1
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int dog;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	dog = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (dog);
}

/**
 * set_alias - sets known alias to astring
 * @info: parameters of the structure
 * @str: the string alias
 *
 * Return: 0 on success, 1 on fail
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints a string
 * @node: The alias
 *
 * Return: returns either 1 or 0
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - copys available alias
 * @info: Struct with potent trials
 *  Return: Always returns a value of 0
 */
int _myalias(info_t *info)
{
	int g = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (g = 1; info->argv[g]; g++)
	{
		p = _strchr(info->argv[g], '=');
		if (p)
			set_alias(info, info->argv[g]);
		else
			print_alias(node_starts_with(info->alias, info->argv[g], '='));
	}

	return (0);
}
