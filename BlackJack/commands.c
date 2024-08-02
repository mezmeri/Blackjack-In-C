#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "headers/card.h"
#include "headers/stack.h"
#include "headers/services.h"

void command_hit(Stack *pPlayerHand, Stack *pStack)
{
    Node *temp = pPlayerHand->top;
    Node *newNode = deal(pStack);

    pPlayerHand->top = newNode;
    pPlayerHand->top->pNext = temp;
}

// If the player stands at any point, the dealers end-game turn should begin. This means that the dealer should reveal their second card, and then begin to add cards to their stack until a value greater than or equal to 16 is reached.
void command_stand(Stack *pDealerHand, Stack *pPlayerHand, Stack *pStack)
{
    int dealerHandValue = get_value_of_hand(pDealerHand, false);
    int playerHandValue = get_value_of_hand(pPlayerHand, false);
    printf("\e[1;1H\e[2J");
    printf("You stand on %d\nDealers hand is %d\n", playerHandValue, dealerHandValue);

    while (dealerHandValue <= 16)
    {
        printf("\e[1;1H\e[2J");
        printf("Dealing.....");
        Node *temp = pDealerHand->top;
        Node *newNode = deal(pStack);

        pDealerHand->top = newNode;
        pDealerHand->top->pNext = temp;
        dealerHandValue = get_value_of_hand(pDealerHand, false);
        printf("Dealers new hand: %d", dealerHandValue);
    }
}

// This function might be redundant....
Stack *command_view()
{
}

// Read the valid command and call the correct function.
void read_command(char command, Stack *pPlayerHand, Stack *pDealerHand, Stack *pStack)
{
    command = (char)command;
    switch (command)
    {
    case 'X':
        command_hit(pPlayerHand, pStack);
        break;

    case 'x':
        command_hit(pPlayerHand, pStack);
        break;

    case 'C':
        command_stand(pDealerHand, pPlayerHand, pStack);
        break;

    case 'c':
        command_stand(pDealerHand, pPlayerHand, pStack);
        break;

    case 'V':

        break;

    case 'v':

        break;

    default:
        break;
    }
}

// Returns positive number if the command is valid. If the command is not valid it will return -1.
int check_if_valid_command(char *command)
{
    for (int i = 0; i < strlen(command); i++)
    {
        if (i > 1)
        {
            return -1;
        }
    }

    switch (*command)
    {
    case 'X':
        return 1;
        break;

    case 'x':
        return 1;
        break;

    case 'C':
        return 1;
        break;

    case 'c':
        return 1;
        break;

    case 'V':
        return 1;
        break;

    case 'v':
        return 1;
        break;

    default:
        return -1;
        break;
    }
}