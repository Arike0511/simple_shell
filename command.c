#include "secondmain.h"

/**
 * cd_dt - This program  changes to th
 * e parent directory
 * @datash: data relevant (enviroment)
 * Return: no return
 */

void cd_dt(data_shell *datash)
{
	char printwd[PATH_MAX];
	char *direc, *cp_printwd, *cp_strtok_printwd;

	getcwd(printwd, sizeof(printwd));
	cp_printwd = _strngduplicate(printwd);
	set_envirn("OLDPWD", cp_printwd, datash);
	direc = datash->arguments[1];
	if (_strngcompare(".", direc) == 0)
	{
		set_envirn("PWD", cp_printwd, datash);
		free(cp_printwd);
		return;
	}
	if (_strngcompare("/", cp_printwd) == 0)
	{
		free(cp_printwd);
		return;
	}
	cp_strtok_printwd = cp_printwd;
	rever_strng(cp_strtok_printwd);
	cp_strtok_printwd = _strngtoken(cp_strtok_printwd, "/");
	if (cp_strtok_printwd != NULL)
	{
		cp_strtok_printwd = _strngtoken(NULL, "\0");

		if (cp_strtok_printwd != NULL)
			rever_strng(cp_strtok_printwd);
	}
	if (cp_strtok_printwd != NULL)
	{
		chdir(cp_strtok_printwd);
		set_envirn("PWD", cp_strtok_printwd, datash);
	}
	else
	{
		chdir("/");
		set_envirn("PWD", "/", datash);
	}
	datash->posture = 0;
	free(cp_printwd);
}

/**
 * cd_to - A program that changes to a
 * directory given by the user
 * @datash: data relevant (directories)
 * Return: no return
 */

void cd_to(data_shell *datash)
{
	char printwd[PATH_MAX];
	char *direc, *cp_printwd, *cp_direc;

	getcwd(printwd, sizeof(printwd));

	direc = datash->arguments[1];
	if (chdir(direc) == -1)
	{
		get_err(datash, 2);
		return;
	}

	cp_printwd = _strngduplicate(printwd);
	set_envirn("OLDPWD", cp_printwd, datash);

	cp_direc = _strngduplicate(direc);
	set_envirn("PWD", cp_direc, datash);

	free(cp_printwd);
	free(cp_direc);

	datash->posture = 0;

	chdir(direc);
}

/**
 * cd_fro - A program changes to
 * the previous directory
 * @datash: data relevant (environ)
 * Return: no return
 */

void cd_fro(data_shell *datash)
{
	char printwd[PATH_MAX];
	char *p_printwd, *p_oldprintwd, *cp_printwd, *cp_oldprintwd;

	getcwd(printwd, sizeof(printwd));
	cp_printwd = _strngduplicate(printwd);

	p_oldprintwd = _gtenv("OLDPWD", datash->_evirnment);

	if (p_oldprintwd == NULL)
		cp_oldprintwd = cp_printwd;
	else
		cp_oldprintwd = _strngduplicate(p_oldprintwd);

	set_envirn("OLDPWD", cp_printwd, datash);

	if (chdir(cp_oldprintwd) == -1)
		set_envirn("PWD", cp_printwd, datash);
	else
		set_envirn("PWD", cp_oldprintwd, datash);

	p_printwd = _gtenv("PWD", datash->_evirnment);

	write(STDOUT_FILENO, p_printwd, _strnglength(p_printwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_printwd);
	if (p_oldprintwd)
		free(cp_oldprintwd);

	datash->posture = 0;

	chdir(p_printwd);
}

/**
 * cd_to_org - This program changes to home directory
 * @datash: data relevant (environ)
 * Return: no return
 */

void cd_to_org(data_shell *datash)
{
	char *p_printwd, *origin;
	char printwd[PATH_MAX];

	getcwd(printwd, sizeof(printwd));
	p_printwd = _strngduplicate(printwd);

	origin = _gtenv("HOME", datash->_evirnment);

	if (origin == NULL)
	{
		set_envirn("OLDPWD", p_printwd, datash);
		free(p_printwd);
		return;
	}

	if (chdir(origin) == -1)
	{
		get_err(datash, 2);
		free(p_printwd);
		return;
	}

	set_envirn("OLDPWD", p_printwd, datash);
	set_envirn("PWD", origin, datash);
	free(p_printwd);
	datash->posture = 0;
}
