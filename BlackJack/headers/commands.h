
#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdlib.h>
#include "headers/card.h"
#include "headers/stack.h"

void command_hit(Card *pPlayerHand, Stack *pStack);

void command_stand();

Card *command_see_hand();

int check_if_valid_command(char *command);

void read_command(char command, Card *pPlayerHand, Stack *pStack);

#endif