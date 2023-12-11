#include "shell.h"

/**
 * _erratoi - converts a string to an int.
 * @s: The string to be converted.
 * Return: 0 if no mum in string, the converted num otherwise,
 * -1 on err (e.g, overflow)
 */
int _erratoi(char *s)
{
	int a = 0;
	unsigned long int res = 0;

	if (*s == '-')
		s++; /* why is main 255 returned? */
	for ( a = 0; s[a] != '\0'; a++)
	{
		if (s[a] >= '0' && s[a] <= '9')
		{
			res *= 10;
			res += (s[a] - '0');
			if (res > INT_MAX)
				return (-1); /* throws an error */
		}
		else 
			return (-1); /* for an invalid char */

		}
	return (result);
}

/**
 * print_error - Prints err message.
 * @info: The parameter and retrurn info node
 * @estr: String ith specified error type.
 * Return: void.
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**print_d - Prints a decimal (int) num (base 10)
 * @input: input num.
 * @fd: file descriptor to write to.
 * Rerurn: num of chars printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = __putchar;
	int a, count = 0;
	unsigned int _abs_, current;

	if ( fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for ( a = 1000000000; a > 1; a /= 10)
	{
		if  (_abs_ / a)
		{
			__putchar('0' + current / a);
			count++;
		}
		current %= a;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * conver_number - converter, a clone of itoa
 * @num: number to be converted
 * @base: base of conversion
 * @flags: arguments flags
 * Return: String representing the num
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVER_LOWERCASE  ? "0123456789abcdef" : "0123456789ABCDEF";
	prt = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	}while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - switch the first instance of '#' with '\0'.
 * @buf: Address of the string to modify.
 * Return: Always 0.
 */
void remove_comments(char *buf)
{
	int r;

	for (r = 0; buf[r] != '\0'; r++)
		if (buf[r] == '#' && (!r || buf[r - 1] == ' '))
		{
			buf[r] = '\0';
			break;
		}
}
