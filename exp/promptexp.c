#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputprompt(char **args)
{
    char *line = NULL, *str, d[] = " ";;
    size_t len = 0;
    ssize_t nr;
    int i = 0, j;

    printf("$ ");
    nr = getline(&line, &len, stdin);

    if (nr == -1)
        exit(EXIT_FAILURE);

    if (nr)
    {
        str = strtok(line, d);
        while (str != NULL)
        {
            args[i] = str;   
            str = strtok(NULL, d);
            i++;
        }
    }

    if (args == NULL)
        exit (EXIT_FAILURE);

    return (nr);
}

int main()
{
    int i = 0;
    char *command[1024];

    while (1)
    {
        inputprompt(command);
        while (command[i] != NULL)
        {
            printf("%s ", command[i]);
            i++;
        }
        i = 0;
    }
}
