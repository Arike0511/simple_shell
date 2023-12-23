#include "secondmain.h"

/**
 * get_builtOOBin - This program builtin that
 * pais the command in the arg
 * @cmd: command
 * Return: function pointer of the builtin command
 */

int (*get_builtOOBin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", quit_theshell },
		{ "setenv", _stenviron },
		{ "unsetenv", _unstenviron },
		{ "cd", cd_shell },
		{ "help", gt_asst },
		{ NULL, NULL }
	};
	int b;

	for (b = 0; builtin[b].cmmnd_nme; b++)
	{
		if (_strngcompare(builtin[b].cmmnd_nme, cmd) == 0)
			break;
	}

	return (builtin[b].f);
}
