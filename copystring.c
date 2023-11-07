#include "shell.h"

/**
 * *_copystring - copy string
 * @dest: destination  of string
 * @src: source of string
 *
 * Return: dest
 */

char *_copystring(char *dest, char *src)
{
	char *ptr = dest;

	if (!dest)
		return (NULL);
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ptr);
}
