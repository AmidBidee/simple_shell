#include "main.h"
/**
 * inputPrompt - prints a prompt and fills a argument array
 * @args: pointer to args pointer
 * Return: array length
 */

int inputPrompt(char **args)
{
    char *line = NULL, *str, *d[2] = {"\n", " "}, cwd[1024]; /* a lineptr, string ptr, array delimeter, array length */
    size_t len = 0; /* var for length of each strings */
    ssize_t nr; /* var for number of line to be read */
    int i, l_len = 0; /* var for indexes */

    /*memset(args, 0, sizeof(args)); /* clear the array before proceeding if its not empty */

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s$ ", cwd); /* prints a dollar sign before commands everytime it's called */

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


/**
 * _strchr - locates a character in a string
 * @s: pointer string
 * @c: character to find
 *
 * Return: pointer to of c
 *
char *_strchr(char *s, char c)
{
	while (*s++)
	{
		if (*s == c)
			*s = NULL;
	}
	return (0);
}*/