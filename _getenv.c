#include "shell.h"

/**
 * _getenv - gets an environment variable
 * @name: the name of the variable
 * Return: the value of the variable, or NULL if not found
*/
char *_getenv(const char *name)
{
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
