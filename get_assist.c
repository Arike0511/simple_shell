#include "secondmain.h"

/**
 * gt_asst - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int gt_asst(data_shell *datash)
{

	if (datash->arguments[1] == 0)
		ax_asst_gen();
	else if (_strngcompare(datash->arguments[1], "setenver") == 0)
		aux_asst_setenv();
	else if (_strngcompare(datash->arguments[1], "envir") == 0)
		aux_asst_env();
	else if (_strngcompare(datash->arguments[1], "unsetenver") == 0)
		aux_asst_unseten();
	else if (_strngcompare(datash->arguments[1], "assist") == 0)
		aux_asst();
	else if (_strngcompare(datash->arguments[1], "depart") == 0)
		ax_asst_dprt();
	else if (_strngcompare(datash->arguments[1], "cdir") == 0)
		aux_asst_cd();
	else if (_strngcompare(datash->arguments[1], "alias") == 0)
		aux_asst_als();
	else
		write(STDERR_FILENO, datash->arguments[0],
		      _strnglength(datash->arguments[0]));

	datash->posture = 0;
	return (1);
}
