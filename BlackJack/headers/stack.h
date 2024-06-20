#include <stdlib.h>
#include "card.h"

#ifndef STACK_H
#define STACK_H

typedef struct Node Node;
typedef struct Node
{
    Card data;
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

int amount(Stack *pStack);

#endif