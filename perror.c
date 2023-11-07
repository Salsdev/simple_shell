#include "shell.h"
#include "error.h"

/**
 * print_error - print the  error message
 * @prog:the  command
 * @cmdr: pointer to teh  error
 * @msg: error message
 *
 * Return: none
 */

void print_error(char *prog, int *cmdr, char *msg)
{
	char *numcmd;
	static int *cmdsrun;
	static char *progname;

	if (!msg)
	{
		cmdsrun =  cmdr;
		progname = prog;
		return;
	}
	if (!cmdr || !prog)
	{
		_write(-1, NULL, 0);
		_write(2, progname, _lenstring(progname) + 1);
		_write(2, ": ", 2);
		numcmd = printtoi(*cmdsrun);
		_write(2, numcmd, _lenstring(numcmd));
		free(numcmd);
		_write(2, ": ", 2);
		_write(2, prog, _lenstring(prog));
		_write(2, ": ", 2);
		_write(2, msg, _lenstring(msg));
		_write(2, "\n", 1);
		_write(2, NULL, 0);
	}
}
