#include "shell.h"

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 * @env: Environment variables
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char **tokens = NULL;
	int interactive;
	size_t len = 0;
	ssize_t read;

	(void)env;
	interactive = (ac == 1);

	while (1)
	{
		if (interactive)
			prompt();
		read = interactive ? _getline(&line, &len) : _read_command(ac, av, &line);
		if (read == -1)
		{
			free(line);
			return (0);
		}
		if (line[0] != '\n' && line[0] != '\0')
		{
			tokens = _split_line(line);
			if (tokens == NULL)
			{
				_putserr("Error: Failed to split line");
				free(line);
				continue;
			}
			_execute(tokens, av);
			_free_tokens(tokens);
		}
		free(line);
		line = NULL;
		len = 0;

		if (!interactive)
			break;
	}
	return (0);
}
