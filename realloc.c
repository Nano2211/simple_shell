#include "shell.h"

/**
 * _memset - Fills memory with a const byte type.
 * @s: Pointer to the memory .
 * @b: The byte to fill *s with.
 * @n: The amount of bytes to be filled.
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int e;

	for (e = 0; e < n; z++)
		s[e] = b;
	return (s);
}

/**
 * ffree - Frees a string of strings.
 * @pp: String of strings.
 */
void ffree(char **pp)
{
	char **m = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(m);
}

/**
 * _realloc - Reallocates a memory block.
 * @ptr: Pointer to the previous malloc'ed bloc.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 *
 * Return: Pointer to the reallocated block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
