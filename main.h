#ifndef HOLBERTON_H
#define HOLBERTON_H

#define _GNU_SOURCE
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * struct tdt - simple shell data structure
 * @args: for a 2d array of strings
 * @cmd: for stdin array string
 * @env: for environmental variable usually {NULL}
 */

typedef struct tdt
{
	char **args;
	char *cmd;
	char **env;
} shdata;

void inputPrompt(void);

char *_strcpy(char *dest, char *src);

int parseCommands(shdata *);

int handlePath(shdata *);

char *getcmd(char *buff);

int isBuiltin(char *command);

int isSysCall(shdata *);

void appendbinpath(char **command);

void _printenv(void);

shdata *initdata(shdata *dtt);

void _freedata(shdata *data);

char *_strcat(char *dest, char *src);

char *_strstr(char *haystack, char *needle);

char *_strcpy(char *dest, char *src);

int _strcmp(char *s1, char *s2);

void handleBuitin(int builtin);

int check_file(char *dirname, char *file);

int _strlen(char *s);

char *_strdup(char *str);

char *_strtok(char *base, char *delims);
#endif
