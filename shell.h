#ifndef SHELL__H
#define SHELL__H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define BUFSIZE 1024

extern char **environ;
void prompt(void);
char *_read_line(void);
char **_split_line(char *line);
int _getline(char **lineptr, size_t *n, FILE *stream);
char *_read_line(void);
char **_split_line(char *line);
int _execute(char **args, char **env);

#endif
