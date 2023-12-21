#include "secondmain.h"

/**
 * reverse_string - reverses a string.
 * @str: input string.
 * Return: no return.
 */

void rever_strng(char *strng)
{
	int counter = 0, i, j;
	char *str, temp;

	while (counter >= 0)
	{
		if (strng[counter] == '\0')
			break;
		counter++;
	}
	str = strng;

	for (i = 0; i < (counter - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
