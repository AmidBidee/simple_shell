#include "main.h"

/**
 * inputPrompt - prints a prompt on terminal
 * Return: ....
 */
void inputPrompt(void)
{
char cwd[1024];
if (getcwd(cwd, sizeof(cwd)) != NULL)
printf("%s$ ", cwd);
}
