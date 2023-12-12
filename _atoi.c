#include "shell.h"

/**
 * interactive - true is returned if shell is in interactive mode
 * @info: address for structure.
 *
 * Return: 1 if true else return 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a char is delimited.
 * @c: checks the character.
 * @delim: the delim checked.
 * Return: 1 else return 0.
 */
int is_delim(char c, char *delim)
{
	while(*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks whether a char is an alphabet.
 * @c: char to be inputted>
 * Return: 1 for true else return 0.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/** _atoi - convert string to int.
 * @s: str to change/
 * Return: 1 if true else return 0.
 */
int _atoi(char *s)
{
	int vaar, sign = 1, flag = 0, out;
	unsigned int res = 0;

	for (vaar = 0; s[vaar] != '\0' && flag !=2; vaar++)
	{
		if (s[vaar] == '-')
			sign *= -1;
		if (s[vaar] >= '0' && s[vaar] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (s[vaar] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		out = -res;
	else
		out = res;
	return (out);
}
