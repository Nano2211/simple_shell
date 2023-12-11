#include "shell.h"

/**
 * _strlen - calcs and returns the len of a string.
 * @s: the input string
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);

	while (*s++)
		len++;
	return (len);
}

/**
 * _strcmp - compares two strings lexicographically.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Checks whether a substring starts with a given string.
 * @haystack: the string to search
 * @needle: the substring to find
 *
 * Return: the address of the next character in haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concats 2 strings and returns the result.
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: a pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (result);
}
