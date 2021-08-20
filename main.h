#ifndef HOLBERTON_H
#define HOLBERTON_H

#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputPrompt(char **args);

char *_strcpy(char *dest, char *src);

int parseCommands(char *bufferarg, char **command);


#endif