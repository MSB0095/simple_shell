#include "shell.h"

/**
 * TODO
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
		tokens = _split_line(line);
		_execute(tokens, av);
		free(line);
		if (!interactive)
			break;
	}

	return (0);
}
