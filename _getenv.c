#include "shell.h"

/**
 * TODO
*/
char *_getenv(const char *name)
{
    extern char **environ;
    int i;
    size_t name_len = _strlen(name);

    for (i = 0; environ[i] != NULL; i++)
    {
        if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
        {
            return (environ[i] + name_len + 1);
        }
    }

    return (NULL);
}
