#include "shell.h"

/**
 * **strtow - ignores repeat delimiters to split a string into 2 seperate strings.
 * @str: the input string
 * @d: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str, char *d)
{
	int a, b, c, m, numwords = 0;
	char **result;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	result = malloc((1 + numwords) * sizeof(char *));
	if (!result)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (is_delim(str[a], d))
			a++;
		c = 0;
		while (!is_delim(str[a + c], d) && str[a + c])
			c++;
		result[b] = malloc((c + 1) * sizeof(char));
		if (!result[b])
		{
			for (c = 0; c < b; c++)
				free(result[c]);
			free(result);
			return (NULL);
		}
		for (m = 0; m < c; m++)
			result[b][m] = str[a++];
		result[b][m] = 0;
	}
	result[b] = NULL;
	return (result);
}

/**
 * **strtow2 - splits a given string into words using a spec delimiter.
 * @str: the input string
 * @d: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int j, k, i, e, numwords = 0;
	char **result;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
		if ((str[j] != d && str[j + 1] == d) ||
				(str[j] != d && !str[j + 1]) || str[j + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	result = malloc((1 + numwords) * sizeof(char *));
	if (!result)
		return (NULL);
	for (j = 0, k = 0; k < numwords; k++)
	{
		while (str[j] == d && str[j] != d)
			j++;
		i = 0;
		while (str[j + i] != d && str[j + i] && str[j + i] != d)
			i++;
		result[k] = malloc((i + 1) * sizeof(char));
		if (!result[k])
		{
			for (i = 0; i < k; i++)
				free(result[i]);
			free(result);
			return (NULL);
		}
		for (e = 0; e < i; e++)
			result[k][e] = str[j++];
		result[k][e] = 0;
	}
	result[k] = NULL;
	return (result);
}
