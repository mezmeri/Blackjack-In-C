#include <stdio.h>

typedef enum
{
    Spades = 1,
    Hearts = 2,
    Diamonds = 3,
    Clubs = 4
} suit;

typedef enum
{
    Ace = 1,
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13

} face;

typedef struct
{
    suit cardSuit;
    face cardFace;

} card;

// 1) Generate card-stack of Card structures
card cardStack[52];

void generate_card_stack()
{
    for (int i = 0; i < sizeof(cardStack); i++)
    {
        card card;
        for (int suit = Hearts; suit <= Clubs; suit++)
        {
            card.cardSuit = suit;
            for (int face = Ace; face <= King; face++)
            {
                card.cardFace = face;
            }
        }
        cardStack[i] = card;
    }
}

// 2) Shuffle the card stack

// 3) Give the player two cards

// 4) Give the dealer two cards, but only reveal the first card

// 5) Read the values of the players card, and ask the player to 'Hit', 'Stand' or 'Fold'

// 6) If the player 'Hit's, reevalutate the cards and see if the new value is lower, equal to or higher than 21.

// 6.2) If the value is lower, give the player a new chance to 'Hit', 'Stand' or 'Fold'.

// 7) If the player stands, reveal the dealers second card. If the sum of the cards are lower than 17, the dealer will take another card until the sum is >= 17.

// 8) If the dealers card sum is higher than the players, the player loses. If the players card is higher than the dealer or the player has hit blackjack, the player wins automatically. The goes for the dealer.

int main(void)
{
    generate_card_stack();

    // Printing elements from cardStack
    for (int i = 0; i < sizeof(cardStack) / sizeof(cardStack[0]); i++)
    {
    }

    return 0;
}