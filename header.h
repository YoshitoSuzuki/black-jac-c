#ifndef HEADER_H
#define HEADER_H

#define N 52
#define waitTime 1

enum Role {
    DEALER,
    PLAYER
};

typedef struct actor {
    enum Role role;
    int tip;
    int cards[N];
    int count;
    int score[4];
    int ACount;
    int isBust; // 0: not bust, 1: bust
    int firstTip;
    int maxTip;
} Actor;

void initializeDeck(int *deck);
void initializeScoreDeck(int *scoreDeck);
void initializeShowCard(char showCard[N][3]);
void initializeActor(Actor *actor);
int drawCard(int *deck, int *scoreDeck, Actor *actor);
int printActor(char showCard[N][3], Actor *actor);
void overWriteScore(Actor *actor);
void printHaveTip(Actor *actor, int bet, int result); // 0: lose, 1: win, 2: draw

#endif