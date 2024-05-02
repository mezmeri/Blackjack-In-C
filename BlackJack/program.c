#include <stdio.h>

typedef enum
{
    Spade,
    Heart,
    Diamond,
    Club,
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
    Jack,
    Queen,
    King

} face;

typedef struct
{
    suit cardSuit;
    face cardFace;

} Card;

// 1) Generate card-stack

// 2) Shuffle the card stack

// 3) Give the player two cards

// 4) Give the dealer two cards, but only reveal the first card

int main()
{
    return 0;
}