#include "secondmain.h"

/**
 * cd_shell - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *str_dir;
	int ishome_str, ishome2_ptr, is_dash;

	str_dir = datash->arguments[1];

	if (str_dir != NULL)
	{
		ishome_str = _strngcompare("$HOME", str_dir);
		ishome2_ptr = _strngcompare("~", str_dir);
		is_dash = _strngcompare("--", str_dir);
	}

	if (str_dir == NULL || !ishome_str || !ishome2_ptr || !is_dash)
	{
		cd_to_org(datash);
		return (1);
	}

	if (_strngcompare("-", str_dir) == 0)
	{
		cd_fro(datash);
		return (1);
	}

	if (_strngcompare(".", str_dir) == 0 || _strngcompare("..", str_dir) == 0)
	{
		cd_dt(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
