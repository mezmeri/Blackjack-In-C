
#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdlib.h>
#include "card.h"
#include "stack.h"

void command_hit(Card *pPlayerHand, int *pCapacity, Stack *pStack);

void command_stand();

Card *command_see_hand();

int check_if_valid_command(char *command);

#endif