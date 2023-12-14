#include "secondmain.h"

/**
 * exit_theshell - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int quit_theshell(data_shell *datash)
{
	unsigned int newstatus;
	int is_figures;
	int string_len;
	int huge_number;

	if (datash->arguments[1] != NULL)
	{
		newstatus = _atoi(datash->arguments[1]);
		is_figures = _isdgt(datash->arguments[1]);
		string_len = _strnglength(datash->arguments[1]);
		huge_number = newstatus > (unsigned int)INT_MAX;
		if (!is_figures || string_len > 10 || huge_number)
		{
			get_err(datash, 2);
			datash->posture = 2;
			return (1);
		}
		datash->posture = (newstatus % 256);
	}
	return (0);
}
