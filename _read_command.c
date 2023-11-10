#include "shell.h"

/**
 * TODO
*/

char *_read_command(int ac, char **av)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t characters_read;
	size_t total_length;
	int i = 0;

	(void)characters_read;
	(void)bufsize;
    if (ac > 1)
    {
        total_length = 0;
        for (i = 1; i < ac; i++)
        {
            total_length += _strlen(av[i]);
        }

        line = malloc(total_length + ac);
        line[0] = '\0';

        for (i = 1; i < ac; i++)
        {
            _strcat(line, av[i]);
            if (i < ac - 1)
            {
                _strcat(line, " ");
            }
        }
    }
    else if (ac == 2)
    {
		line = av[1];
    }

    return (line);
}
