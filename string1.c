#include "shell.h"

/**
 * _strcpy - copies a  string to a destination.
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int dex = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[dex])
	{
		dest[dex] = src[dex];
		dex++;
	}
	dest[dex] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a given string.
 * @str: the string to duplicate
 *
 * Return: a pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *res;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	for (len++; len--;)
		res[len] = *--str;
	return (res);
}

/**
 * _puts - prints the input string to the standard output.
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int dex = 0;

	if (!str)
		return;
	while (str[dex] != '\0')
	{
		_putchar(str[dex]);
		dex++;
	}
}

/**
 * _putchar - writes the character c to the standard output.
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int buff_dex;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || buff_dex >= WRITE_BUF_SIZE)
	{
		write(1, buffer, buff_dex);
		buffer_index = 0;
	}
	if (c != BUF_FLUSH)
		buffer[buff_dex++] = c;
	return (1);
}
