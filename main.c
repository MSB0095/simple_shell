#include "shell.h"

/**
 * main - the main function
 * @ac: the number of arguments
 * @av: the arguments
 * @env: the environment
*/

int main(int ac, char **av, char **env)
{
	char *line = NULL;
	char **args = NULL;
	int status;
	int isinteractive;
	int i;
	(void)ac;
	(void)av;
	(void)env;
	(void)isinteractive;
	if (isatty(STDIN_FILENO))
	{
		isinteractive = 1;
	}
	else
	{
		isinteractive = 0;
	}

	status = 1;
	i = 0;
	while (status)
	{
		prompt();
		line = _read_line();
		args = _split_line(line);
		while (args[i] != NULL)
		{
			printf("%s\n", args[i]);
			i++;
		}
		
		status = _execute(args, env);
		free(line);
		free(args);
	}
	return (0);
}
