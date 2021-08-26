#include "main.h"

/**
 * main - Entry point
 * Return: ...
 */
int main(void)
{
	int builtin = 0, status;
	__pid_t mypid;
	shdata *data;

	while (1)
	{
		if (isatty(0))
		{
			inputPrompt();
		}
		data = initdata(data);
		parseCommands(data);
		if (data->cmd != NULL && *data->cmd != '\n')
		{
			builtin = isBuiltin(data->cmd);
			if (builtin != -1)
			{
				handleBuitin(builtin);
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
					waitpid(mypid, &status, WUNTRACED);
				}
			}
			else
			{
				printf("./hsh: 1: %s: not found\n", data->cmd);
			}
		}
		_freedata(data);
	}
}

/**
 * handleBuitin - Entry point
 *@builtin:...
 * Return: ...
 */
void handleBuitin(int builtin)
{
	if (builtin == 1)
	{
		exit(getpid());
	}
	if (builtin == 3)
	{
		_printenv();
	}
	if (builtin == 0)
	{
		system("clear");
	}
}

/**
 * _freedata - frees the data
 *@data:....
 * Return: ...
 */
void _freedata(shdata *data)
{
	if (data == NULL)
		return;
	free(data->cmd);
	data->cmd = NULL;
	free(data->args);
	data->args = NULL;
	free(data->env);
	data->env = NULL;
}

/**
 * initdata - this is initializes the struct shdata
 * @dtt: this is the data
 * Return: returns the data
 */
shdata *initdata(shdata *dtt)
{
	dtt = malloc(sizeof(shdata));
	dtt->cmd = malloc(sizeof(char) * 1024);
	dtt->args = malloc(sizeof(char *) * 10);
	dtt->env = malloc(sizeof(char *));
	return (dtt);
}
