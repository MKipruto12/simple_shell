#include "main.h"

/**
 * shell - UNIX shell
 *
 * @build: input build
 */

void shell(config *build)
{
	while (true)
	{
		getInputAndPrompt(build);
		if (splitString(build) == false)
			continue;
		if (findBuiltIns(build) == true)
			continue;
		checkPath(build);
		forkAndExecute(build);
	}
}

/**
 * getInputAndPrompt - check stdin and retrieves next line; handles
 * prompt display
 * @build: input build
 */
void getInputAndPrompt(config *build)
{
	register int len;
	size_t bufferSize = 0;
	char *ptr, *ptr2;

	build->args = NULL;
	build->envList = NULL;
	build->lineCounter++;
	if (isatty(STDIN_FILENO))
		prompt();
	len = getline(&build->buffer, &bufferSize, stdin);
	if (len == EOF)
	{
		freeMembers(build);
		if (isatty(STDIN_FILENO))
			newLine();
		if (build->errorStatus)
			exit(build->errorStatus);
		exit(EXIT_SUCCESS);

	}
	ptr = _strchr(build->buffer, '\n');
	ptr2 = _strchr(build->buffer, '\t');
	if (ptr || ptr2)
		nullByte(build->buffer, len - 1);
	stripComments(build->buffer);
}

/**
 * stripComments - remove comments from input string
 *
 * @str: input string
 * Return: length of remaining string
 */
void stripComments(char *str)
{
	register int i = 0;
	_Bool notFirst = false;

	while (str[i])
	{
		if (i == 0 && str[i] == '#')
		{
			nullByte(str, i);
			return;
		}
		if (notFirst)
		{
			if (str[i] == '#' && str[i - 1] == ' ')
			{
				nullByte(str, i);
				return;
			}
		}
		i++;
		notFirst = true;
	}
}

/**
 * forkAndExecute - fork current build and execute processes
 *
 * @build: input build
 */

void forkAndExecute(config *build)
{
	int status;
	pid_t f1 = fork();

	convertLLtoArr(build);
	if (f1 == -1)
	{
		perror("error\n");
		freeMembers(build);
		freeArgs(build->envList);
		exit(1);
	}
	if (f1 == 0)
	{
		if (execve(build->fullPath, build->args, build->envList) == -1)
		{
			errorHandler(build);
			freeMembers(build);
			freeArgs(build->envList);
			if (errno == ENOENT)
				exit(127);
			if (errno == EACCES)
				exit(126);
		}
	} else
	{
		wait(&status);
		if (WIFEXITED(status))
			build->errorStatus = WEXITSTATUS(status);
		freeArgsAndBuffer(build);
		freeArgs(build->envList);
	}
}

/**
 * convertLLtoArr - convert linked list to array
 * @build: input build
 */
void convertLLtoArr(config *build)
{
	register int i = 0;
	size_t count = 0;
	char **envList = NULL;
	l_list *tmp = build->env;

	count = list_len(build->env);
	envList = malloc(sizeof(char *) * (count + 1));
	if (!envList)
	{
		perror("Malloc failed\n");
		exit(1);
	}
	while (tmp)
	{
		envList[i] = _strdup(tmp->string);
		tmp = tmp->next;
		i++;
	}
	envList[i] = NULL;
	build->envList = envList;
}
