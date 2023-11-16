#include "shell.h"

/**
 * _getline - reads the line
 * @lineptr: pointer to the line
 * @n: size of the line
 * @stream: stream
 * Return: the number of characters read
*/

int _getline(char **lineptr, size_t *n)
{
    char *line = NULL;
    size_t bufsize = BUFSIZE;
    ssize_t num_read;
    size_t index = 0;

    line = malloc(bufsize * sizeof(char));
    if (line == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        num_read = read(STDIN_FILENO, &line[index], 1);
        if (num_read == -1)
        {
            free(line);
            exit(EXIT_FAILURE);
        }
        if (line[index] == '\n' || num_read == 0)
        {
            line[index] = '\0';
            break;
        }
        index++;
        if (index >= bufsize)
        {
            bufsize += BUFSIZE;
            line = _realloc(line, bufsize * sizeof(char));
            if (line == NULL)
            {
                exit(EXIT_FAILURE);
            }
        }
    }

    *lineptr = line;
    *n = bufsize;
    return index;
}
