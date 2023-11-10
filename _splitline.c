#include "shell.h"

/**
 * TODO
*/

char **_split_line(char *line)
{
    const char *delim = " \t\n";
    char **tokens = NULL;
    char *token;
    int i = 0;
    int size = 1;
    char **temp;
    int in_quotes = 0;
	char *trimmed_token;

    tokens = malloc(sizeof(char *) * size);
    if (tokens == NULL)
    {
        return (NULL);
    }

    token = strtok(line, delim);
    if (token != NULL && token[0] == '#')
    {
        free(tokens);
        return (NULL);
    }

    while (token != NULL)
    {
        if (token[0] == '"' || token[0] == '\'')
        {
            if (in_quotes)
            {
                in_quotes = 0;
            }
            else
            {
                in_quotes = 1;
            }
        }

        if (in_quotes)
        {
            temp = _realloc(tokens, sizeof(char *) * (i + 2));
            if (temp == NULL)
            {
                _free_tokens(tokens);
                return (NULL);
            }

            tokens = temp;
            tokens[i] = malloc(_strlen(token) + 1);
            if (tokens[i] == NULL)
            {
                _free_tokens(tokens);
                return (NULL);
            }

            _strcpy(tokens[i], token);
            tokens[i + 1] = NULL;

            i++;
            size++;
        }
        else
        {
            trimmed_token = _trim(token);
            if (_strlen(trimmed_token) > 0)
            {
                temp = _realloc(tokens, sizeof(char *) * (i + 2));
                if (temp == NULL)
                {
                    _free_tokens(tokens);
                    return (NULL);
                }

                tokens = temp;
                tokens[i] = malloc(_strlen(trimmed_token) + 1);
                if (tokens[i] == NULL)
                {
                    _free_tokens(tokens);
                    return (NULL);
                }

                _strcpy(tokens[i], trimmed_token);
                tokens[i + 1] = NULL;

                i++;
                size++;
            }
            free(trimmed_token);
        }

        token = strtok(NULL, delim);
    }

    return (tokens);
}
/**
 * TODO
*/
void _free_tokens(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
		return;
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
