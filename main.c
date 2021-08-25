#include "main.h"
/**
 * main - Entry point
 * Return: ...
 */

int main (void)
{
    char **command ={NULL}, *env_args[] = {NULL}; /*pointer to pointer of arguments, a 2dimensional array*/ 
    int statusCode = 0, arg_len;
    __pid_t mypid;

    while (1)
    {
        command = malloc(40);
        if (command == NULL)
            exit(EXIT_FAILURE);
        
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
                /*free(command);*/
            }
            else
            {
                wait(NULL); /*this is the parent process, we simply wait*/
            }
        }
        else
        {
            perror("Error");
        }
        arg_len = 0;
        free(command);
    }
}
