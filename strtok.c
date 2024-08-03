#include "shell.h"

/**
 * _strtok - Split a string into tokens
 * @str: The string to split
 * @delim: The delimiter characters
 * Return: The next token from the string or NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token;
	static char *last_delim;
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
		if (*last_token == '\"')
		{
			last_token++;
			while (*last_token && *last_token != '\"')
				last_token++;
			if (*last_token)
				last_token++;
		}
		else if (_strchr(last_delim, *last_token) != NULL)
		{
			*last_token = '\0';
			last_token++;
			return (token);
		}
		else
			last_token++;
	}

	if (token == last_token)
		return (NULL);

	return (token);
}
