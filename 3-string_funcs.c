#include "main.h"

/**
 * splitString - splits string into an array of strings
 * separated by spaces
 *
 * @build: input build
 * Return: true if able to split, false if not
 */

_Bool splitString(config *build)
{
	register unsigned int i = 0;
	char *tok, *cpy;

	if (countWords(build->buffer) == 0)
	{
		build->args = NULL;
		free(build->buffer);
		return (false);
	}
	build->args = malloc((countWords(build->buffer) + 1) * sizeof(char *));
	cpy = _strdup(build->buffer);
	tok = _strtok(cpy, " ");
	while (tok)
	{
		build->args[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}
	build->args[i] = NULL;
	free(cpy);
	return (true);
}

/**
 * countWords - count number of words in a string
 *
 * @str: input string
 * Return: number of words
 */

unsigned int countWords(char *str)
{
	register int words = 0;
	_Bool wordOn = false;

	while (*str)
	{
		if (isSpace(*str) && wordOn)
			wordOn = false;
		else if (!isSpace(*str) && !wordOn)
		{
			wordOn = true;
			words++;
		}
		str++;
	}
	return (words);
}

/**
* _atoi - change string to an integer

* @s: input string
* Return: -1 if it's not a valid number, else the converted number
*/

int _atoi(char *s)
{
	register int i = 0;
	unsigned long num = 0;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + s[i] - '0';
		else
			return (-1);
		i++;
	}
	if (num > INT_MAX)
	{
		return (-1);
	}
	return (num);
}
