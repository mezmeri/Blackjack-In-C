#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "headers/card.h"
#include "headers/stack.h"
#include "headers/commands.h"

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

cardStackStruct *generate_card_data(cardStackStruct *pCardStack)
{
    Card card;
    unsigned int j = 0;
    for (int Suit = Spades; Suit <= Clubs; Suit++)
    {
        card.cardSuit = Suit;
        for (int Face = Ace; Face <= King; Face++)
        {
            card.cardFace = Face;
            pCardStack->deck[j] = card;
            j++;
        }
    }
    pCardStack = shuffle_card_stack(pCardStack);
    return pCardStack;
}

// Might need to put this in another file
char *get_card_name(Card card)
{
    static char cardName[50];
    char suitName[50];
    char faceName[50];

    switch (card.cardSuit)
    {
    case Spades:
        strcpy(suitName, "Spades");
        break;

    case Hearts:
        strcpy(suitName, "Hearts");
        break;

    case Diamonds:
        strcpy(suitName, "Diamonds");
        break;

    case Clubs:
        strcpy(suitName, "Clubs");
        break;

    default:
        strcpy(suitName, "Couldn't find card suit.");
    }

    switch (card.cardFace)
    {
    case Ace:
        strcpy(faceName, "Ace");
        break;

    case Two:
        strcpy(faceName, "Two");
        break;

    case Three:
        strcpy(faceName, "Three");
        break;

    case Four:
        strcpy(faceName, "Four");
        break;

    case Five:
        strcpy(faceName, "Five");
        break;

    case Six:
        strcpy(faceName, "Six");
        break;

    case Seven:
        strcpy(faceName, "Seven");
        break;

    case Eight:
        strcpy(faceName, "Eight");
        break;

    case Nine:
        strcpy(faceName, "Nine");
        break;

    case Ten:
        strcpy(faceName, "Ten");
        break;

    case Jack:
        strcpy(faceName, "Jack");
        break;

    case Queen:
        strcpy(faceName, "Queen");
        break;

    case King:
        strcpy(faceName, "King");
        break;

    default:
        strcpy(faceName, "Couldn't find card.face");
    }

    snprintf(cardName, sizeof(cardName), "%s of %s", faceName, suitName);
    return cardName;
}

int main(void)
{
    bool isGameRunning = false;
    cardStackStruct *emptyCardStack = (cardStackStruct *)generate_empty_card_stack();
    cardStackStruct *cardStack = generate_card_data(emptyCardStack);

    // The card stack used in the game
    Stack *pStack = initialize_stack();
    for (int i = 0; i < 52; i++)
    {
        push(&cardStack->deck[i], pStack);
    }

    Stack *pPlayerHand = (Stack *)initialize_stack();
    Stack *pDealerHand = (Stack *)initialize_stack();

    int playerHandValue = 0;
    int dealerHandValue = 0;

    printf("\nDealing cards.....\n");

    printf("Cards have been dealt.\n\n");

    char userInput[1];

    printf("YOUR HAND: %d\nDEALER: %d\n\n", playerHandValue, dealerHandValue);

    // START THE ACTUAL GAME
    isGameRunning = true;
    while (isGameRunning)
    {
        printf("CHOOSE ACTION:\n1. HIT (X)\n2. STAND (C)\n3. VIEW (V)\n$: ");
        scanf("%s", &userInput);

        // Making sure the player can't type in multiple characters and break the system by using a function to check if the command is actually valid. If the command is valid check_if_valid_command() will return 1. If not, it will return -1.
        int isValidCommand = check_if_valid_command(userInput);
        while (isValidCommand == -1)
        {
            // Clear the console so that the error message doesn't clutter the terminal.
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
            printf("%d\n", playerHandValue);
            printf("SHIT U HIT A BITCH");
        }

        // Add a condition that sets this to false instead of it being falsed at the end of the while-loop.
        isGameRunning = false;
    }

    free(pStack);
    return 0;
}

// 5) Read the values of the players card, and ask the player to 'Hit' or 'Stand'.

// 6) If the player 'Hit's, reevalutate the cards and see if the new value is lower, equal to or higher than 21.

// 6.2) If the value is lower, give the player a new chance to 'Hit', 'Stand'.

// 7) If the player stands, reveal the dealers second card. If the sum of the cards are lower than 16, the dealer will take another card until the sum is > 16.

// 8) If the dealers card sum is higher (but > 21) than the players, the player loses. If the players card is higher than the dealer or the player has hit blackjack, the player wins automatically. The same goes for the dealer.