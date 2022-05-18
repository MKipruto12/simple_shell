#include "main.h"

/**
 * newLine - inserts a new line
 */

void newLine(void)
{
	write(STDERR_FILENO, "\n", 1);
}

/**
 * nullByte - inserts a null byte
 *
 * @str: input string
 * @idx: index of null byte
 */

void nullByte(char *str, unsigned int idx)
{
	str[idx] = '\0';
}

/**
 * prompt - the shell prompt
 */

void prompt(void)
{
	write(STDERR_FILENO, "#cisfun$ ", 9);
}

/**
 * signalHandler - handles signal and reset
 *
 * @sigint: signal from stdint
 */

void signalHandler(int sigint)
{
	(void)sigint;
	signal(SIGINT, signalHandler);
	newLine();
	prompt();
	fflush(stdout);
}
