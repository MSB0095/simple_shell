#include "shell.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to write
 * Return: 1 on success, -1 on error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _putcharerr - writes a character to stderr
 * @c: character to write
 * Return: 1 on success, -1 on error
 */
int _putcharerr(char c)
{
	return (write(2, &c, 1));
}
/**
 * _putserr - prints a string to stderr
 * @str: string to print
 */
void _putserr(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putcharerr(str[i]);
		i++;
	}
	_putcharerr('\n');
}
/**
 * _puts - prints a string to stdout
 * @str: string to print
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
/**
 * _puts2 - prints a string to stdout
 * @str: string to print
 * Return: void
 */
void _puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
