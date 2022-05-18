#ifndef __MAIN_H__
#define __MAIN_H__

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

#ifndef _Bool
    #define _Bool bool
#endif

#define BUFSIZE 256
#define ENOSTRING 1106
#define EILLEGAL 227
#define EWSIZE 410
#define ENOBUILTIN 415
#define EBADCD 726

typedef unsigned int uint;
extern char **environ;

/**
 * struct linkedList - linked list
 *
 * @string: env variable path name
 * @next: pointer to the next node
 */

typedef struct linkedList
{
	char *string;
	struct linkedList *next;
} l_list;

/**
 * struct configurations - configuration of build settings
 *
 * @env: environment variables
 * @envList: array of env variables to put into execve
 * @args: array of arguments
 * @buffer: user input buffer
 * @path: array of $PATH locations
 * @fullPath: string of path with correct prepended $PATH
 * @shellName: name of the program
 * @lineCounter: counter of lines users have entered
 * @errorStatus: error status of last child process
 */

typedef struct configurations
{
	l_list *env;
	char **envList;
	char **args;
	char *buffer;
	char *path;
	char *fullPath;
	char *shellName;
	unsigned int lineCounter;
	int errorStatus;
} config;

/**
 * struct builtInCommands - commands associated with shell
 *
 * @cmd: input command
 * @func: commund function
 */

typedef struct builtInCommands
{
	char *cmd;
	int (*func)(config *build);
} type_b;

/* shell and system functions */
_Bool findBuiltIns(config *build);
config *configInt(config *build);
void shell(config *build);
void getInputAndPrompt(config *build);
void newLine(void);
void nullByte(char *str, unsigned int idx);
void prompt(void);
void signalHandler(int sigint);
int countArgs(char **args);

void forkAndExecute(config *build);
void getInputAndPrompt(config *build);
char *_getenv(char *input, char **environ);
_Bool checkPath(config *build);
_Bool checkEdgeCases(config *build);
int envFunc(config *build);
int setenvFunc(config *build);
int unsetenvFunc(config *build);

int cdFunc(config *build);
_Bool cdToHome(config *build);
_Bool cdToPrevious(config *build);
_Bool cdToCustom(config *build);
_Bool updateEnviron(config *build);
int updateOld(config *build);
_Bool updateCur(config *build, int index);

/* help shel functions */
int helpFunc(config *build);
int helpExit(config *build);
int helpEnv(config *build);
int helpHistory(config *build);
int displayHelpMenu(void);
int helpAlias(config *build);
int helpCd(config *build);
int helpSetenv(config *build);
int helpUnsetenv(config *build);
int helpHelp(config *build);

int historyFunc(config *build);
int aliasFunc(config *build);

int exitFunc(config *build);

void errorHandler(config *build);
char *getErrorMessage(void);
unsigned int countDigits(int num);

/* linked list functions */
l_list *addNode(l_list **head, char *str);
l_list *addNodeEnd(l_list **head, char *str);
size_t list_len(l_list *h);
size_t printList(const l_list *h);
int deleteNodeAtIndex(l_list **head, unsigned int index);
void convertLLtoArr(config *build);
l_list *generateList(char **arr);
int searchNode(l_list *head, char *str);
l_list *addNodeAtIndex(l_list **head, int index, char *str);
char *getNodeAtIndex(l_list *head, unsigned int index);

/* string functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _isalpha(int c);
char *_strtok(char *str, char *delim);
char *_strchr(char *s, char c);
int _strcspn(char *string, char *chars);
void stripComments(char *str);
int _atoi(char *s);
char *itoa(unsigned int num);
unsigned int countWords(char *str);
unsigned int countWords(char *s);
_Bool isSpace(char c);
_Bool splitString(config *build);

/* memory freeing functions */
void freeMembers(config *build);
void freeArgs(char **args);
void freeArgsAndBuffer(config *build);
void freeList(l_list *head);

#endif
