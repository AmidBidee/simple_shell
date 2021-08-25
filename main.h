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

void inputPrompt();

int handlestatus(char **);

char *_strcpy(char *dest, char *src);

int parseCommands(char **args);

char* handlePath(char *tmp);

int checkifBuiltIn(char* command);

int checkBinDir(char *cmd);

void appendbinpath(char **command);


#endif