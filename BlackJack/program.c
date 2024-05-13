#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "queue.c"

// 1) Generate card-stack of Card structures
card *get_card_stack()
{
    static card cardStack[52];
    return cardStack;
}

int evaluate_hand_value(card *deck)
{
}

card *get_player_hand()
{
    static card playerHand[10];
    return playerHand;
}

void update_player_hand(card newCard)
{
    card *pPlayerHand = get_player_hand();
    for (int i = 0; i < sizeof(pPlayerHand) / sizeof(pPlayerHand[0]); i++)
    {
        if (&pPlayerHand[i] == NULL)
        {
            pPlayerHand[i] = newCard;
        }
    }
}

card *get_dealer_hand()
{
    static card dealerHand[10];
    return dealerHand;
}

void generate_card_stack()
{
    card *cardStack = get_card_stack();
    card card;
    int j = 0;
    for (int suit = Spades; suit <= Clubs; suit++)
    {
        card.cardSuit = suit;
        for (int face = Ace; face <= King; face++)
        {
            card.cardFace = face;
            cardStack[j] = card;
            j++;
        }
    }
}

// 2) Shuffle the card stack
void shuffle_card_stack()
{
    card *cardStack = get_card_stack();
    int deckSize = sizeof(cardStack) / sizeof(cardStack[0]) - 1;
    for (int i = deckSize; i >= 0; i--)
    {
        card temp = cardStack[i];
        int random = rand() % deckSize;
        cardStack[i] = cardStack[random];
        cardStack[random] = temp;
    }
}

void add_cards_to_queue(card *cardStack)
{
    int deckSize = sizeof(cardStack) / sizeof(cardStack[0]);
    for (int i = 0; i < deckSize; i++)
    {
        enqueue(&cardStack[i]);
    }
}

// 3) Give the player two cards
// 4) Give the dealer two cards, but only reveal the first card

void deal_cards_first_round(card *pPlayerHand, card *pDealerHand)
{
    card *cardStack = get_card_stack();
    for (int i = 0; i <= 2; i++)
    {
        pPlayerHand[i] = cardStack[i];
        pDealerHand[i] = cardStack[i + 1];
    }
}

int evaluate_cards(card *pCard)
{
    int counter = 0;
    int deckSize = sizeof(*pCard) / (sizeof(pCard[0]));
    for (int i = 0; i < deckSize; i++)
    {
        counter += pCard[i].cardFace;
    }

    return counter;
}

int main(void)
{
    generate_card_stack();
    // shuffle_card_stack();

    card newcard;
    newcard.cardFace = 2;
    newcard.cardSuit = 2;
    enqueue(&newcard);

    return 0;
}

// 5) Read the values of the players card, and ask the player to 'Hit' or 'Stand'.

// 6) If the player 'Hit's, reevalutate the cards and see if the new value is lower, equal to or higher than 21.

// 6.2) If the value is lower, give the player a new chance to 'Hit', 'Stand'.

// 7) If the player stands, reveal the dealers second card. If the sum of the cards are lower than 16, the dealer will take another card until the sum is > 16.

// 8) If the dealers card sum is higher (but > 21) than the players, the player loses. If the players card is higher than the dealer or the player has hit blackjack, the player wins automatically. The same goes for the dealer.