#include <stdlib.h>
#include "headers/card.h"

#ifndef STACK_H
#define STACK_H

typedef struct Node Node;
typedef struct Node
{
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