#include "secondmain.h"

/**
 * ax_assist_envir - A program that helps
 * information for the builtin env
 * Return: no return
 */

void aux_asst_env(void)
{
	char *gvhelp = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));

}

/**
 * ax_assist_setenver - A program that helps
 * information for the builtin setenv
 * Return: no return
 */

void aux_asst_setenv(void)
{

	char *gvhelp = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "int replace)\n\t";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
}

/**
 * ax_assist_unsetenver - This program helps
 * information for the builtin unsetenv
 * Return: no return
 */

void aux_asst_unseten(void)
{
	char *gvhelp = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
}

/**
 * ax_assist_gen - Entry point for help
 * information for the help builtin
 * Return: no return
 */

void ax_asst_gen(void)
{
	char *gvhelp = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "unsetenv [variable]\n";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
}

/**
 * ax_asst_dprt - This proograms helps
 * information fot the builint exit
 * Return: no return
 */

void ax_asst_dprt(void)
{
	char *gvhelp = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
	gvhelp = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, gvhelp, _strnglength(gvhelp));
}
