#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputprompt(char **args)
{
    char *line = NULL, *str, d[] = " ", l_len;
    size_t len = 0;
    ssize_t nr;
    int i = 0, j;

    printf("$");
    nr = getline(&line, &len, stdin);

    if (nr == -1)
        exit(EXIT_FAILURE);

    if (nr)
    {
        str = strtok(line, d);
        while (str != NULL)
        {
            args[l_len] = str;   
            str = strtok(NULL, d);
            l_len++;
        }
    }

    if (args == NULL)
        exit (EXIT_FAILURE);

    return (l_len);
}

int main()
{
    int i = 0, line_len;
    char *command[1024];

    while (1)
    {
        memset(command, 0, 1024);
        line_len = inputprompt(command);
        while (i < line_len)
        {
            if (command[i] != NULL)
                printf(" %s", command[i]);
            i++;
        }
        i = 0;
    }
}
