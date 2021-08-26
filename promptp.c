#include "main.h"

/**
 * inputPrompt - prints a prompt on terminal
 * Return: ....
 */
void inputPrompt()
{
char *c;
c = "$ ";
write(STDOUT_FILENO, c, _strlen(c));
}
