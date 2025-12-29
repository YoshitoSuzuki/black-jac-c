#include "header.h"
#include <stdio.h>

void printSpace(int n) {
    for (int i=0; i<n; i++) {
        printf("\n");
    }
}

void printScreenTopBottom() {
    printf("\n");
    printf("========================================\n");
    printf("========================================\n");
    printf("\n");
}

void printScreen1stSection() {
    printSpace(1);
    printf("----------------------------------------\n");
}

void printScreen2ndSection() {
    printSpace(11);
}

void printScreen3rdSection() {
    printf("----------------------------------------\n");
    printSpace(5);
}

void printScreenMidSection(char text[MAX_TEXT_LENGTH]) {
    printSpace(5);
    printf("%s\n", text);
    printSpace(5);
}

void printScreenMidSectionWithBet(char text[MAX_TEXT_LENGTH], int bet) {
    printf("bet: %d\n", bet);
    printSpace(4);
    printf("%s\n", text);
    printSpace(5);
}

void printScreenWelcom() {
    printSpace(4);
    printf("****************************************\n");
    printf("******** Welcome to Black Jack! ********\n");
    printf("****************************************\n");
    printSpace(4);
}

void printScreenHaveTip(Actor *player) {
    printSpace(1);
    printf("You have %d tip\n", player->tip);
    printf("----------------------------------------\n");
}

void printScreenDicideOwnedTip(Actor *player) {
    printSpace(5);
    printf("Decide your owned tip (1 ~ 2147483647): ");
    scanf(" %d", &player->tip);
    printSpace(5);
}

void printScreenBet(Actor *player, int *bet) {
    printSpace(5);
    printf("How much would you bet? (1 ~ %d): ", player->tip);
    scanf(" %d", bet);
    printSpace(5);
}

void printScreenFirstDrawDeck(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printf("bet: %d", bet);
    printSpace(2);
    printf("**************** Dealer ****************\n");
    printf("%s\n", showCard[dealer->cards[0]]);
    printScore(dealer);
    printSpace(1);
    printf("**************** Player ****************\n");
    for (int i=0; i<player->count; i++) {
        printf("%s\n", showCard[player->cards[i]]);
    }
    printScore(player);
    printSpace(1);
}

// ============================================================================================================================================================
// ============================================================================================================================================================
// ============================================================================================================================================================

void pWelcom() {
    printScreenTopBottom();
    printScreen1stSection();
    printScreenWelcom();
    printScreen3rdSection();
    printScreenTopBottom();
}

void pDecideOwnedTip(Actor *player) {
    printScreenTopBottom();
    printScreen1stSection();
    printScreenDicideOwnedTip(player);
    printScreen3rdSection();
    printScreenTopBottom();
}

void pHaveTip(Actor *player) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printSpace(5);
    printf("Decide your owned tip (1 ~ 2147483647): %d\n", player->tip);
    printSpace(5);
    printScreen3rdSection();
    printScreenTopBottom();
}

void pShuffling(Actor *player) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenMidSection("Shuffling the deck...");
    printScreen3rdSection();
    printScreenTopBottom();
}

// > in game

void pBet(Actor *player, int *bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenBet(player, bet);
    printScreen3rdSection();
    printScreenTopBottom();
}

void pBetedBet(Actor *player, int *bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printf("bet: %d\n", *bet);
    printSpace(4);
    printf("How much would you bet? (1 ~ %d): %d\n", player->tip, *bet);
    printSpace(5);
    printScreen3rdSection();
    printScreenTopBottom();
}

void pDrawingCard(Actor *player, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenMidSectionWithBet("Drawing card...", bet);
    printScreen3rdSection();
    printScreenTopBottom();
}

void pFirstDraw(Actor *player, Actor *dealer, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenMidSectionWithBet("Drawing card...", bet);
    printScreen3rdSection();
    printScreenTopBottom();
}

void pFirstDrawResult(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printScreen3rdSection();
    printScreenTopBottom();
}

void pPlayerTurn(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Player's turn...\n");
    printSpace(1);
    printf("Hit or Stand? (h/s): ");
    scanf(" %c", &player->action);
    printSpace(1);
    printScreenTopBottom();
}

void pPlayerHiting(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    player->count++;
    player->cards[player->count] = 52;
    
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Player's turn... Drawing card...\n");
    printSpace(1);
    printf("Hit or Stand? (h/s): h -> Hit!\n");
    printSpace(1);
    printScreenTopBottom();
    
    player->count--;
}

void pPlayerHitResult(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Player's turn...\n");
    printSpace(3);
    printScreenTopBottom();
}

void pPlayerBusts(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(2);
    printf("Player busts!\n");
    printSpace(2);
    printScreenTopBottom();
}

void pPlayerStand(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Player's turn...\n");
    printSpace(1);
    printf("Hit or Stand? (h/s): s -> Stand!\n");
    printSpace(1);
    printScreenTopBottom();
}

void pDealerTurn(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Dealer's turn...\n");
    printSpace(3);
    printScreenTopBottom();
}

void pDealerDrawingCard(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    dealer->count++;
    dealer->cards[dealer->count] = 52;
    
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Dealer's turn... Drawing card...\n");
    printSpace(1);
    printScreenTopBottom();
    
    dealer->count--;
}

void pDealerHitResult(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Dealer's turn...\n");
    printSpace(1);
    printf("Dranwd\n");
    printSpace(1);
    printScreenTopBottom();
}

void pDealerBusts(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(2);
    printf("Dealer busts!\n");
    printSpace(2);
    printScreenTopBottom();
}

void pWinOrLose(char showCard[N][3], Actor *player, Actor *dealer, int bet, char judge[6]) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("You %s!\n", judge);
    printSpace(3);
    printScreenTopBottom();
}

void pPlayAgain(char showCard[N][3], Actor *player, Actor *dealer, int bet, char *wantToPlayAgain) {
    printScreenTopBottom();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Play again? (y/n):");
    scanf(" %c", wantToPlayAgain);
    printSpace(3);
    printScreenTopBottom();
}

void pGameResult(Actor *player) {
    player->finalScore = (player->maxTip / player->firstTip) * 30 + (player->tip / player->firstTip) * 50;

    printScreenTopBottom();
    printScreenHaveTip(player);
    printSpace(2);
    printf("Your first tip is %d\n", player->firstTip);
    printSpace(1);
    printf("Your max tip is %d\n", player->maxTip);
    printSpace(1);
    printf("Your final tip is %d\n", player->tip);
    printSpace(2);
    printf("----------------------------------------\n");
    printSpace(2);
    printf("Score: %d\n", player->finalScore);
    printSpace(2);
    printScreenTopBottom();
}

void pEndGame(Actor *player) {
    printScreenTopBottom();
    printSpace(1);
    printf("Tip: First: %d, Max: %d, Final: %d\n", player->firstTip, player->maxTip, player->tip);
    printf("----------------------------------------\n");
    printSpace(4);
    printf("****************************************\n");
    printf("******** Thank you for playing! ********\n");
    printf("****************************************\n");
    printSpace(4);
    printf("----------------------------------------\n");
    printSpace(2);
    printf("Score: %d\n", player->finalScore);
    printSpace(2);
    printScreenTopBottom();
}
    