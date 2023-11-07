#include "shell.h"

/**
 * find_tok_occ - find no. of occurences of token
 * @str: string to be searched
 * @tof: string to find
 *
 * Return: number of times delimiter occur
 */

int find_tok_occ(char *str, char *tof)
{
	char *tokenized = NULL, *new = NULL;
	int i = 0;

	if (_lenstring(tof) > _lenstring(str))
		return (0);
	new = _strdup(str);
	tokenized = _tokstring(new, tof, 1);
	while (tokenized != NULL)
	{
		i++;
		tokenized = _tokstring(NULL, tof, 1);
	}
	free(new);
	if (_strcmps(str + _lenstring(str) - _lenstring(tof), tof) == 1)
		i++;
	return (i - 1);
}
/**
 * find_n_rep - find and replace part of string
 * @str: string to be parsed
 * @torep: string to be replaced
 * @repwith: sting to replace
 *
 * Return: 0 on sucess and -1 on faliure
 */

int find_n_rep(char **str, char *torep, char *repwith)
{
	char *tokenized = NULL, *tmp, *new = _malloc(1);
	int rep = 0, tor = find_tok_occ(*str, torep), newlen = 0;

	tokenized = _tokstring(*str, torep, 1);
	*new = '\0';
	while (tokenized != NULL)
	{
		newlen = _lenstring(new) + _lenstring(tokenized) + _lenstring(repwith);
		tmp = _realloc(new, newlen +  2);
		new = tmp;
		_catstring(new, tokenized);
		if (rep < tor)
			_catstring(new, repwith);
		rep++, tokenized = _tokstring(NULL, torep, 1);
	}
	free(*str);
	*str = new;
	return (0);
}
