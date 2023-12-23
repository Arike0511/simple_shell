#include "secondmain.h"

/**
 * err_environ - A program that brings  error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: print error message.
 */

char *err_env(data_shell *datash)
{
	int gtlen;
	char *prn_err;
	char *veron_strng;
	char *messg;

	veron_strng = aux_frmitoa(datash->meas_ure);
	messg = ": Unable to add/remove from environment\n";
	gtlen = _strnglength(datash->av[0]) + _strnglength(veron_strng);
	gtlen += _strnglength(datash->arguments[0]) + _strnglength(messg) + 4;
	prn_err = malloc(sizeof(char) * (gtlen + 1));

	if (prn_err == 0)
	{
		free(prn_err);
		free(veron_strng);
		return (NULL);
	}

	_strngcopy(prn_err, datash->av[0]);
	_strngcat(prn_err, ": ");
	_strngcat(prn_err, veron_strng);
	_strngcat(prn_err, ": ");
	_strngcat(prn_err, datash->arguments[0]);
	_strngcat(prn_err, messg);
	_strngcat(prn_err, "\0");
	free(veron_strng);

	return (prn_err);
}

/**
 * err_pt_126 - A program that brings
 * error message for path and failure denied permission.
 * @datash: This gets data relevant (counter, arguments).
 *
 * Return: The error string.
 */

char *error_pt_126(data_shell *datash)
{
	int gt_len;
	char *veron_strng;
	char *prn_err;

	veron_strng = aux_frmitoa(datash->meas_ure);
	gt_len = _strnglength(datash->av[0]) + _strnglength(veron_strng);
	gt_len += _strnglength(datash->arguments[0]) + 24;
	prn_err = malloc(sizeof(char) * (gt_len + 1));
	if (prn_err == 0)
	{
		free(prn_err);
		free(veron_strng);
		return (NULL);
	}
	_strngcopy(prn_err, datash->av[0]);
	_strngcat(prn_err, ": ");
	_strngcat(prn_err, veron_strng);
	_strngcat(prn_err, ": ");
	_strngcat(prn_err, datash->arguments[0]);
	_strngcat(prn_err, ": Permission denied\n");
	_strngcat(prn_err, "\0");
	free(veron_strng);

	return (prn_err);
}
