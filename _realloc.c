#include "shell.h"

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @size: size of the memory block to be reallocated
 * Return: pointer to the reallocated memory
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
 * _memcpy - copies memory area
 * @dest: pointer to the destination memory area
 * @src: pointer to the source memory area
 * @n: number of bytes to be copied
 * Return: pointer to the destination memory area
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
/**
 * _memmove - copies memory area
 * @dest: pointer to the destination memory area
 * @src: pointer to the source memory area
 * @n: number of bytes to be copied
 * Return: pointer to the destination memory area
*/
void *_memmove(void *dest, const void *src, size_t n)
{
	char *csrc = (char *)src;
	char *cdest = (char *)dest;
	char *temp = malloc(sizeof(char) * n);
	int i = 0;

	if (temp == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < (int)n; i++)
	{
		temp[i] = csrc[i];
	}

	for (i = 0; i < (int)n; i++)
	{
		cdest[i] = temp[i];
	}

	free(temp);
	return (dest);
}
