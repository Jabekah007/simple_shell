#include "shell.h"

/**
 * get_history_file - it gets the history file
 * @info: it is parameter struct
 *
 * Return: it allocated string containg history file
 */

char *get_history_file(info_t *info)
{
	char *buff, *dirr;

	dirr = _getenv(info, "HOME=");
	if (!dirr)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dirr) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dirr);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * write_history - It creates a file, or appends to an existing file
 * @info:it is the parameter struct
 *
 * Return: 1 for success, else -1
 */
int write_history(info_t *info)
{
	ssize_t ff;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	ff = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (ff == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, ff);
		_putfd('\n', ff);
	}
	_putfd(BUF_FLUSH, ff);
	close(ff);
	return (1);
}

/**
 * read_history - it reads history from file
 * @info: it isthe parameter struct
 *
 * Return: it histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int j, last = 0, linecount = 0;
	ssize_t ff, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	ff = open(filename, O_RDONLY);
	free(filename);
	if (ff == -1)
		return (0);
	if (!fstat(ff, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(ff, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(ff);
	for (j = 0; j < fsize; j++)
		if (buf[j] == '\n')
		{
			buf[j] = 0;
			build_history_list(info, buf + last, linecount++);
			last = j + 1;
		}
	if (last != j)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list -it adds entry to a history linked list
 * @info:it is a  Structure containing potential arguments. Used to maintain
 * @buf: it is a buffer
 * @linecount: it is the history linecount, histcount
 *
 * Return: It is Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *nod = NULL;

	if (info->history)
		nod = info->history;
	add_node_end(&nod, buf, linecount);

	if (!info->history)
		info->history = nod;
	return (0);
}

/**
 * renumber_history -it renumbers the history linked list after changes
 * @info: it is Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *nod = info->history;
	int j = 0;

	while (nod)
	{
		nod->num = j++;
		nod = nod->next;
	}
	return (info->histcount = j);
}

