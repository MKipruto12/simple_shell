#include "main.h"

/**
 * main -  prints "$ " and waits for the user to enter a command
 *
 * Return : 0 if successful
 */

int main()
{
	char cmd[20];

	printf("$ ");
	while (scanf("%s", cmd))
	{
		printf("%s\n", cmd);
		system(cmd);
		print("$ ");
	}

	return (0);
}
