#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void initializeDeck(int *deck) {
    for (int i=0; i<N; i++) {
        deck[i] = 1;
    }
}

void initializeScoreDeck(int *scoreDeck) {
    for (int i=0; i<N; i++) {
        if (i % 13 < 10) {
            scoreDeck[i] = i % 13 + 1;
        } else if (i % 13 >= 10) {
            scoreDeck[i] = 10;
        }
    }
}

void initializeShowCard(char showCard[N][3]) {
    srand(time(NULL));
    for (int i=0; i<N; i++) {
        int s = i/13;
        if (s == 0) {
            showCard[i][0] = 'H';
        } else if (s == 1) {
            showCard[i][0] = 'D';
        } else if (s == 2) {
            showCard[i][0] = 'C';
        } else {
            showCard[i][0] = 'S';
        }
        
        int r = i%13;
        char ranks[] = "A23456789TJQK";
        showCard[i][1] = ranks[r];

        showCard[i][2] = '\0';
    }
    showCard[52][0] = '?';
    showCard[52][1] = '?';
    showCard[52][2] = '\0';
}

void initializeActor(Actor *actor) {
    actor->count = 0;
    for (int i=0; i<4; i++) {
        actor->score[i] = 0;
    }
    actor->ACount = 0;
    actor->isBust = 0;
    actor->judge = -1;
    actor->action = 'p';
}

int drawCard(int *deck, int *scoreDeck, Actor *actor) {
    int count = 0;
    while (count < 1000) {
        int random = rand() % 52;
        if (deck[random]) {
            deck[random] = 0;
            actor->cards[actor->count] = random;
            actor->count++;
            for (int i=0; i<4; i++) {
                actor->score[i] += scoreDeck[random];
            }
            if (scoreDeck[random] == 1) {
                for (int j=actor->ACount+1; j<4; j++) {
                    actor->score[j] += 10;
                }
                actor->ACount++;
            }

            overWriteScore(actor);

            if (actor->score[0] > 21) {
                return 1;
            }
            return 0;
        }
        count++;
    }
    return -1;
}

int printActor(char showCard[N][3], Actor *actor) {
    printf("***********");
    if (actor->role == DEALER) {
        printf("Dealer");
    } else {
        printf("Player");
    }
    printf("***********\n");
    for (int i=0; i<actor->count; i++) {
        printf("%s ", showCard[actor->cards[i]]);
    }
    printf("\n");
    printScore(actor);
    printf("\n");
    return 0;
}

void printScore(Actor *actor) {
    printf("Score: %d", actor->score[0]);
    for (int i=0; i<3; i++) {
        if (actor->score[i] != actor->score[i+1] && actor->score[i+1] != 0) {
            printf(" / %d", actor->score[i+1]);
        }
    }
}

void getBestScore(Actor *actor) {
    actor->bestScore = actor->score[0];
    for (int i = 1; i < 4; i++) {
        if (actor->score[i] <= 21 && actor->score[i] > actor->bestScore) {
            actor->bestScore = actor->score[i];
        }
    }
}

void overWriteScore(Actor *actor) {
    for (int i=1; i<4; i++) {
        if (actor->score[i] > 21) {
            actor->score[i] = actor->score[i-1];
        }
    }
}

void printScreen(Actor *player, char text[MAX_TEXT_LENGTH]) {
    int inGame = 1;

    if (inGame) {
        printf("\n");
        printf("========================================\n");
        printf("========================================\n");
        printf("\n");
        printf("----------------------------------------\n");
        printf("You have %d tip\n", player->tip);
        printf("----------------------------------------\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("%s\n", text);
        printf("\n");
        printf("----------------------------------------\n");
        printf("\n");
        printf("========================================\n");
        printf("========================================\n");
        printf("\n");
    }
}

void printHaveTip(Actor *actor, int bet, int result) { // 0: lose, 1: win, 2: draw
    if (result == 0) {
        actor->tip -= bet;
        printf("You lose!\n");
        printf("Tip: -%d\n", bet);
    } else if (result == 1) {
        actor->tip += bet;
        printf("You win!\n");
        printf("Tip: +%d\n", bet);
    } else if (result == 2) {
        printf("Draw!\n");
        printf("Tip: ±0\n");
    }
    printf("\n");
    sleep(waitTime);
    printf("----------------------------------------\n");
    printf("\n");
    printf("You have %d tip\n", actor->tip);
    printf("\n");
}