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

typedef struct tdt
{
    char **args;
    char *cmd;
    char **env;
}shdata;

void inputPrompt();

int handlestatus(char **);

char *_strcpy(char *dest, char *src);

int parseCommands(shdata *);

int handlePath(shdata *);

char* getcmd (char *buff);

int isBuiltin(char* command);

int isSysCall(shdata *);

void appendbinpath(char **command);

void printenv();

shdata* initdata (shdata *dtt);

void _freedata(shdata *data);

#endif
