#include "main.h"

/**
 * _getenv - gets environment varible thet matches input
 *
 * @input: input string
 * @env: local env variable
 * Return: string of env variable
 */

char *_getenv(char *input, char **env)
{
	register int i = 0;
	char *tok, *right;

	while (env[i])
	{
		tok = _strtok(env[i], "=");
		if (_strcmp(tok, input) == 0)
		{
			right = _strtok(NULL, "=");
			return (right);
		}
		i++;
	}
	return (NULL);
}
