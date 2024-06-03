#include <stdlib.h>
#include <stdio.h>
#include "card.h"

void command_hit(Card *pPlayerHand, int *pCapacity)
{
    pPlayerHand = realloc(pPlayerHand, sizeof(Card));
    *pCapacity++;
}

void command_stand()
{
}

Card *command_see_hand()
{
}