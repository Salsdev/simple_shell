#include "shell.h"

/**
 * _chdir - change the current directory
 * @path:set a  new path
 * Return: 0 on sucess and 1 on failure
 */

int _chdir(char *path)
{
	int status, exitstat = 0;
	char *currentdir = _getenv("PWD"), *buf = NULL, *cdir, *msg;
	char *smn;
	size_t size = 0;

	if (!path || !_comp2string(path, "~"))
		status = chdir(_getenv("HOME"));
	else if (!_comp2string(path, "-"))
		status = chdir(_getenv("OLDPWD"));
	else
		status = chdir(path);
	if (status < 0)
	{
		errno = -3;
		msg = _malloc(_lenstring("No such file or directory ") +
				_lenstring(path) + 4);
		_copystring(msg, "No such file or directory ");
		smn = _malloc(_lenstring("cd: ") + _lenstring(path) + 4);
		_copystring(smn, "cd: "), _catstring(smn, path);
		print_error(smn, NULL, msg);
		free(msg), free(smn);
		exitstat = 1;
	}

	_setenv("OLDPWD", currentdir, 1);
	cdir = getcwd(buf, size);
	_setenv("PWD", cdir, 1);
	free(buf), free(cdir);
	return (exitstat);

}
