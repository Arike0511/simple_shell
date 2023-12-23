#include "secondmain.h"

/**
 * _stringcat - This program concatenate two strings
 * @nw_src: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the new_src
 */

char *_strngcat(char *nw_src, const char *src)
{
	int c;
	int d;

	for (c = 0; nw_src[c] != '\0'; c++)
	;
	for (d = 0; src[d] != '\0'; d++)
	{
		nw_src[c] = src[d];
		c++;
	}

	nw_src[c] = '\0';
	return (nw_src);
}

/**
 * *_stringcpy - Copies the string pointed to by src to the new_str.
 * @nw_src: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the new_src.
 */

char *_strngcopy(char *nw_src, char *src)
{

	size_t d;

	for (d = 0; src[d] != '\0'; d++)
	{
		nw_src[d] = src[d];
	}
	nw_src[d] = '\0';

	return (nw_src);
}

/**
 * _stringcmp - A function / program that compares two strings.
 * @string1: type string 1 compared
 * @string2: type string 2 compared
 * Return: Always 0.
 */

int _strngcompare(char *string1, char *string2)
{
	int a;

	for (a = 0; string1[a] == string2[a] && string1[a]; a++)
	;
	if (string1[a] > string2[a])
	{
        return (1);
    }
	if (string1[a] < string2[a])
	{
        return (-1);
    }
	return (0);
}

/**
 * _stringchr - This locates a character in a string,
 * @str: string.
 * @cha: character.
 * Return: first occurence character c.
 */

char *_strngchr(char *str, char cha)
{
	unsigned int a = 0;

	for (; *(str + a) != '\0'; a++)
		if (*(str + a) == cha)
			return (str + a);
	if (*(str + a) == cha)
		return (str + a);
	return ('\0');
}

/**
 * _stringspn - This program gets the length of a prefix substring.
 * @str: initial segment.
 * @granted: accepted bytes.
 * Return: the number of accepted bytes.
 */

int _strngspn(char *str, char *granted)
{
	int c, d, bool;

	for (c = 0; *(str + c) != '\0'; c++)
	{
		bool = 1;
		for (d = 0; *(granted + d) != '\0'; d++)
		{
			if (*(str + c) == *(granted + d))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (c);
}
