#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strncmp - compares two strings up to n bytes
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of bytes to compare
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}
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
/**
 * _strndup - duplicates a string up to n bytes
 * @s: the source string
 * @n: the number of bytes to duplicate
 * Return: a pointer to the duplicated string
 */
char *_strndup(const char *s, size_t n)
{
	char *result;
	size_t len;

	len = strnlen(s, n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);

	result[len] = '\0';
	return ((char *)memcpy(result, s, len));
}
