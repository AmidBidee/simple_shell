#ifndef HOLBERTON_H
#define HOLBERTON_H

#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputPrompt();

int handlestatus(char **);

char *_strcpy(char *dest, char *src);

int parseCommands(char **args);

void appendbinpath(char **command);


#endif