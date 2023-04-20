#include "shell.h"

/**
 * _myhistory -Displays history list with line numbers
 * beginning 0 before each command.
 * @info: Arrangement with potential arguments.
 * used to retain the prototype of the * constant function.
 * Return: It is Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - It sets alias to string
 * @info: This is parameter struct
 * @str: this represent string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *q, z;
	int ret;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	z = *q;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = z;
	return (ret);
}

/**
 * set_alias - It sets alias to string
 * @info: this is a parameter struct
 * @str: this is the string alias
 *
 * Return: t is IAlways 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *k;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	if (!*++k)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *k = NULL, *b = NULL;

	if (node)
	{
		k = _strchr(node->str, '=');
		for (b = node->str; b <= k; b++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - it imitates the alias builtin (man alias)
 * @info: Arrangement with potential arguments.
 * used to retain the prototype of the * constant function.
 *  Return: it is Always 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		p = _strchr(info->argv[j], '=');
		if (q)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}

