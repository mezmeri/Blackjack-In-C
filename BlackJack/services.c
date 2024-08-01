#include <stdio.h>
#include <stdbool.h>
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

int get_value_of_hand(Stack *pStack, bool showFirstCardOnly)
{
    int result = 0;

    Node *current = pStack->top;

    if(showFirstCardOnly)
    {
        result += current->data.value;
        return result;
    }

    while (current != NULL)
    {
        result += current->data.value;
        current = current->pNext;

        if (current->pNext == NULL)
        {
            result += current->data.value;
            break;
        }
    }

    return result;
}