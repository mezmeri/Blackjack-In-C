#include <stdlib.h>
#include "card.h"
#include "stack.h"

#ifndef COMMANDS_H
#define COMMANDS_H

void command_hit(Card *pPlayerHand, int *pCapacity, Stack *pStack);

void command_stand();

Card *command_see_hand();

#endif