#include <stdio.h>
#include "headers/stack.h"
#include "headers/card.h"
#include "headers/services.h"

void deal_cards_first_round(Stack *pPlayerHand, Stack *pDealerHand, Stack *pStack)
{
    for (unsigned int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            pPlayerHand[i].top = deal(pStack);
            pDealerHand[i].top = deal(pStack);
        }
        else
        {
            pPlayerHand->top->pNext = deal(pStack);
            pDealerHand->top->pNext = deal(pStack);

            pPlayerHand->top->pNext->pNext = NULL;
            pDealerHand->top->pNext->pNext = NULL;
        }
    }
}