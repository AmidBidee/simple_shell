#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int inputPrompt(char **args)
{
    char *line = NULL, *str, d[] = " ", cwd[1024]; /* a lineptr, string ptr, array delimeter, array length */
    size_t len = 0; /* var for length of each strings */
    ssize_t nr; /* var for number of line to be read */
    int i = 0, l_len = 0; /* var for indexes */

    if (args != NULL)
        memset(args, 0, sizeof(args)); /* clear the array before proceeding if its not empty */
    
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s$ ", cwd); /* prints a dollar sign before commands everytime it's called */

    nr = getline(&line, &len, stdin);  /* get the commands from standard input */

    if (nr == -1)   /* if it fails to read the lines, exit */
        exit(EXIT_FAILURE);

    if (nr)
    {
        str = strtok(line, d);  /* create and extract each token to str */
        while (str != NULL)
        {
            args[l_len] = str;   /* fill the args array with the tokens */
            str = strtok(NULL, d);
            l_len++;  /* Not to sure but i think this separates each token in array */
            /* increase this so we can use as length */
        }
    }

    if (args == NULL)  /* if the args wasn't filled exit */
        exit (EXIT_FAILURE);

    return (l_len); 
}

int main()
{
    int i = 0, line_len=0, o_l;
    char *command[1024];

    while (1)
    {
        memset(command, 0, 1024); /* the array keeps allocating, so this clears it */
        line_len = inputPrompt(command); /* the prompt returns the length of array after this*/

        /* THIS PART WAS FOR THE SAKE OF TESTING */
        printf("array length-> %d", line_len); /**
                                                but it adds the length of current array to
                                                previous length, please fix if you can
                                                */
        while (i < line_len)
        {
            if (command[i] != NULL)
                printf(" %s", command[i]);
            i++;
        }
        i = 0;
    }
}
