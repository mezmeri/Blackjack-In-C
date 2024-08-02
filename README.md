# Blackjack in C

This project is just a way for me to learn and experiment with data structures in C, and in the meantime create a simple game of blackjack. 😎

**Some nerdy info:**
### Shuffle algorithm
I've used the Fisher-Yates algorithm for shuffling the cards in the array. This was a great success.

### Card deck effect
I've built a stack to resemble the card deck that is used in the game. This stack have a 'top' attribute, which is a pointer to the top card in the deck. The top card is only the one that can be dealt.

### The game logic
The game is very, very simple. Currently, I haven't implemented the Ace rule, which makes Aces either count as 1 or 11. Currently, all Aces count as 1.

You can't split your deck either. I might implement it just for fun, but I didn't deem it necesarry. You also can't double down, as there are no stakes involved in the game.

![image](https://github.com/user-attachments/assets/3682a3ed-aba2-4346-b630-750b8067ad5a)

![image](https://github.com/user-attachments/assets/e2fe315f-ad5f-4b84-983b-d0b6c794255d)

![image](https://github.com/user-attachments/assets/8813ca29-1556-45eb-9fb8-ab98a4814609)
