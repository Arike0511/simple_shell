#include "secondmain.h"

/**
 * chr_environ_name - compares env variables names
 * with the name passed.
 * @nameenv: name of the environment variable
 * @str_name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int chr_environ_name(const char *nameenv, const char *str_name)
{
	int b = 0;

	while (nameenv[b] != '=')
	{
		if (nameenv[b] != str_name[b])
		{
			return (0);
		}
		b++;
	}
	return (b + 1);
}

/**
 * _gtenv - get an environment variable
 * @name: name of the environment variable
 * @_environment: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_gtenv(const char *name, char **_evirnment)
{
	char *pter_eviron;
	int j, str_mov;

	/* Initialize ptr_env value */
	pter_eviron = NULL;
	str_mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (j = 0; _evirnment[j]; j++)
	{
		/* If name and env are equal */
		str_mov = chr_environ_name(_evirnment[j], name);
		if (str_mov)
		{
			pter_eviron = _evirnment[j];
			break;
		}
	}

	return (pter_eviron + str_mov);
}

/**
 * _env - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int firry, secet;

	for (firry = 0; datash->_evirnment[firry]; firry++)
	{

		for (secet = 0; datash->_evirnment[firry][secet]; secet++)
			;

		write(STDOUT_FILENO, datash->_evirnment[firry], secet);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->posture = 0;

	return (1);
}
