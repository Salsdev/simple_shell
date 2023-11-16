#include "shell.h"
/**
 * _strcmpd - Compare two strings lexicographically.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Description: This function compares two strings lexicographically and
 * returns an integer representing the difference between the ASCII values
 * of the first non-matching characters.
 *
 * Return: 0 if the strings are equal, otherwise the difference
 * between the ASCII values of the first non-matching characters.
 */

int _strcmpd(const char *s1, const char *s2)
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
/**
 * Return: 0 when both strings are equal
 **/
return (0);
}
