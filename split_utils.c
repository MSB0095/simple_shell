#include "shell.h"

/**
 * isspace - Check if a character is a whitespace character
 * @c: The character to check
 * Return: 1 if the character is a whitespace character, 0 otherwise
 */

int isspace(int c)
{
	const char whitespace[] = " \t\n\r\v\f";
	int i;

	for (i = 0; whitespace[i]; ++i)
	{
		if (c == whitespace[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * is_whitespace_or_quote - Check if a character is a whitespace or a quote
 * @c: The character to check
 * Return: 1 if the character is a whitespace or a quote, 0 otherwise
 */

int is_whitespace_or_quote(char c)
{
	return (isspace(c) || c == '"' || c == '\'');
}

/**
 * _strncpy - Copy a string
 * @dest: The destination buffer
 * @src: The source string
 * @n: The number of bytes to copy
 * Return: The destination buffer
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _trim - trims a string
 * @str: string to trim
 * Return: destination
 */
char *_trim(char *str)
{
	size_t len, start, end, trimmed_len;
	char *trimmed_str;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);
	start = 0;
	end = len - 1;

	while (start < len && is_whitespace_or_quote(str[start]))
	{
		start++;
	}

	while (end > start && is_whitespace_or_quote(str[end]))
	{
		end--;
	}

	trimmed_len = end - start + 1;

	trimmed_str = (char *)malloc((trimmed_len + 1) * sizeof(char));
	if (trimmed_str == NULL)
	{
		return (NULL);
	}

	_strncpy(trimmed_str, str + start, trimmed_len);
	trimmed_str[trimmed_len] = '\0';

	return (trimmed_str);
}
