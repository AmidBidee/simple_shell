#include "main.h"

/**
 * parseCommands - this reads info from the stdin and breaks them
 *                  into null terminated entries for *command
 * @bufferarg: this is used to temproarily store stdin for iteration
 * @command: this points to arrays of null terminated arguments
 * Return : returns -1 if there is an error or 1 if its through
 */



int parseCommands(char *bufferarg, char **command)
{
    if(fgets(bufferarg, sizeof(bufferarg), stdin) != NULL)
    {
        /*needs more work for implementation*/
        return 0;
    }
    else
    {
        return -1;
    }
}