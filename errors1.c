#include "shell.h"

/**
 * _erratoi -it  changes a string to an integer
 * @s: represent string to be converted
 * Return: returns 0 if string has no number, changes number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int h = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (h = 0;  s[h] != '\0'; h++)
	{
		if (s[h] >= '0' && s[h] <= '9')
		{
			result *= 10;
			result += (s[h] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - it prints an error message
 * @info: it displays the parameter & return info struct
 * @estr: The string containing specified error type
 * Return: returns 0 if string has no number, changes number otherwise
 * -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - This function prints a decimal number (base 10)
 * @input: takes input
 * @fd: this represent filedescriptor
 *
 * Return: prints number of characters
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int v, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (v = 1000000000; v > 1; v /= 10)
	{
		if (_abs_ / v)
		{
			__putchar('0' + current / v);
			count++;
		}
		current %= v;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - it converter function, a clone of itoa
 * @num: Represent number
 * @base: Represent base
 * @flags: It takes argument flags
 *
 * Return: returns a string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char symb = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		symb = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (symb)
		*--ptr = symb;
	return (ptr);
}

/**
 * remove_comments -It  function replaces first instance of '#' with '\0'
 * @buf: It address of the string to modify
 *
 * Return: returns  0;
 */
void remove_comments(char *buf)
{
	int b;

	for (b = 0; buf[b] != '\0'; b++)
		if (buf[b] == '#' && (!b || buf[b - 1] == ' '))
		{
			buf[b] = '\0';
			break;
		}
}

