#include "shell.h"
#include "signals.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * signal_handler - Handles received signals
 * @signal: Signal number
 * @info: Signal info
 * @context: Context
 */
void signal_handler(int signal, siginfo_t *info, void *context)
{
	signal_data_t *data = (signal_data_t *)context;
	(void)info;
	data->signals_received[signal]++;
	_putserr("Signal received\n");
}

/**
 * setup_signal_handlers - Sets up signal handlers
 * @data: Pointer to signal data structure
 */
void setup_signal_handlers(signal_data_t *data)
{
	int i;
	struct sigaction sa;

	(void)data;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	for (i = 1; i < NSIG; i++)
	{
		if (i == SIGKILL || i == SIGSTOP || i == SIGRTMIN || i == SIGRTMAX ||
			i == 32 || i == 33 || i == SIGCHLD)
		{
			continue;
		}

		if (sigaction(i, &sa, NULL) == -1)
		{
			_putserr("Cannot handle signal\n");
		}
	}
}

/**
 * process_line - Processes a single line of input
 * @line: Line to process
 * @av: Argument vector
 */
void process_line(char *line, char **av)
{
	char **tokens;

	if (line[0] != '\n' && line[0] != '\0')
	{
		tokens = _split_line(line);
		if (tokens == NULL)
		{
			_putserr("Error: Failed to split line");
			free(line);
			return;
		}
		if (strcmp(tokens[0], "exit") == 0)
		{
			_free_tokens(tokens);
			free(line);
			exit(0);
		}
		_execute(tokens, av);
		_free_tokens(tokens);
	}
	free(line);
}

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 * @env: Environment variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL;
	int interactive;
	size_t len = 0;
	ssize_t read;
	signal_data_t signal_data = {0};

	(void)env;
	interactive = isatty(STDIN_FILENO);

	setup_signal_handlers(&signal_data);
	while (1)
	{
		if (interactive)
			prompt();
		read = interactive ? _getline(&line, &len) : _read_command(ac, av, &line);
		if (read == -1)
		{
			free(line);
			return (0);
		}
		process_line(line, av);
		line = NULL;
		len = 0;

		if (!interactive)
			break;
	}
	return (0);
}
