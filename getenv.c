#include "shell.h"

/**
 * get_environ -It returns the string array copy of our environ
 * @info: It is a Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: returns 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - It removes an environment variable
 * @info: It is a structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 to delete, 0 otherwise
 * @var: it is the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t j = 0;
	char *q;

	if (!node || !var)
		return (0);

	while (node)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), j);
			j = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		j++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *nod;
	char *q;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (nod)
	{
		p = starts_with(nod->str, var);
		if (q && *q == '=')
		{
			free(nod->str);
			nod->str = buf;
			info->env_changed = 1;
			return (0);
		}
		nod = nod->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

