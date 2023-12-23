#include "secondmain.h"

/**
 * liberate_data - This program data structure
 *
 * @datash: data structure
 * Return: no return
 */

void liberate_data(data_shell *datash)
{
	unsigned int i = 0;

	while (datash->_evirnment[i])
	{
		free(datash->_evirnment[i]);
		i++;
	}

	free(datash->_evirnment);
	free(datash->pid);
}

/**
 * apply_data - This program Initialize dt structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */

void apply_data(data_shell *datash, char **av)
{
	unsigned int b;

	datash->av = av;
	datash->take_in = NULL;
	datash->arguments = NULL;
	datash->posture = 0;
	datash->meas_ure = 1;

	for (b = 0; environ[b]; b++)
		;

	datash->_evirnment = malloc(sizeof(char *) * (b + 1));

	for (b = 0; environ[b]; b++)
	{
		datash->_evirnment[b] = _strngduplicate(environ[b]);
	}

	datash->_evirnment[b] = NULL;
	datash->pid = aux_frmitoa(getpid());
}

/**
 * main - The program's Entry
 *
 * @agc: argument count
 * @agv: argument vector
 *
 * Return: 0 on success.
 */

int main(int agc, char **agv)
{
	data_shell datash;
	(void) agc;

	signal(SIGINT, gt_signdint);
	apply_data(&datash, agv);
	shell_loop(&datash);
	liberate_data(&datash);
	if (datash.posture < 0)
		return (255);
	return (datash.posture);
}
