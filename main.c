#include "main.h"

/**
 * main - program entry point
 *
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0 or -1
 */

int main(int argc, char **argv)
{
	config build;

	(void)argc;
	signal(SIGINT, signalHandler);
	configInt(&build);
	build.shellName = argv[0];
	shell(&build);
	return (0);
}

/**
 * configInt - initialize member values for config struct
 *
 * @build: input build
 * Return: build with initialized members
 */

config *configInt(config *build)
{
	build->env = generateList(environ);
	build->envList = NULL;
	build->args = NULL;
	build->buffer = NULL;
	build->path = _getenv("PATH", environ);
	build->fullPath = NULL;
	build->lineCounter = 0;
	build->shellName = NULL;
	build->errorStatus = 0;
	return (build);
}
