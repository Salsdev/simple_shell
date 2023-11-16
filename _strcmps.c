#include "shell.h"
/**
 * _strcmps - Compare two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: 0 if the strings are equal, otherwise the difference
 * between the ASCII values of the first non-matching characters.
 */
int _strcmps(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
return (0);
}
