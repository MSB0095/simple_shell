#include "shell.h"
#define MAX_TOKEN_SIZE 100
/**
 * TODO
*/

char **_split_line(char *line)
{
    int bufsize = MAX_TOKEN_SIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;
	char *tokendup;
	char *trimmed_token;

    if (!tokens) {
        exit(EXIT_FAILURE);
    }

	token = _strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		if (token && token[0] != '\0')
		{
            tokendup = _strdup(token);
            trimmed_token = _trim(tokendup);
            tokens[position] = trimmed_token;
            free(tokendup);
			position++;
		}

		token = _strtok(NULL, " \t\r\n\a");
	}
    tokens[position] = NULL;
    return tokens;
}
/**
 * TODO
*/
int is_special_character(char c)
{
    return c == ';' || c == '&' || c == '|';
}
/**
 * TODO
*/
void _free_tokens(char **tokens)
{
    int i = 0;
    while (tokens[i] != NULL)
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}
