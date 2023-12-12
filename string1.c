#include "shell.h"

/**
 * _strcpy - copies a set of strings from a source to an alt destination
 * @dest: the destination 
 * @src: the source
 *
 * Return: a pointer to the stings destination
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

	/**
	 * _strdup - duplicates a string
	 * @str: the duplicate string
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
		result = malloc(sizeof(char) * (length + 1));
		if (!res)
			return (NULL);
		for (len++, len--;)
			res[len] = *--str;
		return (res);
	}

/**
 * _puts - prints the input string to the stdout.
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
 * _putchar - writes the char 'c' to the stdout.
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
 int _putchar(char c)
{
	static int m;
	static char bufr[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(1, bufr, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		bufr[m++] = c;
	return (1);
}
