#include "shell.h"

/**
 * TODO
*/

int isspace(int c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

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
    return dest;
}

char *_trim(char *str)
{
    size_t len, start, end, trimmed_len;
    char *trimmed_str;

    if (str == NULL)
    {
        return NULL;
    }

    len = _strlen(str);
    start = 0;
    end = len - 1;

    while (start < len && isspace(str[start]))
    {
        start++;
    }

    while (end > start && isspace(str[end]))
    {
        end--;
    }

    trimmed_len = end - start + 1;

    trimmed_str = (char *)malloc((trimmed_len + 1) * sizeof(char));
    if (trimmed_str == NULL)
    {
        return NULL;
    }

    _strncpy(trimmed_str, str + start, trimmed_len);
    trimmed_str[trimmed_len] = '\0';

    return trimmed_str;
}
