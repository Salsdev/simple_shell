#include "help.h"

/**
 * print_help - print help command
 * @arg: arguments
 * Return: none
 */

void print_help(char *arg)
{
	int fd = 1;

	_write(-1, NULL, 0);

	if (!arg)
		_write(1, ghelp, _lenstring(ghelp));
	else if (!_comp2string(arg, "help"))
		_write(1, help_h, _lenstring(help_h));
	else if (!_comp2string(arg, "set"))
		_write(1, set_h, _lenstring(set_h));
	else if (!_comp2string(arg, "unset"))
		_write(1, unset_h, _lenstring(unset_h));
	else if (!_comp2string(arg, "history"))
		_write(1, history_h, _lenstring(history_h));
	else if (!_comp2string(arg, "env"))
		_write(1, env_h, _lenstring(env_h));
	else if (!_comp2string(arg, "cd"))
		_write(1, cd_h, _lenstring(cd_h));
	else if (!_comp2string(arg, "alias"))
		_write(1, alias_h, _lenstring(alias_h));
	else if (!_comp2string(arg, "exit"))
		_write(1, exit_h, _lenstring(exit_h));
	else if (!_comp2string(arg, "setenv"))
		_write(1, set_h, _lenstring(set_h));
	else if (!_comp2string(arg, "unsetenv"))
		_write(1, unset_h, _lenstring(unset_h));
	else
	{
		_write(2, "No help found for ", 18), fd = 2;
		_write(2, arg, _lenstring(arg));
		_write(2, "\n", 1);
	}
	_write(fd, NULL, 0);
}
