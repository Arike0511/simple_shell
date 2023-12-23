#include "secondmain.h"

/**
 * get_err - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @evaluate: error value
 * Return: error
 */
int get_err(data_shell *datash, int evaluate)
{
	char *nw_err;

	switch (evaluate)
	{
	case -1:
		nw_err = err_env(datash);
		break;
	case 126:
		nw_err = error_pt_126(datash);
		break;
	case 127:
		nw_err = err_abs(datash);
		break;
	case 2:
		if (_strngcompare("exit", datash->arguments[0]) == 0)
			nw_err = error_dprt_shell(datash);
		else if (_strngcompare("cd", datash->arguments[0]) == 0)
			nw_err = err_get_cdirec(datash);
		break;
	}

	if (nw_err)
	{
		write(STDERR_FILENO, nw_err, _strnglength(nw_err));
		free(nw_err);
	}

	datash->posture = evaluate;
	return (evaluate);
}
