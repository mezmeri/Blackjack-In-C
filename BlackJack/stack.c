#include <stdio.h>
#include <stdlib.h>
#include "headers/card.h"
#include "headers/stack.h"

Stack *initialize_stack()
{
    Stack *pStack = (Stack *)malloc(sizeof(Stack));
    if (pStack == NULL)
    {
        printf(stderr, "Memory allocation failed");
    }
    pStack->top = NULL;
    return pStack;
}

int isEmpty(Stack *pStack)
{
}

Node *deal(Stack *pStack)
{
    if (pStack == NULL)
    {
        return NULL;
    }

    if (pStack->top == NULL)
    {
        printf("Card stack is empty.");
        return NULL;
    }

    Node *pNode = pStack->top;
    pStack->top = pStack->top->pNext;
    pNode->pNext = NULL;

    return pNode;
}

void push(Card *cardToBeAdded, Stack *pStack)
{
    Node *pNode = (Node *)malloc(sizeof(Node));

    pNode->data = *cardToBeAdded;
    if (pStack->top == NULL)
    {
        pStack->top = pNode;
        pStack->top->pNext = NULL;
    }

    if (pNode != NULL)
    {
        pNode->pNext = pStack->top;
        pStack->top = pNode;
    }
}