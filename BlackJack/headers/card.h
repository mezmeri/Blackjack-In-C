#include <stdio.h>

#ifndef CARD_H
#define CARD_H

typedef enum
{
    Spades,
    Hearts,
    Diamonds,
    Clubs,
} Suit;

typedef enum
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King

} Face;

typedef struct
{
    Suit cardSuit;
    Face cardFace;
    int value;

} Card;

#endif