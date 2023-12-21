#include "secondmain.h"

/**
 * _stringdup - A program that duplicates a str in the heap memory.
 * @str: Type char pointer str
 * Return: The duplicated string
 */

char *_strngdup(const char *str)
{
	char *nw_mem;
	size_t len;

	len = _strnglength(str);
	nw_mem = malloc(sizeof(char) * (len + 1));
	if (nw_mem == NULL)
	{
        return (NULL);
    }
	_memorycopy(nw_mem, str, len + 1);
	return (nw_mem);
}

/**
 * _strnglen - This program returns the lenght of a string.
 * @str: Type char pointer.
 * Return: Always 0.
 */
int _strnglen(const char *str)
{
	int len;

	for (len = 0; str[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * compare_chars - This program compares chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */

int cmpre_chars(char strng[], const char *delim)
{
	unsigned int a, b, c;

	for (a = 0, c = 0; strng[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (strng[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
	{
        return (1);
    }

	return (0);
}

/**
 * _stringtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */

char *_strngtok(char strng[], const char *delim)
{
	static char *divide, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (strng != NULL)
	{
		if (cmpre_chars(strng, delim))
		{
            return (NULL);
        }
		divide = strng; /*Stores the first address*/
		i = _strnglen(strng);
		str_end = &strng[i]; /*Stores the last address*/
	}
	str_start = divide;
	if (str_start == str_end) /*Reaching the particular end*/
		return (NULL);

	for (bool = 0; *divide; divide++)
	{
		/*Breaking loop with a view to finding the next token*/
		if (divide != str_start)
			if (divide && *(divide - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; delim[i]; i++)
		{
			if (*divide == delim[i])
			{
				*divide = '\0';
				if (divide == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *divide) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @strng: input string
 * Return: 1 if string is a number. 0 in other case.
 */

int _isdgt(const char *strng)
{
	unsigned int a;

	for (a = 0; strng[a]; a++)
	{
		if (strng[a] < 48 || strng[a] > 57)
		{
            return (0);
        }
	}
	return (1);
}
