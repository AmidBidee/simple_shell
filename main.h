#ifndef HOLBERTON_H
#define HOLBERTON_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputPrompt(char **args);

int parseCommands(char *bufferarg, char **command);


#endif