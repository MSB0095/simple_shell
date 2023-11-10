#include "shell.h"

/**
 * TODO
*/

void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t old_size;

    if (size == 0)
    {
        free(ptr);
        return (NULL);
    }

    if (ptr == NULL)
    {
        return (malloc(size));
    }

    new_ptr = malloc(size);
    if (new_ptr == NULL)
    {
        return (NULL);
    }

    old_size = sizeof(ptr);
    if (size <= old_size)
    {
        old_size = size;
    }

    _memcpy(new_ptr, ptr, old_size);
    free(ptr);

    return (new_ptr);
}

/**
 * TODO
*/
void *_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
	size_t i;

    for (i = 0; i < n; i++)
    {
        d[i] = s[i];
    }

    return (dest);
}
