#include "shell.h"

/**
 * input_buf - Buffer thats chained to commands
 * @info: Node Parameter structure in the code
 * @buf: Buffer address in the code
 * @len: Len variable address in the code
 * Return: Read bytes.
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* error handling for when nothing is left, just ++ to add to buffer*/
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT,sigintHandler);

#if USE_GETLINE
	r = getline(buf, &len_p, stdin);
#else
	r = _getline(info, buf, &len_p);
#endif
	if ( r > 0)
	{
		if ((*buf)[r - 1] == '\n')
		{
			(*buf)[r - 1] = '\0';/* removes whitespaces and null terminates */
				r--;
		}
		info->linecount_flag = 1;
		remove_comments(*buf);
		build_history_list(info, *buf, info->histcount++);
			*len = r;
		info->cmd_buf = buf;
	}
	return (r);
}

/**
 * get_input - Gets line input minus the newline.
 * @info: Parameter structure.
 * Return: Read bytes in code.
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* Buff command for ';' */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /*EOF */
	{
		return (-1);
	}
	if (len) /* This is for left over commands in the buffer */
	{
		j = i; /* Initializing static signed int with another initializor */
		p = buf + i; /* return pointer. */
	}
	while (j < len) /* Iteration of a ";" or the end */
	{
		if (is_chain(info, buf, &j))
			break;
		j++;
	}
	i = j + 1; /* increments past nulled semicolon */
	if (i >= len) /* buffer end? */
	{
		i = len = 0; /* reposition and reset length */
		info->cmd_buf_type = CMD_NORM;
	}
	*buf_p = p; /* sends pointer to current command position */
	return (_strlen(p)); /* Returns the lenth of the current command */
}

/**
 * read_buf - Reads buffer.
 * @info: Parameter structure.
 * @buf: Buffer.
 * @i: size variable.
 * Return: r
 * */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}
/**
 * _getline - Gets next line of input from STDIN.
 * @info: Parameter structure.
 * @ptr: A pointer to a buffer, preallocated or NULL.
 * @length: size of  preallocated ptr buffer if not NULL.
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE!RITICAL */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - Blocks command, ctrl-C.
 * @sig_num: The signal num.
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
