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

Card *command_see_hand()
{
}