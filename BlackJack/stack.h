#include <stdlib.h>
#include "card.h"

#ifndef STACK_H
#define STACK_H

typedef struct Node Node;
typedef struct Node
{
    // Maybe it should just contain the actual data instead of a pointer to the data? pointer hell incoming
    Card *pData;
    Node *pNext;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *initialize_stack();

void isEmpty(Stack *pStack);

Card *deal(Stack *pStack);

void push(Card *cardToBeAdded, Stack *pStack);

#endif