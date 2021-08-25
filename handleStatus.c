#include "main.h"
#include "string.h"

/**
 * handlestatus - This searches for special characters
 */

int handlestatus(char **command)
{
    /*check for exit*/
    /*1 is for exit,  2 is for clear*/

    if(strcmp(&(*command[0]), "exit") == 0)
    {
        return 1;
    }
    
    if (strcmp(&(*command[0]), "clear") == 0)
    {
        return 2;
    }

    return 0;
    
}