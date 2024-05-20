#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "queue.c"
#include <string.h>

// This might be a little to hard to read in the context of the game I'm trying to create...
typedef struct
{
    int size;
    card deck[52];
} cardStruct;

cardStruct *shuffle_card_stack(cardStruct *cardStack)
{
    for (int i = 52; i >= 0; i--)
    {
        // Fisher-Yates shuffle algorithm
        card temp = cardStack->deck[i];
        int random = rand() % 52;
        cardStack->deck[i] = cardStack->deck[random];
        cardStack->deck[random] = temp;
    }

    return (cardStruct *)cardStack;
}

// 1) Generate empty card-stack of Card structures
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

// **Populate the empty card stack with actual data
cardStruct *generate_card_data(cardStruct *cardStack)
{
    card card;
    unsigned int j = 0;
    for (int suit = Spades; suit <= Clubs; suit++)
    {
        card.cardSuit = suit;
        for (int face = Ace; face <= King; face++)
        {
            card.cardFace = face;
            cardStack->deck[j] = card;
            j++;
        }
    }
    cardStack = shuffle_card_stack(cardStack);
    return cardStack;
}

// Looooong ahhh converter function
char *get_card_name(card card)
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

// 3) Give the player two cards
// 4) Give the dealer two cards, but only reveal the first card

// void deal_cards_first_round(card *pPlayerHand, card *pDealerHand)
// {
//     card *cardStack = return_current_card_stack();
//     for (int i = 0; i <= 2; i++)
//     {
//         pPlayerHand[i] = cardStack[i];
//         pDealerHand[i] = cardStack[i + 1];
//     }
// }

int main(void)
{
    cardStruct *emptyCardStack = (cardStruct *)generate_empty_card_stack();

    // Generate card data and shuffle the cards
    cardStruct *cardStack = generate_card_data(emptyCardStack);

    // printf("SIZE: %d bytes", sizeof(*emptyCardStack));
    // shuffle_card_stack();

    // card newcard;
    // newcard.cardFace = 2;
    // newcard.cardSuit = 2;
    // enqueue(&newcard);

    return 0;
}

// 5) Read the values of the players card, and ask the player to 'Hit' or 'Stand'.

// 6) If the player 'Hit's, reevalutate the cards and see if the new value is lower, equal to or higher than 21.

// 6.2) If the value is lower, give the player a new chance to 'Hit', 'Stand'.

// 7) If the player stands, reveal the dealers second card. If the sum of the cards are lower than 16, the dealer will take another card until the sum is > 16.

// 8) If the dealers card sum is higher (but > 21) than the players, the player loses. If the players card is higher than the dealer or the player has hit blackjack, the player wins automatically. The same goes for the dealer.