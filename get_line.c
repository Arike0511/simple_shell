#include "secondmain.h"

/**
 * get_ln - A program that assigns the line var
 * @lnptr: Buffer that store the input str
 * @buffer: str that is been called to line
 * @n: size of line
 * @a: size of buffer
 */

void get_ln(char **lnptr, size_t *n, char *buffer, size_t a)
{

	if (*lnptr == NULL)
	{
		if  (a > SIZE_IN_TOTAL)
		{
			*n = a;
		}

		else
		{
			*n = SIZE_IN_TOTAL;
		}

		*lnptr = buffer;
	}

	else if (*n < a)
	{
		if (a > SIZE_IN_TOTAL)
		{
			*n = a;
		}

		else
		{
			*n = SIZE_IN_TOTAL;
		}
		*lnptr = buffer;
	}

	else
	{
		_strngcopy(*lnptr, buffer);
		free(buffer);
	}
}

/**
 * get_liner - The program that Read inpt from stream
 * @lnptr: buffer that stores the input
 * @n: size of lineptr
 * @streaming: stream to read from
 * Return: The number of bytes
 */

ssize_t get_liner(char **lnptr, size_t *n, FILE *streaming)
{
	int a;
	static ssize_t take_in;
	ssize_t retrie;
	char *bufferi;
	char letter = 'z';

	if (take_in == 0)
		fflush(streaming);
	else
		return (-1);
	take_in = 0;

	bufferi = malloc(sizeof(char) * SIZE_IN_TOTAL);
	if (bufferi == 0)
		return (-1);
	while (letter != '\n')
	{
		a = read(STDIN_FILENO, &letter, 1);
		if (a == -1 || (a == 0 && take_in == 0))
		{
			free(bufferi);
			return (-1);
		}
		if (a == 0 && take_in != 0)
		{
			take_in++;
			break;
		}
		if (take_in >= SIZE_IN_TOTAL)
			bufferi = _reallocated(bufferi, take_in, take_in + 1);
		bufferi[take_in] = letter;
		take_in++;
	}

	bufferi[take_in] = '\0';
	get_ln(lnptr, n, bufferi, take_in);
	retrie = take_in;
	if (a != 0)
		take_in = 0;
	return (retrie);
}
