#include "shell.h"

/**
 * _catstring - concatinate two strings
 * @dest: string destination
 * @src: source of the  string
 *
 * Return: concatinated string
 */

char *_catstring(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
		*p++ = *src++;

	*p = '\0';

	return (dest);
}
