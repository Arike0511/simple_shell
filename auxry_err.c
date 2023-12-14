#include "secondmain.h"

/**
 * strconcat_cd - function that concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @err_msg: message to print
 * @err: output message
 * @veron_string: counter lines
 * Return: error message
 */
char *strconcat_cd(data_shell *datash, char *err_msg,
char *err, char *veron_string)
{
	char *ill_flag;

	_strngcopy(err, datash->av[0]);
	_strngcat(err, ": ");
	_strngcat(err, veron_string);
	_strngcat(err, ": ");
	_strngcat(err, datash->arguments[0]);
	_strngcat(err, err_msg);
	if (datash->arguments[1][0] == '-')
	{
		ill_flag = malloc(3);
		ill_flag[0] = '-';
		ill_flag[1] = datash->arguments[1][1];
		ill_flag[2] = '\0';
		_strngcat(err, ill_flag);
		free(ill_flag);
	}
	else
	{
		_strngcat(err, datash->arguments[1]);
	}

	_strngcat(err, "\n");
	_strngcat(err, "\0");
	return (err);
}

/**
 * err_gt_cd - error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *err_gt_cd(data_shell *datash)
{
	int length1, length_ident;
	char *err, *veron_strng, *err_msg;

	veron_strng = aux_frmitoa(datash->meas_ure);
	if (datash->arguments[1][0] == '-')
	{
		err_msg = ": Illegal option ";
		length_ident = 2;
	}
	else
	{
		err_msg = ": can't cd to ";
		length_ident = _strnglength(datash->arguments[1]);
	}

	length1 = _strnglength(datash->av[0]) + _strnglength(datash->arguments[0]);
	length1 += _strnglength(veron_strng) + _strnglength(err_msg) + length_ident + 5;
	err = malloc(sizeof(char) * (length1 + 1));

	if (err == 0)
	{
		free(veron_strng);
		return (NULL);
	}

	err = strconcat_cd(datash, err_msg, err, veron_strng);

	free(veron_strng);

	return (err);
}

/**
 * err_absent - generic error message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *err_absent(data_shell *datash)
{
	int length1;
	char *error;
	char *veron_strng;

	veron_strng = aux_frmitoa(datash->meas_ure);
	length1 = _strnglength(datash->av[0]) + _strnglength(veron_strng);
	length1 += _strnglength(datash->arguments[0]) + 16;
	error = malloc(sizeof(char) * (length1 + 1));
	if (error == 0)
	{
		free(error);
		free(veron_strng);
		return (NULL);
	}
	_strngcopy(error, datash->av[0]);
	_strngcat(error, ": ");
	_strngcat(error, veron_strng);
	_strngcat(error, ": ");
	_strngcat(error, datash->arguments[0]);
	_strngcat(error, ": not found\n");
	_strngcat(error, "\0");
	free(veron_strng);
	return (error);
}

/**
 * err_depart_shell - generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *err_depart_shell(data_shell *datash)
{
	int length1;
	char *error;
	char *veron_strng;

	veron_strng = aux_frmitoa(datash->meas_ure);
	length1 = _strnglength(datash->av[0]) + _strnglength(veron_strng);
	length1 += _strnglength(datash->arguments[0]) + _strnglength(datash->arguments[1]) + 23;
	error = malloc(sizeof(char) * (length1 + 1));
	if (error == 0)
	{
		free(veron_strng);
		return (NULL);
	}
	_strngcopy(error, datash->av[0]);
	_strngcat(error, ": ");
	_strngcat(error, veron_strng);
	_strngcat(error, ": ");
	_strngcat(error, datash->arguments[0]);
	_strngcat(error, ": Illegal number: ");
	_strngcat(error, datash->arguments[1]);
	_strngcat(error, "\n\0");
	free(veron_strng);

	return (error);
}
