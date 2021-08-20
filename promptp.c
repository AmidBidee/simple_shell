#include "main.h"
/**
 * inputPrompt - prints a prompt and fills a argument array
 * @args: pointer to args pointer
 * Return: array length
 */

int inputPrompt(char **args)
{
    char *line = NULL, *str, d[] = " "; /* a lineptr, string ptr, array delimeter, array length */
    size_t len = 0; /* var for length of each strings */
    ssize_t nr; /* var for number of line to be read */
    int i = 0, l_len = 0; /* var for indexes */

    /*memset(args, 0, sizeof(args)); /* clear the array before proceeding if its not empty */

    printf("$");  /* prints a dollar sign before commands everytime it's called */
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