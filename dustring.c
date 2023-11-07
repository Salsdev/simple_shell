#include "shell.h"

/**
 * _strdup - duplicate the string
 * @str: string to be duplicated
 * Return: duplicated string
 */

char *_strdup(char *str)
{

	char *copy, *_copy;

	if (!str)
		return (NULL);
	copy = _malloc((_lenstring(str) + 1) * sizeof(char));
	_copy = copy;

	while (*str)
		*_copy = *str, str += 1, _copy += 1;

	*_copy = '\0';
	return (copy);
}
