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
#define PATH_MAX 1024
#define BUFFER_SIZE 64

extern char **environ;
void prompt(void);
char *_read_line(void);
char **_split_line(char *line);
int _getline(char **lineptr, size_t *n, FILE *stream);
char *_read_line(void);
char **_split_line(char *line);
int _putchar(char c);
void _puts(char *str);
void _puts2(char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _atoi(char *s);
int isspace(int c);
char *_strncpy(char *dest, const char *src, size_t n);
char *_trim(char *str);
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *dest, const void *src, size_t n);
void _free_tokens(char **tokens);
char *_read_command(int ac, char **av);
void _execute(char **tokens, char **argv);
void _execute_from_path(char **tokens, char **argv);
int _is_executable(char *command);
char *_make_path(char *dir, char *command);
int _is_builtin(char *command);
void _execute_builtin(char **tokens, char **argv, char **env);
void _builtin_env(char **env);
void _builtin_cd(char **tokens);
int _builtin_setenv(const char *name, const char *value, int overwrite);
int _builtin_unsetenv(const char *name);
void _builtin_exit(char **tokens);
char *_getenv(const char *name);
char *_strtok(char *str, const char *delim);
char **allocate_token(char **tokens, char *token, int i);
char **handle_quotes(char **tokens, char *token, int *i, int *size);
char **handle_no_quotes(char **tokens, char *token, int *i, int *size);
char **allocate_token(char **tokens, char *token, int i);
char **handle_quotes(char **tokens, char *token, int *i, int *size);
char **handle_no_quotes(char **tokens, char *token, int *i, int *size);
char *_trim_quotes(char *str);
char *_strndup(const char *s, size_t n);
void *_memmove(void *dest, const void *src, size_t n);
void _putserr(char *str);
int _putcharerr(char c);
void _puts2err(char *str);
int is_special_character(char c);
#endif
