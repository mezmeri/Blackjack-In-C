#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "stack.c"
#include <string.h>

typedef struct
{
    int size;
    Card deck[52];
} cardStruct;

cardStruct *shuffle_card_stack(cardStruct *cardStack)
{
    srand(time(NULL));
    for (int i = 52; i > 0; i--)
    {
        Card temp = cardStack->deck[i];
        int random = rand() % 52;
        cardStack->deck[i] = cardStack->deck[random];
        cardStack->deck[random] = temp;
    }

    return (cardStruct *)cardStack;
}

cardStruct *generate_empty_card_stack()
{
    cardStruct *cardStack = malloc(sizeof(cardStruct));
    cardStack->size = 52;
    if (cardStack == NULL)
    {
        printf("Memory allocation error at generate_card_stack!");
        return NULL;
    }

    cardStack->size = 52;

    return cardStack;
}

cardStruct *generate_card_data(cardStruct *cardStack)
{
    Card card;
    unsigned int j = 0;
    for (int Suit = Spades; Suit <= Clubs; Suit++)
    {
        card.cardSuit = Suit;
        for (int Face = Ace; Face <= King; Face++)
        {
            card.cardFace = Face;
            cardStack->deck[j] = card;
            j++;
        }
    }
    cardStack = shuffle_card_stack(cardStack);
    return cardStack;
}

void deal_cards(Card *playerHand, Card *dealerHand, Stack *stack)
{
    for (int i = 0; i < 2; i++)
    {
        playerHand[i] = *deal(stack);
        dealerHand[i] = *deal(stack);
    }
}

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

int get_value_of_player_hand(Card *card, int deckSize)
{
    int value = 0;
    for (int i = 0; i < deckSize; i++)
    {
        value += card->cardFace;
        card += 1;
    }
    return value;
}

int get_value_of_dealer_hand(Card *card, int deckSize)
{
    int value = 0;
    value += card->cardFace;
    return value;
}

int main(void)
{
    // PRE-GAME PREPARATION
    bool isGameRunning = false;
    cardStruct *emptyCardStack = (cardStruct *)generate_empty_card_stack();

    cardStruct *cardStack = generate_card_data(emptyCardStack);
    Stack *stack = initialize_stack();

    for (int i = 0; i < 52; i++)
    {
        push(&cardStack->deck[i], stack);
    }

    int capacity = 2;
    Card *playerHand = (Card *)malloc(capacity * sizeof(Card));
    Card *dealerHand = (Card *)malloc(capacity * sizeof(Card));
    if (playerHand == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 0;
    }

    // START GAME
    isGameRunning = true;
    while (isGameRunning)
    {
        int playerHandValue = 0;
        int dealerHandValue = 0;

        printf("Dealing cards.....\n");

        deal_cards(playerHand, dealerHand, stack);

        printf("Cards have been dealt.\n");

        playerHandValue = get_value_of_player_hand(playerHand, capacity);
        dealerHandValue = get_value_of_dealer_hand(dealerHand, capacity);
        printf("YOUR HAND: %d\n", playerHandValue);
        printf("DEALER HAND: %d\n", dealerHandValue);
        printf("HIT: X\nSTAND: C\nHAND: V\n");

        isGameRunning = false;
    }

    free(stack);
    free(playerHand);
    free(dealerHand);
    return 0;
}

// 5) Read the values of the players card, and ask the player to 'Hit' or 'Stand'.

// 6) If the player 'Hit's, reevalutate the cards and see if the new value is lower, equal to or higher than 21.

// 6.2) If the value is lower, give the player a new chance to 'Hit', 'Stand'.

// 7) If the player stands, reveal the dealers second card. If the sum of the cards are lower than 16, the dealer will take another card until the sum is > 16.

// 8) If the dealers card sum is higher (but > 21) than the players, the player loses. If the players card is higher than the dealer or the player has hit blackjack, the player wins automatically. The same goes for the dealer.