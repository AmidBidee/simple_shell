#include "main.h"
/**
 * main - Entry point
 * Return: ...
 */

int main (void)
{
    char **command = NULL, *env_args[] = {NULL}; /*pointer to pointer of arguments, a 2dimensional array*/
    int statusCode = 0, arg_len;
    __pid_t mypid;

    command = malloc(sizeof(char *));
    while (1)
    {
        inputPrompt();
        arg_len = parseCommands(command);
        statusCode = handlestatus(command);
        if (statusCode == 1)
        {
            exit(getpid());
        }
        if (statusCode != -1)
        {
            mypid = fork();
            if(mypid == 0)
            {
                execve(command[0], command, env_args);/*child process to run the command*/
            }
            else
            {
                wait(NULL); /*this is the parent process, we simply wait*/
            }
        }
        else
        {
            printf("Error");
        }
    }
    free(command);
}
