#include "shell.h"

/**
 * _is_builtin - checks if a command is a builtin
 * @command: the command to check
 * Return: 1 if builtin, 0 otherwise
*/

int _is_builtin(char *command)
{
	if (_strcmp(command, "exit") == 0
	|| _strcmp(command, "env") == 0
	|| _strcmp(command, "cd") == 0
	|| _strcmp(command, "setenv") == 0
	|| _strcmp(command, "unsetenv") == 0)
	{
		return (1);
	}
	return (0);
}
/**
 * _execute_builtin - executes a builtin
 * @tokens: the tokens
 * @argv: the arguments
 * @env: the environment
*/
void _execute_builtin(char **tokens, char **argv, char **env)
{
	(void)argv;
	if (_strcmp(tokens[0], "exit") == 0)
	{
		_builtin_exit(tokens);
	}
	else if (_strcmp(tokens[0], "env") == 0)
	{
		_builtin_env(env);
	}
	else if (_strcmp(tokens[0], "cd") == 0)
	{
		_builtin_cd(tokens);
	}
	else if (_strcmp(tokens[0], "setenv") == 0)
	{
		_builtin_setenv(tokens[1], tokens[2], 1);
	}
	else if (_strcmp(tokens[0], "unsetenv") == 0)
	{
		_builtin_unsetenv(tokens[1]);
	}
}
