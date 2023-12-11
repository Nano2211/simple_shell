#include "shell.h"

/**
 * bfree - releases a pointer and sets new address to NULL.
 * @ptr; Address of pointer.
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
