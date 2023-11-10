#include "shell.h"

/**
 * TODO
 */

void _execute(char **tokens, char **argv)
{
    pid_t pid;
    int status;
    pid_t wait;

    if (tokens != NULL)
    {
		if (_is_builtin(tokens[0]))
		{
			_execute_builtin(tokens, argv, environ);
			return;
		}
    	pid = fork();
        if (pid == -1)
        {
            _puts("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            if (_is_executable(tokens[0]))
            {
                execve(tokens[0], tokens, NULL);
                _puts("execve");
                exit(EXIT_FAILURE);
            }
            else
            {
                _execute_from_path(tokens, argv);
            }
        }
        else
        {
            wait = waitpid(pid, &status, 0);
            if (wait == -1)
            {
                _puts("waitpid");
                exit(EXIT_FAILURE);
            }
        }
    }
}

/**
 * TODO
*/
void _execute_from_path(char **tokens, char **argv)
{
    char *path = _getenv("PATH");
    char *dir;
    char *exec_path;
	char *pathcp;

    if (path != NULL)
    {
        pathcp = _strdup(path);
        dir = _strtok(pathcp, ":");
        while (dir != NULL)
        {
            exec_path = _make_path(dir, tokens[0]);
            if (_is_executable(exec_path))
            {
                execve(exec_path, tokens, NULL);
                _puts("execve");
                exit(EXIT_FAILURE);
            }
            free(exec_path);
            dir = _strtok(NULL, ":");
        }
        free(pathcp);
    }
    _puts2(argv[0]);
	_puts(": No such file or directory");
    exit(EXIT_FAILURE);
}

/**
 * TODO
*/
int _is_executable(char *command)
{
    int acc;

    acc = access(command, X_OK);
    if (acc == 0)
    {
        return (1);
    }
    return (0);
}

/**
 * TODO
*/
char *_make_path(char *dir, char *command)
{
    size_t dirlen;
    size_t cmdlen;
    size_t pathlen;
    char *execpath;

	dirlen = _strlen(dir);
	cmdlen = _strlen(command);
	pathlen = dirlen + cmdlen + 2;
	execpath = malloc(pathlen * sizeof(char));

    if (execpath == NULL)
    {
        _puts("malloc");
        exit(EXIT_FAILURE);
    }

    _strcpy(execpath, dir);
    _strcat(execpath, "/");
    _strcat(execpath, command);
    return (execpath);
}
