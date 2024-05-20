#include <stdio.h>
#include <stdlib.h>
#include "card.c"

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

Stack *initialize_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty()
{
}

int isFull()
{
}

Card *deal(Stack *stack)
{
    if (stack == NULL)
    {
        return NULL;
    }

    Card *card;
    Node *temp = stack->top;
    card = stack->top->pData;
    stack->top = stack->top->pNext;
    free(temp);

    return card;
}

void push(Card *cardToBeAdded, Stack *stack)
{
    Node *node = malloc(sizeof(Node));
    node->pData = cardToBeAdded;
    if (stack->top == NULL)
    {
        stack->top = node;
        stack->top->pNext = NULL;
    }
    else
    {
        node->pNext = stack->top;
        stack->top = node;
    }
}