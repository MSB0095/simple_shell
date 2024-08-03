#include "shell.h"

/**
 * _read_command - reads a command from arguments
 * @ac: Argument count
 * @av: Argument vector
 * @line: Pointer to the line buffer
 * Return: Number of characters read
 */
ssize_t _read_command(int ac, char **av, char **line)
{
	if (ac > 1)
	{
		*line = _strdup(av[1]);
		if (*line == NULL)
		{
			_putserr("Error: strdup failed");
			return (-1);
		}
		return (_strlen(*line));
	}
	return (-1);
}
