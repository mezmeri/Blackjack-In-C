#include <stdlib.h>
#include "card.h"
#include "stack.h"

#ifndef COMMANDS_H
#define COMMANDS_H
void command_hit(Card *pPlayerHand, Stack *pStack);

void command_stand(Stack *pDealerHand, Stack *pPlayerHand, Stack *pStack);

Stack *command_view();

void read_command(char command, Stack *pPlayerHand, Stack *pDealerHand, Stack *pStack);

int check_if_valid_command(char *command);

#endif