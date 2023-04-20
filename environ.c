#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info:it Arrange with potential arguments.
 * used to retain the prototype of the * constant function.
 * Return: It Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - it gets the value of an environ variable
 * @info: it contains potential arguments. Used to maintain
 * @name: it contains env var name
 *
 * Return:it returns a value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, name);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv -It  starts a new environment variable,
 *             or changes an existing one
 * @info: Arrangement with potential arguments.
 * used to retain the prototype of the * constant function.
 *  Return:It Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv -It  removes an environment variable
 * @info: Arrangement with potential arguments.
 * used to retain the prototype of the * constant function.
 *  Return:It Always 0
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}

/**
 * populate_env_list -this increases env linked list
 * @info: Arrangement with potential arguments.
 * used to retain the prototype of the * constant function.
 * Return:It Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);
	info->env = node;
	return (0);
}

