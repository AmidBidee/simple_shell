#include "main.h"
#define MAX_BUFF 1024

/**
 * parseCommands - this reads info from the stdin and breaks them
 *                  into null terminated entries for *command
 * @bufferarg: this is used to temproarily store stdin for iteration
 * @command: this points to arrays of null terminated arguments
 * Return : returns -1 if there is an error or 1 if its through
 */

char* handlePath(char *tmp);

int parseCommands(char **args)
{
    char *line = NULL, *str, *buff, *d[2] = {"\n", " "};  /* a lineptr, string ptr, array delimeter, array length */
    size_t len = 0; /* var for length of each strings */
    ssize_t nr; /* var for number of line to be read */
    int i, l_len = 0; /* var for indexes */

    /*memset(args, 0, sizeof(args)); /* clear the array before proceeding if its not empty */


    nr = getline(&buff, &len, stdin);  /* get the commands from standard input */

    if (nr == -1)   /* if it fails to read the lines, exit */
        exit(EXIT_FAILURE);
    line = handlePath(buff);
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

/**
 * handlePath - This appends the bin oath to the command
 *              if it does not exist already
 * @command: this is the 2d array
 * Return : returns the 2d array
 */

char* handlePath(char *buff){
    /*check if path is not yet appended*/
    char token = strtok(buff, ' ');

    if(checkBuiltin(token) == -1) /*make sure token is not a built in command*/
    {
        return buff;
    }

    char path[] = "/bin/";
    char *tmp = malloc(sizeof(char) * MAX_BUFF);
    strcat(tmp, path);
    if(strstr(buff, path) == NULL)
    {
        strcat(tmp, buff);
    }
    else
    {
        return buff;
    }
    return tmp;
}


int checkBuiltin(char* command){

}
