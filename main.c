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

	(void)env;
	interactive = (ac == 1);

	while (1)
	{
		if (interactive)
			prompt();
		line = interactive ? _read_line() : _read_command(ac, av);
		if (line == NULL)
			return (0);
		if (line[0] != '\n' && line[0] != '\0')
		{
			tokens = _split_line(line);
			free(line);
			_execute(tokens, av);
			_free_tokens(tokens);
		}

		if (!interactive)
			break;
	}
	return (0);
}
