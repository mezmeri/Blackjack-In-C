#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "headers/card.h"
#include "headers/stack.h"
#include "headers/commands.h"
#include "headers/services.h"

// ### The functions in this file should be moved to another file at some point.
typedef struct
{
    int size;
    Card deck[52];
} cardStackStruct;

cardStackStruct *shuffle_card_stack(cardStackStruct *pCardStack)
{
    srand(time(NULL));
    for (int i = 52; i > 0; i--)
    {
        Card temp = pCardStack->deck[i];
        int random = rand() % 52;
        pCardStack->deck[i] = pCardStack->deck[random];
        pCardStack->deck[random] = temp;
    }

    return (cardStackStruct *)pCardStack;
}

cardStackStruct *generate_empty_card_stack()
{
    cardStackStruct *cardStack = malloc(sizeof(cardStackStruct));
    cardStack->size = 52;
    if (cardStack == NULL)
    {
        printf("Memory allocation error at generate_card_stack!");
        return NULL;
    }

    cardStack->size = 52;

    return cardStack;
}

cardStackStruct *generate_card_data(cardStackStruct *pStack)
{
    Card card;
    unsigned int j = 0;
    for (int Suit = Spades; Suit <= Clubs; Suit++)
    {
        card.cardSuit = Suit;
        for (int Face = Ace; Face <= King; Face++)
        {
            card.cardFace = Face;

            // The cards need to hold their value... Might need to refactor.
            switch (card.cardFace)
            {
            case Ace:
                card.value = 1;
                break;

            case Two:
                card.value = 2;
                break;

            case Three:
                card.value = 3;
                break;

            case Four:
                card.value = 4;
                break;

            case Five:
                card.value = 5;
                break;

            case Six:
                card.value = 6;
                break;

            case Seven:
                card.value = 7;
                break;

            case Eight:
                card.value = 8;
                break;

            case Nine:
                card.value = 9;
                break;

            case Ten:
                card.value = 10;

            case Jack:
                card.value = 10;
                break;

            case Queen:
                card.value = 10;
                break;

            case King:
                card.value = 10;
                break;
            }
            pStack->deck[j] = card;
            j++;
        }
    }
    pStack = shuffle_card_stack(pStack);
    return pStack;
}

int main(void)
{
    bool isGameRunning = false;
    cardStackStruct *emptyCardStack = (cardStackStruct *)generate_empty_card_stack();
    cardStackStruct *cardStack = generate_card_data(emptyCardStack);

    Stack *pStack = initialize_stack();
    for (int i = 0; i < 52; i++)
    {
        push(&cardStack->deck[i], pStack);
    }

    Stack *pPlayerHand = (Stack *)initialize_stack();
    Stack *pDealerHand = (Stack *)initialize_stack();

    printf("\nDealing cards.....\n");

    // Add the dealing functionality of the first round
    deal_cards_first_round(pPlayerHand, pDealerHand, pStack);

    printf("Cards have been dealt.\n\n");

    char userInput[1];
    int playerHandValue = 0;
    int dealerHandValue = 0;

    // START THE ACTUAL GAME
    isGameRunning = true;
    while (isGameRunning)
    {
        playerHandValue = get_value_of_hand(pPlayerHand, false);
        dealerHandValue = get_value_of_hand(pDealerHand, true);

        printf("#############################\n");
        printf("YOUR HAND: %d\n", playerHandValue);
        printf("DEALERS HAND: %d\n", dealerHandValue);
        printf("#############################\n\n");
        printf("CHOOSE ACTION:\n1. HIT (X)\n2. STAND (C)\n3. VIEW (V)\n$: ");
        scanf("%s", &userInput);

        // Making sure the player can't type in multiple characters and break the system by using a function to check if the command is actually valid. If the command is valid the function will return 1. If not, it will return -1 and not break out of the loop.
        int isValidCommand = check_if_valid_command(userInput);
        while (isValidCommand == -1)
        {
            // Clear all text so that the error message doesn't clutter the terminal.
            printf("\e[1;1H\e[2J");

            printf("\nINVALID COMMAND!\n\n");
            printf("CHOOSE ACTION:\n1. HIT (X)\n2. STAND (C)\n3. VIEW (V)\n\n$: ");
            scanf("%s", &userInput);
            isValidCommand = check_if_valid_command(userInput);
            if (isValidCommand == 1)
            {
                break;
            }
        }

        if (isValidCommand)
        {
            read_command(userInput[0], pPlayerHand, pStack);
        }

        if(playerHandValue > 21)
        {
            isGameRunning = false;
            printf("Your hand value is over 21 (%d). You've lost.", playerHandValue);
        }
    }

    free(pStack);
    free(pPlayerHand);
    free(pDealerHand);
    return 0;
}