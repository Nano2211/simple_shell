#include "shell.h"

/**
 * _strncpy - Copy a string.
 * @dest: The destination of the  string to be copied to.
 * @src: The source string.
 * @n: The num of chars to be copied.
 * Return: A pointer to the concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int m, j;
	char *s = dest;

	m = 0;
	while (src[m] != '\0' && m < n - 1)
	{
		dest[m] = src[m];
		m++;
	}
	if (m < n)
	{
		j = m;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - Concats 2 strings.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used.
 * Return: A pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}

/**
 * _strchr - Locates a char in a string.
 * @s: The string thats  parsed.
 * @c: The char to look for.
 * Return: pointer to the first occurrence of the character in the string.
 *         If the character is not found, returns NULL.
 */
char *_strchr(char *s, char c)
{
	do	{
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
