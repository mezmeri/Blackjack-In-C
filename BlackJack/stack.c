#include <stdio.h>
#include <stdlib.h>
#include "card.h"
#include "stack.h"

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

// Only use before isGameRunning is sat
Stack *initialize_stack()
{
    Stack *pStack = (Stack *)malloc(sizeof(Stack));
    pStack->top = NULL;
    return pStack;
}

void isEmpty(Stack *pStack)
{
}

Card *deal(Stack *pStack)
{
    if (pStack == NULL)
    {
        return NULL;
    }

    Card *card;
    Node *temp = pStack->top;
    card = pStack->top->pData;
    pStack->top = pStack->top->pNext;
    free(temp);

    return card;
}

void push(Card *cardToBeAdded, Stack *pStack)
{
    Node *pNode = malloc(sizeof(Node));
    pNode->pData = cardToBeAdded;
    if (pStack->top == NULL)
    {
        pStack->top = pNode;
        pStack->top->pNext = NULL;
    }
    else
    {
        pNode->pNext = pStack->top;
        pStack->top = pNode;
    }
}