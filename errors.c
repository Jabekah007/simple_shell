#include "shell.h"

/**
 *_eputs - It prints an input string
 * @str: it is the string to be printed
 *
 * Return: returns nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 * _eputchar - it writes the character c to stderr
 * @c: it print characters
 *
 * Return: returns 1 on success.
 * when error occurs, it returns -1, and errno is set well.
 */
int _eputchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 * _putfd - It writes the character c to given fd
 * @c: it print characters
 * @fd: it represent filedecriptors
 *
 * Return: On success 1.
 * when error occurs, it returns -1, and errno is set well.
 */
int _putfd(char c, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 *_putsfd -It prints an input string
 * @str: it print string
 * @fd: it represent filedecriptors
 *
 * Return: it returns the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int k = 0;

	if (!str)
		return (0);
	while (*str)
	{
		k += _putfd(*str++, fd);
	}
	return (k);
}

