#include <stdlib.h>
#include <stdio.h>
#include "card.h"
#include "stack.h"

void command_hit(Card *pPlayerHand, int *pCapacity, Stack *pStack)
{
    pPlayerHand = realloc(pPlayerHand, sizeof(Card));

    *pCapacity++;

    pPlayerHand[*pCapacity] = *deal(pStack);
}

void command_stand()
{
}

Card *command_see_player_hand()
{
}

// Returns positive number if the command is valid. If the command is not valid it will return -1.
int check_if_valid_command(char command)
{
    switch (command)
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