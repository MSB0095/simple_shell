#include "shell.h"

/**
 * _builtin_exit - exits the shell
 * @tokens: the tokens
*/
void _builtin_exit(char **tokens)
{
	int status = 0;

	if (tokens[1] != NULL)
	{
		status = _atoi(tokens[1]);
	}

	exit(status);
}

/**
 * _builtin_env - prints the environment
 * @env: the environment
*/

void _builtin_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		_puts(env[i]);
		i++;
	}
}

/**
 * _builtin_cd - changes the current working directory
 * @tokens: the tokens
*/
void _builtin_cd(char **tokens)
{
	char *dir = tokens[1];
	char *prev_dir = _getenv("PWD");
	char cwd[PATH_MAX];

	if (dir == NULL || _strcmp(dir, "~") == 0)
	{
		dir = _getenv("HOME");
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = prev_dir;
	}

	if (chdir(dir) == -1)
	{
		perror("chdir");
		return;
	}


	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return;
	}

	if (_builtin_setenv("PWD", cwd, 1) == -1)
	{
		perror("_setenv");
		return;
	}
}

/**
 * _builtin_setenv - sets an environment variable
 * @name: the name of the variable
 * @value: the value of the variable
 * @overwrite: whether to overwrite the variable if it already exists
 * Return: 0 on success, -1 on failure
*/
int _builtin_setenv(const char *name, const char *value, int overwrite)
{
	char *env_var;
	int name_len;
	int value_len;
	int total_len;

	if (name == NULL || value == NULL)
	{
		return (-1);
	}

	if (overwrite == 0 && _getenv(name) != NULL)
	{
		return (0);
	}

	name_len = _strlen(name);
	value_len = _strlen(value);
	total_len = name_len + value_len + 2;

	env_var = malloc(total_len * sizeof(char));
	if (env_var == NULL)
	{
		perror("malloc");
		return (-1);
	}

	_strcpy(env_var, name);
	_strcat(env_var, "=");
	_strcat(env_var, value);

	if (putenv(env_var) != 0)
	{
		perror("putenv");
		free(env_var);
		return (-1);
	}
	free(env_var);
	return (0);
}

/**
 * _builtin_unsetenv - unsets an environment variable
 * @name: the name of the variable
 * Return: 0 on success, -1 on failure
*/
int _builtin_unsetenv(const char *name)
{
	if (name == NULL)
	{
		return (-1);
	}

	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}
