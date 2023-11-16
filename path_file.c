#include "shell.h"

/**
 * get_file_path - get PATH
 * @name: name of command
 * Return: a full path of name or name it self on failure
 */

char *get_file_path(char *name)
{
	char *PATH = _getenv("PATH"), *fpath = NULL;
	char *tokenized = _tokstring(PATH, ":", 0);
	struct stat fileinfo;

	if (!name)
		return (NULL);
	if (*name == '/' || *name == '.')
	{
		fpath = _malloc(_lenstring(name) * sizeof(char) + 1);
		_copystring(fpath, name);
		return (fpath);
	}
	while (tokenized)
	{
		fpath = _malloc((_lenstring(tokenized) +
					_lenstring(name) + 1) * sizeof(char) + 1);
		_copystring(fpath, tokenized);
		_catstring(fpath, "/");
		_catstring(fpath, name);
		if (!stat(fpath, &fileinfo))
			return (fpath);
		free(fpath);
		tokenized = _tokstring(NULL, ":", 0);
	}
	fpath = _malloc(_lenstring(name) * sizeof(char) + 1);
	_copystring(fpath, name);
	return (fpath);
}
