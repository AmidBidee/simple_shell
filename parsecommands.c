#include "main.h"
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
	if (nr)
	{
		for (i = 0; i < 2; i++)
		{
			str = _strtok(buff, d[i]);
			while (str != NULL)
			{
				data->args[l_len] = str;
				str = _strtok(NULL, d[i]);
				l_len++;
			}
			l_len = 0;
		}
	}
	if (data->args == NULL)
		exit(EXIT_FAILURE);
	data->cmd = _strcpy(data->cmd, data->args[0]);
	return (l_len);
}

/**
 * handlePath - checks if command exists
 * @data: this is the 2d array
 * Return: returns 0 on success
 */
int handlePath(shdata *data)
{
	char *path = NULL, *token = NULL, *fpath = "/bin/";
	char *tmp;
	struct stat st;

	path = getenv("PATH");
	tmp = _strdup(path);

	if (_strstr(data->cmd, fpath) != NULL)
		return (stat(data->cmd, &st));
	if (tmp == NULL)
	{
		printf("error: PATH could not be read");
		exit(EXIT_FAILURE);
	}
	token = _strtok(tmp, ":");
	while (token)
	{
		if (check_file(token, data->cmd) == 1)
		{
			_strcat(token, "/");
			_strcpy(data->cmd, _strcat(token, data->cmd));
			return (0);
		}
		token = _strtok(NULL, ":");
	}
	free(tmp);
	return (-1);
}

/**
 * check_file - check if a file exist in a directory
 * @dirname: directory name
 * @file: name of the file to check
 * Return: 1 if success, 0 if failure
 */
int check_file(char *dirname, char *file)
{
	DIR *d;
	struct dirent *dir;

	d = opendir(dirname);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (_strcmp(dir->d_name, file) == 0)
				return (1);
		}
		closedir(d);
	}
	return (0);
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

	command = _strtok(command, "\n");
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
