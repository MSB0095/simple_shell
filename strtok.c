#include "shell.h"

/**
 * TODO
*/
char *_strtok(char *str, const char *delim)
{
    static char *last_token = NULL;
    static char *last_delim = NULL;
    char *token;

    if (str != NULL)
    {
        last_token = str;
        last_delim = (char *)delim;
    }

    if (last_token == NULL)
        return (NULL);

    token = last_token;
    while (*last_token != '\0')
    {
        if (_strchr(last_delim, *last_token) != NULL)
        {
            *last_token = '\0';
            last_token++;
            return (token);
        }
        last_token++;
    }

    if (token == last_token)
        return (NULL);

    return (token);
}
