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

char *get_card_name(Card card)
{
    switch (card.cardSuit)
    {
    case Spades:
        "Spades";
        break;

    case Hearts:
        "Hearts";
        break;

    case Diamonds:
        "Diamonds";
        break;

    case Clubs:
        "Clubs";
        break;

    default:
        "Couldn't find card suit.";
    }

    switch (card.cardFace)
    {
    case Ace:
        "Ace";
        break;

    case Two:
        "Two";
        break;

    case Three:
        "Three";
        break;

    case Four:
        "Four";
        break;

    case Five:
        "Five";
        break;

    case Six:
        "Six";
        break;

    case Seven:
        "Seven";
        break;

    case Eight:
        "Eight";
        break;

    case Nine:
        "Nine";
        break;

    case Ten:
        "Ten";
        break;

    case Jack:
        "Jack";
        break;

    case Queen:
        "Queen";
        break;

    case King:
        "King";
        break;

    default:
        "Couldn't find card.face";
    }

    char cardName[10];
}

int main(void)
{
    cardStruct *emptyCardStack = (cardStruct *)generate_empty_card_stack();

    // Generate card data and shuffle the cards
    cardStruct *cardStack = generate_card_data(emptyCardStack);

    Stack *stack = initialize_stack();

    for (int i = 0; i < 52; i++)
    {
        push(&cardStack->deck[i], stack);
    }

    free(stack);
    return 0;
}

// 5) Read the values of the players card, and ask the player to 'Hit' or 'Stand'.

// 6) If the player 'Hit's, reevalutate the cards and see if the new value is lower, equal to or higher than 21.

// 6.2) If the value is lower, give the player a new chance to 'Hit', 'Stand'.

// 7) If the player stands, reveal the dealers second card. If the sum of the cards are lower than 16, the dealer will take another card until the sum is > 16.

// 8) If the dealers card sum is higher (but > 21) than the players, the player loses. If the players card is higher than the dealer or the player has hit blackjack, the player wins automatically. The same goes for the dealer.