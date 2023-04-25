#include "shell.h"

/**
 * **strtow - makes word divisions in a string. It ignores repeated delimiters.
 * @str: this is the input string
 * @d: this is the delimeter string
 * Return: a pointer to a collection of strings,
 * or NULL in the event of failure.
 */

char **strtow(char *str, char *d)
{
	int a, b, c, f, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (is_delim(str[a], d))
			a++;
		c = 0;
		while (!is_delim(str[a + c], d) && str[a + c])
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (f = 0; f < c; f++)
			s[b][f] = str[a++];
		s[b][f] = 0;
	}
	s[b] = NULL;
	return (s);
}

/**
 * **strtow2 - separates words from a string
 * @str: this is the input string
 * @d: this is the delimeter
 * Return: a pointer to a string array, or NULL in the event of failure.
 */
char **strtow2(char *str, char d)
{
	int a, b, c, f, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
		    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		c = 0;
		while (str[a + c] != d && str[a + c] && str[a + c] != d)
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (f = 0; f < c; f++)
			s[b][f] = str[a++];
		s[b][f] = 0;
	}
	s[b] = NULL;
	return (s);
}
