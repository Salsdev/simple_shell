#include "shell.h"

/**
 * _toi - convert string to integer
 * @s: the string
 * Return: integer
 */

int _toi(char *s)
{
	unsigned int num = 0, sign = 1, started = 0;

	while (*s)
	{
		if (started && !(*s >= '0' && *s <= '9'))
			break;
		if (*s == '-')
			sign *= -1;
		if ((*s >= '0' && *s <= '9'))
		{
			started = 1;
			num =  num * 10 + (int)*s - 48;
		}
		s++;
	}
	return (sign * num);
}
