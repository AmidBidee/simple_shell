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
{ /*this is to read the stdin and used to mark null points for *command*/
    char **command; /*pointer to pointer of arguments, a 2dimensional array*/
    int statusCode = 0, arg_len;
    __pid_t mypid;
    char *env_args[] = {NULL};
    /*char *c[] = {"/bin/ls", "-l\n", NULL};*/
    /*char *c = malloc(sizeof(char *));*/

    while (1)
    {
        command = malloc(sizeof(char *));
        inputPrompt();
        arg_len = parseCommands(command);
        statusCode = handlestatus(command);
        if (statusCode == 1)
        {
            exit(getpid());
        }
        /* statusCode = parseCommands(argbuffer, command); /*here we read input and fill them in the command pointer*/
        if (statusCode != -1)
        {
            mypid = fork();

            if(mypid == 0)
            {
                /*printf("%s %s", command[0], command[arg_len]);*/
                /*command[arg_len] = NULL;*/
                execve(command[0], command, env_args);
                /*child process to run the command*/
            }
            else
            {
                /*this is the parent process, we simply wait*/
                wait(NULL);
            }
        }
        else
        {
            printf("Error");
        }
        free(command);
    }
}
