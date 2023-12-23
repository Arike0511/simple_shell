#include "secondmain.h"

/**
 * rd_ln - This program reads the input string.
 * @i_eof: return value of getline function
 * Return: input string
 */

char *rd_line(int *i_eof)
{
	char *get_in = NULL;
	size_t buff_size = 0;

	*i_eof = get_liner(&get_in, &buff_size, stdin);

	return (get_in);
}
