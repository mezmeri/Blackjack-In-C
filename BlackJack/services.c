#include <stdio.h>
#include "headers/stack.h"
#include "headers/card.h"
#include "headers/services.h"

void deal_cards_first_round(Stack *pPlayerHand, Stack *pDealerHand, Stack *stack)
{
    for (unsigned int i = 0; i < 2; i++)
    {
        pPlayerHand[i].top = deal(&stack);
        pDealerHand[i].top = deal(&stack);
    }
}