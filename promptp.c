#include "main.h"
/**
 * inputPrompt - prints a prompt and fills a argument array
 * @args: pointer to args pointer
 * Return: array length
 */

void inputPrompt()
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s$ ", cwd); /* prints a dollar sign before commands everytime it's called */
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