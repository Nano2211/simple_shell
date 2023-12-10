#include "shell.h"

/**
 * main - the entry point of the simple shell.
 * @ac: argument count.
 * @av: array of strings repping the command-line arguments.
 *
 * Return: 0 on succes, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = {INFO_INIT}
	int fd = 2;

	/* Increment file descriptor */
	asm("mov %1, %0\n\t"
			"add $3, %0"
			: "=r"(fd)
			: "=r"(fd));
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCESS)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}

	/* Init enviro and read histroy */
	populate_env_list(info);
	read_history(info);

	/* Init the shell */
	hsh(info, av);

	return (EXIT_SUCCESS);
}