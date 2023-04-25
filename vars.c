#include "shell.h"

/**
 * is_chain - it test whether current char in buffer is a chain delimeter
 * @info: this is a parameter struct
 * @buf: this is  char buffer
 * @p: this is an address of current position in buffer
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t l = *p;

	if (buf[l] == '|' && buf[l + 1] == '|')
	{
		buf[l] = 0;
		l++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[l] == '&' && buf[l + 1] == '&')
	{
		buf[l] = 0;
		l++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[l] == ';') /* found end of this command */
	{
		buf[l] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = l;
	return (1);
}

/**
 * check_chain - it checks what we should
 * continue chaining based on last status
 * @info: this is the parameter struct
 * @buf: this is the char buffer
 * @p: this is the address of current position in buf
 * @i: this is the starting position in buf
 * @len: this is the length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t l = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			l = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			l = len;
		}
	}

	*p = l;
}

/**
 * replace_alias - this swaps out one of the aliases in the tokenized string.
 * @info: this is the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - it does replace vars in the tokenized string
 * @info: this is the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - it replaces string
 * @old: this is address of old string
 * @new: this is new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

