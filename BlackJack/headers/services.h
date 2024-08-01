
#ifndef DLLOGIC
#define DLLOGIC
#include <stdio.h>
#include <stdbool.h>

void deal_cards_first_round(Stack *pPlayerHand, Stack *pDealerHand, Stack *stack);
int get_value_of_hand(Stack *pStack, bool showFirstCardOnly);
#endif