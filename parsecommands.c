#include "main.h"
#include <stdio.h>
#define MAX_BUFF 1024

/**
 * parseCommands - this reads info from the stdin and breaks them
 *                  into null terminated entries for *command
 * @bufferarg: this is used to temproarily store stdin for iteration
 * @command: this points to arrays of null terminated arguments
 * Return : returns -1 if there is an error or 1 if its through
 */


int parseCommands(char **args)
{
    char *line = NULL, *str, *buff = NULL, *d[2] = {"\n", " "};  /* a lineptr, string ptr, array delimeter, array length */
    size_t len = 0; /* var for length of each strings */
    ssize_t nr; /* var for number of line to be read */
    int i, l_len = 0; /* var for indexes */

    /*memset(args, 0, sizeof(args)); /* clear the array before proceeding if its not empty */


    nr = getline(&buff, &len, stdin);  /* get the commands from standard input */
    if (nr == -1)   /* if it fails to read the lines, exit */
        exit(EXIT_FAILURE);
    line = handlePath(buff); /*this checks if there is a '/bin/' appended, if none, it appends*/

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

char* getcmd (char *buff){
    char *tmp;
    tmp = malloc(sizeof(buff));
    strcpy(tmp, buff);
    return (strtok(tmp, " "));
}


char* handlePath(char *buff){
        int checkbuff = 0;
    /*check if path is not yet appended*/
    char *token = getcmd(buff);
    checkbuff = checkifBuiltIn(token); /*make sure token is not a built in command*/
    if (checkbuff == 1) 
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



int checkifBuiltIn(char* command)
{
    int iterator = 0;
    command = strtok(command, "\n");
    if(command == NULL)
    {
        return 0;
    }
    char ch_arr[3][10] = {
                         "clear",
                         "exit",
                         "cd"
                     };
    if(handleBinDir(command) == 1)
    {
        /*if the command is not in the bin folder, means it does not exist andn
        its not a built in command*/
        return 1;
    }
    while (ch_arr[iterator] && iterator < 3)
    {
        if (strcmp(ch_arr[iterator], command) == 0)
        {
            return 1;
        }
        iterator ++;
    }

    /*also need to be sure that the command does not exist in the '/bin/ folder*/

    return 0;
}


int handleBinDir(char *cmd)
{
    /*load all files in bin and make comparison against them*/

}