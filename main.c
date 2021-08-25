#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - Entry point
 * Return: ...
 */


int main (void)
{
	int statusCode = 0, syscall, arg_len, builtin = 0;
	__pid_t mypid;
	shdata *data;

	while (1)
	{
		inputPrompt();
		data = initdata(data);
		arg_len = parseCommands(data);
		if ((builtin = isBuiltin(data->cmd)) != -1)
		{
			if (builtin == 1)
			{
				exit(getpid());
			}
			if(builtin == 3)
			{
				printenv();
				continue;
			}
			if (builtin == 0)
			{
				system("clear");
			}
		}
		else if (handlePath(data) == 0)
		{
			mypid = fork();
			if (mypid == 0)
			{
				execve(data->cmd, data->args, data->env);
			}
			else
			{
				wait(NULL);
			}
		}
		free(data);
	}
}


void _freedata(shdata *data){
	int iterator = 0;
	free(data->cmd);
	while (data->args[iterator])
	{
		free(data->args[iterator]);
		iterator++;
	}
	free(data->args);
	free(data->env);
}

/**
 * initdata - this is initializes the struct shdata
 * @dtt: this is the data
 * Return: returns the data
 */
shdata* initdata (shdata *dtt)
{
	dtt = malloc(sizeof(shdata));
	dtt->cmd = malloc(sizeof(char) * 1024);
	dtt->args = malloc(sizeof(char *) * 10);
	dtt->env = malloc(sizeof(char*));return dtt;
}

