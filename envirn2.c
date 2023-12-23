#include "secondmain.h"

/**
 * cpy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @val: value (env or alias)
 *
 * Return: new env or alias.
 */
char *cpy_info(char *name, char *val)
{
	char *strng_new;
	int length_nm, len_value_new, length1;

	length_nm = _strnglength(name);
	len_value_new = _strnglength(val);
	length1 = length_nm + len_value_new + 2;
	strng_new = malloc(sizeof(char) * (length1));
	_strngcopy(strng_new, name);
	_strngcat(strng_new, "=");
	_strngcat(strng_new, val);
	_strngcat(strng_new, "\0");

	return (strng_new);
}

/**
 * set_environ - sets an environment variable
 *
 * @name: name of the environment variable
 * @val: value of the environment variable
 * @datash: data structure (environ)
 * Return: no return
 */
void set_envirn(char *name, char *val, data_shell *datash)
{
	int a;
	char *va_environ, *name_env_iron;

	for (a = 0; datash->_evirnment[a]; a++)
	{
		va_environ = _strngduplicate(datash->_evirnment[a]);
		name_env_iron = _strngtoken(va_environ, "=");
		if (_strngcompare(name_env_iron, name) == 0)
		{
			free(datash->_evirnment[a]);
			datash->_evirnment[a] = cpy_info(name_env_iron, val);
			free(va_environ);
			return;
		}
		free(va_environ);
	}

	datash->_evirnment = _reallocatedp(datash->_evirnment, a,
			sizeof(char *) * (a + 2));
	datash->_evirnment[a] = cpy_info(name, val);
	datash->_evirnment[a + 1] = NULL;
}

/**
 * _stenviron - compares env variables names
 * with the name passed.
 * @datash: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _stenviron(data_shell *datash)
{

	if (datash->arguments[1] == NULL || datash->arguments[2] == NULL)
	{
		get_err(datash, -1);
		return (1);
	}

	set_envirn(datash->arguments[1], datash->arguments[2], datash);

	return (1);
}

/**
 * _unstenviron - deletes a environment variable
 *
 * @datash: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unstenviron(data_shell *datash)
{
	char **realoc_evirnment;
	char *va_environ, *name_env_iron;
	int a, b, c;

	if (datash->arguments[1] == NULL)
	{
		get_err(datash, -1);
		return (1);
	}
	c = -1;
	for (a = 0; datash->_evirnment[a]; a++)
	{
		va_environ = _strngduplicate(datash->_evirnment[a]);
		name_env_iron = _strngtoken(va_environ, "=");
		if (_strngcompare(name_env_iron, datash->arguments[1]) == 0)
		{
			c = a;
		}
		free(va_environ);
	}
	if (c == -1)
	{
		get_err(datash, -1);
		return (1);
	}
	realoc_evirnment = malloc(sizeof(char *) * (a));
	for (a = b = 0; datash->_evirnment[a]; a++)
	{
		if (a != c)
		{
			realoc_evirnment[b] = datash->_evirnment[a];
			b++;
		}
	}
	realoc_evirnment = NULL;
	free(datash->_evirnment[c]);
	free(datash->_evirnment);
	datash->_evirnment = realoc_evirnment;
	return (1);
}
