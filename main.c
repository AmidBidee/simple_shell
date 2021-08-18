#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - Entry point
 * Return: ...
 */


int main ()
{
    char argbuffer [1024]; /*this is to read the stdin and used to mark null points for *command*/
    char *command[64]; /*pointer to pointer of arguments, a 2dimensional array*/
    int statusCode = 0;
    __pid_t mypid;
    int inputstream;

    while (1)
    {
        printPrompt();
        statusCode = parseCommands(argbuffer, command); /*here we read inpuit and fill them in the command pointer*/
        if (statusCode != -1)
        {
            mypid = fork();

            if(mypid == 0)
            {
                execvp(*command, command);
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
    }
    
}