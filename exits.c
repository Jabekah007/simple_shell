#include "shell.h"

/**
 * _strncpy - copies a specified number of characters
 * from a source string to a destination string
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * @n: maximum number of characters to be copied
 * Return: pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
* _strncat - concatenates a specified number of characters from
* a source string to the end of a destination string
* @dest: pointer to the destination string
* @src: pointer to the source string
* @n: maximum number of characters to be concatenated
* Return: pointer to the destination string
*/
char *_strncat(char *dest, char *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}


	if (b < n)
		dest[a] = '\0';
	return (s);
}

/**
 * _strchr - locates the first occurrence of a specified character in a string
 * @s: pointer to the string to be searched
 * @c: character to be located
 * Return: a pointer to the located character in the string or
 * NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
