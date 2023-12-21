#include "secondmain.h"

/**
 * reapted_char - counts the repetitions of a char
 *
 * @tip: input string
 * @a: index
 * Return: repetitions
 */
int reapted_charac(char *tip, int a)
{
	if (*(tip - 1) == *tip)
		return (reapted_charac(tip - 1, a + 1));

	return (a);
}

/**
 * error_sep_op - finds syntax errors
 *
 * @tip: input string
 * @a: index
 * @end: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int error_sep_op(char *tip, int a, char end)
{
	int strng_count;

	strng_count = 0;
	if (*tip == '\0')
		return (0);

	if (*tip == ' ' || *tip == '\t')
		return (error_sep_op(tip + 1, a + 1, end));

	if (*tip == ';')
		if (end == '|' || end == '&' || end == ';')
			return (a);

	if (*tip == '|')
	{
		if (end == ';' || end == '&')
			return (a);

		if (end == '|')
		{
			strng_count = reapted_charac(tip, 0);
			if (strng_count == 0 || strng_count > 1)
				return (a);
		}
	}

	if (*tip == '&')
	{
		if (end == ';' || end == '|')
			return (a);

		if (end == '&')
		{
			strng_count = reapted_charac(tip, 0);
			if (strng_count == 0 || strng_count > 1)
				return (a);
		}
	}

	return (error_sep_op(tip + 1, a + 1, *tip));
}

/**
 * festive_charac - finds index of the first char
 *
 * @tip: input string
 * @a: index
 * Return: 1 if there is an error. 0 in other case.
 */
int festive_charac(char *tip, int *a)
{

	for (*a = 0; tip[*a]; *a += 1)
	{
		if (tip[*a] == ' ' || tip[*a] == '\t')
			continue;

		if (tip[*a] == ';' || tip[*a] == '|' || tip[*a] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * prnt_syntax_error - prints when a syntax error is found
 *
 * @datash: data structure
 * @take_in: input string
 * @a: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void prnt_syntax_error(data_shell *datash, char *take_in, int a, int bool)
{
	char *str_msg, *str_msg2, *str_msg3, *err, *measure;
	int length1;

	if (take_in[a] == ';')
	{
		if (bool == 0)
			str_msg = (take_in[a + 1] == ';' ? ";;" : ";");
		else
			str_msg = (take_in[a - 1] == ';' ? ";;" : ";");
	}

	if (take_in[a] == '|')
		str_msg = (take_in[a + 1] == '|' ? "||" : "|");

	if (take_in[a] == '&')
		str_msg = (take_in[a + 1] == '&' ? "&&" : "&");

	str_msg2 = ": Syntax error: \"";
	str_msg3 = "\" unexpected\n";
	measure = aux_frmitoa(datash->meas_ure);
	length1 = _strnglength(datash->av[0]) + _strnglength(measure);
	length1 += _strnglength(str_msg) + _strnglength(str_msg2) + _strnglength(str_msg3) + 2;

	err = malloc(sizeof(char) * (length1 + 1));
	if (err == 0)
	{
		free(measure);
		return;
	}
	_strngcopy(err, datash->av[0]);
	_strngcat(err, ": ");
	_strngcat(err, measure);
	_strngcat(err, str_msg2);
	_strngcat(err, str_msg);
	_strngcat(err, str_msg3);
	_strngcat(err, "\0");

	write(STDERR_FILENO, err, length1);
	free(err);
	free(measure);
}

/**
 * chek_syn_err - intermediate function to
 * find and print a syntax error
 *
 * @datash: data structure
 * @take_in: input string
 * Return: 1 if there is an error. 0 in other case
 */
int chck_syn_err(data_shell *datash, char *take_in)
{
	int str_beg = 0;
	int str_f_char = 0;
	int d = 0;

	str_f_char = festive_charac(take_in, &str_beg);
	if (str_f_char == -1)
	{
		prnt_syntax_error(datash, take_in, str_beg, 0);
		return (1);
	}

	d = error_sep_op(take_in + str_beg, 0, *(take_in + str_beg));
	if (d != 0)
	{
		prnt_syntax_error(datash, take_in, str_beg + d, 1);
		return (1);
	}

	return (0);
}
