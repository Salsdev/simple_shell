#include "shell.h"

/**
 * _tokstring - tokenize string
 * @str: string to be tokenized
 * @delimeter: token delimiter
 * @whichf: which comp2string to use, 0 for altcustring, and 1 for comp2string
 *
 * Return:  character pointer to the current delimited token
 */
char *_tokstring(char *str, const char *delimeter, int whichf)
{
	static char *save;
	char *_new = NULL;
	int i = 0, (*func)(const char *, const char *), loc, in_quotes = 0;

	func = (whichf == 0) ? _strcmpd : _strcmps;
		loc = (whichf) ? _lenstring(delimeter) - 1 : 0;
	if (!str || !*str)
	{
		if (!save || !*save)
			return (NULL);
		while (in_quotes || (func(save + i, delimeter) != 1 && *(save + i) != '\0'))
		{
			if (*(save + i) == '\'' || *(save + i) == '\"')
				in_quotes = !in_quotes;
			i++;
		}
		if (*(save + i) == '\0')
		{
			_new = save, save = NULL;
			return (_new);
		}
		_new = save;
		*(save + i) = '\0';
		save = save + i + loc + 1;
		return (_new);
	}
	while (in_quotes || (func(str + i, delimeter) != 1 && *(str + i) != '\0'))
	{
		if (*(str + i) == '\'' || *(str + i) == '\"')
			in_quotes = !in_quotes;
		i++;
	}
	if (*(str + i) == '\0')
	{
		save = NULL;
		return (str);
	}
	save = str + i + loc + 1;
	*(str + i) = '\0';
	return (str);
}
