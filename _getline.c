#include "shell.h"

/**
 * _getline - reads the line
 * @lineptr: pointer to the line
 * @n: size of the line
 * @stream: stream
 * Return: the number of characters read
*/

int _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line = NULL;
	size_t bufsize;
	ssize_t read;

	bufsize = BUFSIZE;
	read = getline(&line, &bufsize, stream);
	if (read == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(EXIT_SUCCESS);
	}
	*lineptr = line;
	*n = bufsize;
	return (read);
}
