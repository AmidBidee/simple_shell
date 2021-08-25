#include "main.h"
#include <stdio.h>
#define MAX_BUFF 1024

/**
 * parseCommands - this reads info from the stdin and breaks them
 * @data: ....
 * Return: returns number of characters
 */
int parseCommands(shdata *data)
{
	char *str, *buff = NULL, *d[2] = {"\n", " "};
	size_t len = 0;
	ssize_t nr;
	int i, l_len = 0;

	nr = getline(&buff, &len, stdin);
	if (nr == -1)
		exit(EXIT_FAILURE);

	data->cmd = strcpy(data->cmd, getcmd(buff));
	if (nr)
	{
		for (i = 0; i < 2; i++)
		{
			str = strtok(buff, d[i]);
			while (str != NULL)
			{
				data->args[l_len] = str;
				str = strtok(NULL, d[i]);
				l_len++;
			}
			l_len = 0;
		}
	}
	if (data->args == NULL)
		exit(EXIT_FAILURE);
	return (l_len);
}

/**
 * getcmd - This gets the command from the buffer
 * @buff: this is the buff
 * Return: returns the token
 */
char *getcmd(char *buff)
{
	char *tmp;

	tmp = malloc(sizeof(buff));
	_strcpy(tmp, buff);
	return (strtok(tmp, " "));
}

/**
 * handlePath - This appends the bin oath to the command
 *              if it does not exist already
 * @data: this is the 2d array
 * Return: returns 0 on success
 */
int handlePath(shdata *data)
{
	char path[] = "/bin/";
	char *tmp = malloc(sizeof(char) * MAX_BUFF);
	struct stat st;

	_strcat(tmp, path);
	if (_strstr(data->cmd, path) == NULL)
	{
		data->cmd = _strcat(tmp, data->cmd);
	}

	return (stat(data->cmd, &st));
}

/**
 * isBuiltin - checks if its builtin
 * @command: The command to check
 * Return: returns codes for implementation
 */
int isBuiltin(char *command)
{
	int iterator = 0;
	char ch_arr[4][10] = {"clear", "exit", "cd", "env"};

	command = strtok(command, "\n");
	if (command == NULL)
	{
		return (0);
	}
	while (ch_arr[iterator] && iterator < 4)
	{
		if (_strcmp(ch_arr[iterator], command) == 0)
		{
			return (iterator);
		}
		iterator++;
	}
	return (-1);
}
