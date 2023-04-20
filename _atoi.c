/**
 * is_delim - This checks if character is a delimeter
 * @c: it is use to check char
 * @delim: this is use to represent delimeter string
 * Return: 1 if it is true and  0 if it is false
 */
int is_delim(char c, char *delim)
{
	for (; *delim; delim++)
{
	if (*delim == c)
		return (1);
}

	return (0);
}

/**
 *_isalpha - This checks for alphabetic character
 *@c: it represent a character to input
 *Return: 1 if  c is alphabetic or 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - This converts a string to an integer
 *@s: it represent string to be converted
 *Return: 0 if no numbers in string or converted number otherwise
 */

int _atoi(char *s)
{
	int i, symb = 1, flag = 0, output;
	unsigned int endpoint = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			symb *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			endpoint *= 10;
			endpoint += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (symb == -1)
		output = -endpoint;
	else
		output = endpoint;

	return (output);
}


