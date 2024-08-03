#include "shell.h"
#define MAX_TOKEN_SIZE 100
/**
 * _split_line - Split a line into tokens
 * @line: The line to split
 * Return: An array of tokens
 */

char **_split_line(char *line)
{
	int bufsize = MAX_TOKEN_SIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;
	char *tokendup;
	char *trimmed_token;

	if (!tokens)
	{
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
	return (tokens);
}
/**
 * is_special_character - Check if a character is a special character
 * @c: The character to check
 * Return: 1 if the character is special, 0 otherwise
 */
int is_special_character(char c)
{
	return (c == ';' || c == '&' || c == '|');
}
/**
 * _free_tokens - Free an array of tokens
 * @tokens: The array of tokens to free
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
