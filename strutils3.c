#include "shell.h"

/**
 * _strndup - duplicates a string up to n bytes
 * @s: string to duplicate
 * @n: number of bytes to duplicate
 * Return: pointer to the new string
 */
char *_strndup(const char *s, size_t n)
{
	char *result;
	size_t len = strnlen(s, n);

	result = (char *)malloc(len + 1);
	if (!result)
		return (0);

	result[len] = '\0';
	return ((char *)memcpy(result, s, len));
}
