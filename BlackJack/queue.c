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

typedef struct
{
    card *pNode;
    card *pNextCard;
} node;

int isEmpty()
{
}

int isFull()
{
}

void dequeue()
{
}

void enqueue(card *cardToBeAdded)
{
    printf("%p\n", (void *)cardToBeAdded);
    card newCard = *cardToBeAdded;
    printf("%p", newCard);
}