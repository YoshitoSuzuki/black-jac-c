#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct deck {
    char suit;
    char rank;
} Deck;

int main(void) {
    Deck theDeck[52];
    char suits[4] = {'H', 'D', 'C', 'S'};
    char ranks[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            theDeck[i * 13 + j].suit = suits[i];
            theDeck[i * 13 + j].rank = ranks[j];
        }
    }
    
    return 0;
}