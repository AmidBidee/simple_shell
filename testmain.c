#include "main.h"
#include <stdio.h>



int main(void)
{
    char input[] = {'\n'};
    char *tmp;
    tmp = handlePath(input);
    printf("%s", tmp);
}