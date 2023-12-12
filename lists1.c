#include "shell.h"

/**
 * list_len - Finds the length of a linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t list_len(const list_t *h)
{
	size_t m = 0;

	while (h)
	{
		h = h->next;
		m++;
	}
	return (m);
}

/**
 * list_to_strings - Returns an array of strings from the list->str node field.
 * @head: Pointer to the first node.
 *
 * Return: Array of strings.
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t m = list_len(head), f;
	char **ztrz;
	char *str;

	if (!head || !m)
		return (NULL);
	ztrz = malloc(sizeof(char *) * (m + 1));
	if (!ztrz)
		return (NULL);
	for (m = 0; node; node = node->next, m++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (f = 0; f < m; f++)
				free(ztrz[f]);
			free(ztrz);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		ztrz[m] = str;
	}
	ztrz[m] = NULL;
	return (ztrz);
}

/**
 * print_list - Prints entirty of the  elements of a list_t linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t print_list(const list_t *h)
{
	size_t m = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		m++;
	}
	return (m);
}

/**
 * node_starts_with - Returns the node whose string starts with known prefix.
 * @node: Pointer to the list head.
 * @prefix: String to match.
 * @c: The next character after the prefix to match.
 *
 * Return: Matching node or NULL.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *pp = NULL;

	while (node)
	{
		pp = starts_with(node->str, prefix);
		if (pp && ((c == -1) || (*pp == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - Finds the index of a node in a linked list.
 * @head: Pointer to the list head.
 * @node: Pointer to the node.
 *
 * Return: Index of the node or -1 if not found.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t m = 0;

	while (head)
	{
		if (head == node)
			return (m);
		head = head->next;
		m++;
	}
	return (-1);
}
