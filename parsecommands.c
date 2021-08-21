#include "main.h"

/**
 * parseCommands - this reads info from the stdin and breaks them
 *                  into null terminated entries for *command
 * @bufferarg: this is used to temproarily store stdin for iteration
 * @command: this points to arrays of null terminated arguments
 * Return : returns -1 if there is an error or 1 if its through
 */



int parseCommands(char **args)
{
    char *line = NULL, *str, *d[2] = {"\n", " "};  /* a lineptr, string ptr, array delimeter, array length */
    size_t len = 0; /* var for length of each strings */
    ssize_t nr; /* var for number of line to be read */
    int i, l_len = 0; /* var for indexes */

    /*memset(args, 0, sizeof(args)); /* clear the array before proceeding if its not empty */


    nr = getline(&line, &len, stdin);  /* get the commands from standard input */

    if (nr == -1)   /* if it fails to read the lines, exit */
        exit(EXIT_FAILURE);

    if (nr)
    {
        for (i = 0; i < 2; i++)
        {
            str = strtok(line, d[i]);
            while (str != NULL)  /* create and extract each token to str */
            {
                args[l_len] = str;   /* fill the args array with the tokens */
                str = strtok(NULL, d[i]);
                l_len++;  /* Not to sure but i think this separates each token in array */
                /* increase this so we can use as length */
            }
            l_len = 0;
        }
    }

    if (args == NULL)  /* if the args wasn't filled exit */
        exit (EXIT_FAILURE);

    

    return (l_len); 
}