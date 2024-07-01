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

// Remove the top card from the stack
Card *deal(Stack *pStack)
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

    Card card;
    Node *temp = pStack->top;
    card = temp->data;
    pStack->top = pStack->top->pNext;

    free(temp);

    return &card;
}

// Add card to the top of the stack
void push(Card *cardToBeAdded, Stack *pStack)
{
    Node *pNode = malloc(sizeof(Node));

    pNode->data = *cardToBeAdded;

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
    free(pNode);
}