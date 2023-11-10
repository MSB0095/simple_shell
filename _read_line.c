#include "shell.h"

/**
 * _read_line - reads the line
*/

char *_read_line(void)
{
	char *line = NULL;
	size_t bufsize;
	ssize_t read;

	bufsize = BUFSIZE;
	read = _getline(&line, &bufsize, stdin);
	if (read == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(EXIT_SUCCESS);
	}
	return (line);
}