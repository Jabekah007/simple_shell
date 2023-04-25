#include "shell.h"

/**
 **_memset - fills a block of memory with a specified value
 *@s: pointer to the memory block to be filled
 *@b: the byte to fill *s with
 *@n: number of bytes to be set to the value
 *Return: (s) a pointer to the memory block s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees a dynamically allocated array of strings
 * @pp: pointer to the array of strings to be freed
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to the previously allocated block of memory
 * @old_size: size of the old memory block in bytes
 * @new_size: size of the new memory block in bytes
 *
 * Return: pointer to the reallocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

