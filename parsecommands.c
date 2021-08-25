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


int parseCommands(shdata *data)
{
    char *line = NULL, *str, *buff = NULL, *d[2] = {"\n", " "};  /* a lineptr, string ptr, array delimeter, array length */
    size_t len = 0; /* var for length of each strings */
    ssize_t nr; /* var for number of line to be read */
    int i, l_len = 0, checkBin = 0; /* var for indexes */
    char **cmd;
    /*memset(args, 0, sizeof(args)); /* clear the array before proceeding if its not empty */


    nr = getline(&buff, &len, stdin);  /* get the commands from standard input */
    if (nr == -1)   /* if it fails to read the lines, exit */
        exit(EXIT_FAILURE);

    data->cmd = strcpy(data->cmd, getcmd(buff));
    if (nr)
    {
        for (i = 0; i < 2; i++)
        {
            str = strtok(buff, d[i]);
            while (str != NULL)  /* create and extract each token to str */
            {
                data->args[l_len] = str;   /* fill the args array with the tokens */
                str = strtok(NULL, d[i]);
                l_len++;  /* Not to sure but i think this separates each token in array */
                /* increase this so we can use as length */
            }
            l_len = 0;
        }
    }
    if (data->args == NULL)  /* if the args wasn't filled exit */
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


int handlePath(shdata *data){
    char path[] = "/bin/";
    char *tokentmp;
    char *tmp = malloc(sizeof(char) * MAX_BUFF);
    strcat(tmp, path);
    if(strstr(data->cmd, path) == NULL)
    {
        data->cmd = strcat(tmp, data->cmd);
    }
    struct stat st;
    return stat(data->cmd, &st);
}



int isBuiltin(char* command)
{
    int iterator = 0;
    command = strtok(command, "\n");
    if(command == NULL)
    {
        return 0;
    }
    char ch_arr[4][10] = {
                         "clear",
                         "exit",
                         "cd",
                         "env"
                     };
    while (ch_arr[iterator] && iterator < 4)
    {
        if (strcmp(ch_arr[iterator], command) == 0)
        {
            return iterator;
        }
        iterator ++;
    }

    /*also need to be sure that the command does not exist in the '/bin/ folder*/

    return -1;
}


int isSysCall(shdata *data)
{
    /*if built in exist return one or if it does not return 0*/
    /*handle path here*/
    /* loads up bin dir and make comparison against its files */
    DIR *d; /* directory pointer */
    struct dirent *dir;
    d = opendir("/bin/");
    if (d)
    {
        while ((dir = readdir(d)) != NULL) /* traverse to the end of the folder */
        {
            if ((strcmp(data->cmd, dir->d_name)) == 0) /* compare each file with the command */
            {
                handlePath(data);
                return (1); /* if there's a match return 1 */
            }
        }
        closedir(d); /* close the dir */
    }
    return (0);
    return 1;
}