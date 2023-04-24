#include "shell.h"

/**
 * add_node - It adds a node to the start of the list
 * @head: It address of pointer to head node
 * @str:It is  str field of node
 * @num: It is node index used by history
 *
 * Return: It size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_h;

	if (!head)
		return (NULL);
	new_h = malloc(sizeof(list_t));
	if (!new_h)
		return (NULL);
	_memset((void *)new_h, 0, sizeof(list_t));
	new_h->num = num;
	if (str)
	{
		new_h->str = _strdup(str);
		if (!new_h->str)
		{
			free(new_h);
			return (NULL);
		}
	}
	new_h->next = *head;
	*head = new_h;
	return (new_h);
}

/**
 * add_node_end - it adds a node to the end of the list
 * @head: it is address of pointer to head node
 * @str: it is a str field of node
 * @num: it is a node index used by history
 *
 * Return: it is size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_nd, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_nd = malloc(sizeof(list_t));
	if (!new_nd)
		return (NULL);
	_memset((void *)new_nd, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_nd->str = _strdup(str);
		if (!new_nd->str)
		{
			free(new_nd);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_nd;
	}
	else
		*head = new_nd;
	return (new_nd);
}

/**
 * print_list_str - it is prints only the str element of a list_t linked list
 * @h: it is pointer to first node
 *
 * Return: it size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * delete_node_at_index - It deletes node at given index
 * @head: it is an address of pointer to first node
 * @index:iit is  index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int j = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (j == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - it frees all nodes of a list
 * @head_ptr: it address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_nd, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_nd = node->next;
		free(node->str);
		free(node);
		node = next_nd;
	}
	*head_ptr = NULL;
}

