#include "shell.h"

/**
 * _myexit - It exits the shell
 * @info: Arrangement with potential arguments.
 * used to retain the prototype of the * constant function.
 * Return: if info.argv[0]!= "exit",
 * exits with the supplied exit status_atoi.c * (0).
 */
int _myexit(info_t *info)
{
	int quitcheck;

	if (info->argv[1])  /* If there is an exit parameters */
	{
		quitcheck = _erratoi(info->argv[1]);
		if (quitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - alters the process's current directory
 * @info: Arrangement with potential arguments.
 * used to retain the prototype of the * constant function.
 *  Return:It is Always 0
 */
int _mycd(info_t *info)
{
	char *v, *dir, buffer[1024];
	int chdir_retn;

	v = getcwd(buffer, 1024);
	if (!v)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_retn = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_retn = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(v);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_retn = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_retn = chdir(info->argv[1]);
	if (chdir_retn == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - alters the process's current directory
 * @info: Arrangement with potential arguments.
 * used to retain the prototype of the * constant function.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}

