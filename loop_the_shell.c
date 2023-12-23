#include "secondmain.h"

/**
 * without_comment - This program deletes comme from the input
 * @in: input string
 * Return: input without comments
 */

char *wthot_com(char *in)
{
	int a, to_go;

	to_go = 0;
	for (a = 0; in[a]; a++)
	{
		if (in[a] == '#')
		{
			if (a == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[a - 1] == ' ' || in[a - 1] == '\t' || in[a - 1] == ';')
				to_go = a;
		}
	}

	if (to_go != 0)
	{
		in = _reallocated(in, a, to_go + 1);
		in[to_go] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of the shell
 * @datash: data relevant (av, input, args)
 * Return: no return.
 */

void shell_loop(data_shell *datash)
{
	int loop, i_eof;
	char *in_you_go;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		in_you_go = rd_line(&i_eof);
		if (i_eof != -1)
		{
			in_you_go = wthot_com(in_you_go);
			if (in_you_go == NULL)
				continue;

			if (chck_syn_err(datash, in_you_go) == 1)
			{
				datash->posture = 2;
				free(in_you_go);
				continue;
			}
			in_you_go = rep_varble(in_you_go, datash);
			loop = split_cmds(datash, in_you_go);
			datash->meas_ure += 1;
			free(in_you_go);
		}
		else
		{
			loop = 0;
			free(in_you_go);
		}
	}
}
