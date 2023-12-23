#include "secondmain.h"

/**
 * exe_ln - This program finds builtins and commands
 * @datash: data relevant (args)
 * Return: 1 on success.
 */

int exe_ln(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->arguments[0] == NULL)
		return (1);

	builtin = get_builtOOBin(datash->arguments[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exe(datash));
}
