#include "secondmain.h"

/**
 * ax_assist - Help information for the builtin help.
 * Return: no return
 */
void aux_asst(void)
{
	char *nw_gt_help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, nw_gt_help, _strnglength(nw_gt_help));
	nw_gt_help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, nw_gt_help, _strnglength(nw_gt_help));
	nw_gt_help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, nw_gt_help, _strnglength(nw_gt_help));
}
/**
 * ax_assist_alias - Help information for the builtin alias.
 * Return: no return
 */
void aux_asst_als(void)
{
	char *nw_gt_help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, nw_gt_help, _strnglength(nw_gt_help));
	nw_gt_help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, nw_gt_help, _strnglength(nw_gt_help));
}
/**
 * ax_assist_cdir - Help information for the builtin alias.
 * Return: no return
 */
void aux_asst_cd(void)
{
	char *nw_gt_help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, nw_gt_help, _strnglength(nw_gt_help));
	nw_gt_help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, nw_gt_help, _strnglength(nw_gt_help));
}
