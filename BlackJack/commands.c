#include <stdlib.h>
#include <stdio.h>
#include "headers/card.h"
#include "headers/stack.h"
#include <string.h>

void command_hit(Card *pPlayerHand, Stack *pStack)
{
    pPlayerHand = realloc(pPlayerHand, sizeof(Card));
}

void command_stand()
{
}

Card *command_view()
{
}

// Read the valid command and call the correct function.
void read_command(char command, Stack *pPlayerHand, Stack *pStack)
{
    command = (char)command;
    switch (command)
    {
    case 'X':
        command_hit(pPlayerHand, pStack);
        break;

    case 'x':
        command_hit(pPlayerHand, pStack);
        break;

    case 'C':

        break;

    case 'c':

        break;

    case 'V':

        break;

    case 'v':

        break;

    default:
        break;
    }
}

// Returns positive number if the command is valid. If the command is not valid it will return -1.
int check_if_valid_command(char *command)
{
    for (int i = 0; i < strlen(command); i++)
    {
        if (i > 1)
        {
            return -1;
        }
    }

    switch (*command)
    {
    case 'X':
        return 1;
        break;

    case 'x':
        return 1;
        break;

    case 'C':
        return 1;
        break;

    case 'c':
        return 1;
        break;

    case 'V':
        return 1;
        break;

    case 'v':
        return 1;
        break;

    default:
        return -1;
        break;
    }
}