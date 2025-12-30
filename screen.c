#include "header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void printSpace(int n) {
    for (int i=0; i<n; i++) {
        printf("\n");
    }
}

void printScreenTop() {
    printSpace(5);
    printf("========================================\n");
    printf("========================================\n");
}

void printScreenBottom() {
    printf("========================================\n");
    printf("========================================\n");
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

void printScreenBet(Actor *player, int *bet) {
    printSpace(5);
    printf("How much would you bet? (1 ~ %d): ", player->tip);
    scanf(" %d", bet);
    printSpace(5);
}

void printScreenFirstDrawDeck(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printf("bet: %d", bet);
    printSpace(2);
    printSpace(1);
    printf("**************** Dealer ****************\n");
    for (int i=0; i<dealer->count; i++) {
        printf("%s ", showCard[dealer->cards[i]]);
    }
    printf("\n");
    printScore(dealer);
    printf("\n");
    printSpace(1);
    printf("**************** Player ****************\n");
    for (int i=0; i<player->count; i++) {
        printf("%s ", showCard[player->cards[i]]);
    }
    printf("\n");
    printScore(player);
    printf("\n");
    printSpace(1);
}

void printScreenWinOrLose(char showCard[N][3], Actor *player, Actor *dealer, int bet, char judge[6]) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("You %s!\n", judge);
    printSpace(3);
    printScreenBottom();
}

// ============================================================================================================================================================
// ============================================================================================================================================================
// ============================================================================================================================================================

void pWelcome() {
    printScreenTop();
    printScreen1stSection();
    printScreenWelcom();
    printScreen3rdSection();
    printScreenBottom();
}

void pDecideOwnedTip(Actor *player) {
    printScreenTop();
    printScreen1stSection();
    printScreenWelcom();
    printScreen3rdSection();
    printScreenBottom();
    printf("Decide your owned tip (1 ~ 2147483647): ");
    scanf("%d", &player->tip);
}

void pHaveTip(Actor *player) {
    printScreenTop();
    printScreenHaveTip(player);
    printSpace(5);
    printf("Decide your owned tip (1 ~ 2147483647): %d\n", player->tip);
    printSpace(5);
    printScreen3rdSection();
    printScreenBottom();
}

void pShuffling(Actor *player) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenMidSection("Shuffling the deck...");
    printScreen3rdSection();
    printScreenBottom();
}

// > in game

void pBet(Actor *player, int *bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreen2ndSection();
    printScreen3rdSection();
    printScreenBottom();
    printf("How much would you bet? (1 ~ %d): ", player->tip);
    scanf(" %d", bet);
}

void pBetError(Actor *player, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printf("bet: %d\n", bet);
    printSpace(4);
    printf("How much would you bet? (1 ~ %d): %d\n", player->tip, bet);
    printSpace(5);
    printf("----------------------------------------\n");
    printSpace(2);
    printf("You don't have enough tip.\n");
    printf("Please enter a available number.\n");
    printSpace(2);
    printScreenBottom();
}

void pBetedBet(Actor *player, int *bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printf("bet: %d\n", *bet);
    printSpace(4);
    printf("How much would you bet? (1 ~ %d): %d\n", player->tip, *bet);
    printSpace(5);
    printScreen3rdSection();
    printScreenBottom();
}

void pDrawingCard(Actor *player, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenMidSectionWithBet("Drawing card...", bet);
    printScreen3rdSection();
    printScreenBottom();
}

void pFirstDraw(Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenMidSectionWithBet("Drawing card...", bet);
    printScreen3rdSection();
    printScreenBottom();
}

void pFirstDrawResult(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printScreen3rdSection();
    printScreenBottom();
}

void pBlackjack(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(2);
    printf("Blackjack!\n");
    printSpace(2);
    printScreen3rdSection();
    printScreenBottom();
}

void pPlayerTurn(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Player's turn...\n");
    printSpace(3);
    printScreenBottom();
    printf("Hit or Stand? (h/s): ");
    scanf(" %c", &player->action);
}

void pPlayerHiting(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    player->cards[player->count] = 52;
    player->count++;
    
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Player's turn... Drawing card...\n");
    printSpace(1);
    printf("Hit or Stand? (h/s): h -> Hit!\n");
    printSpace(1);
    printScreenBottom();
    
    player->count--;
}

void pPlayerHitResult(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Player's turn...\n");
    printSpace(3);
    printScreenBottom();
}

void pPlayerBusts(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(2);
    printf("Player busts!\n");
    printSpace(2);
    printScreenBottom();
}

void pPlayerStand(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Player's turn...\n");
    printSpace(1);
    printf("Hit or Stand? (h/s): s -> Stand!\n");
    printSpace(1);
    printScreenBottom();
}

void pDealerTurn(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Dealer's turn...\n");
    printSpace(3);
    printScreenBottom();
}

void pDealerDrawingCard(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    dealer->cards[dealer->count] = 52;
    dealer->count++;
    
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Dealer's turn... Drawing card...\n");
    printSpace(3);
    printScreenBottom();
    
    dealer->count--;
}

void pDealerHitResult(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("Dealer's turn...\n");
    printSpace(1);
    printf("Dranwd\n");
    printSpace(1);
    printScreenBottom();
}

void pDealerBusts(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(2);
    printf("Dealer busts!\n");
    printSpace(2);
    printScreenBottom();
}

void pJudge(char showCard[N][3], Actor *player, Actor *dealer, int bet) {
    getBestScore(player);
    getBestScore(dealer);

    if (player->bestScore > 21) {
        printScreenWinOrLose(showCard, player, dealer, bet, "lose");
        player->judge = 0;
    } else if (dealer->bestScore > 21) {
        printScreenWinOrLose(showCard, player, dealer, bet, "win");
        player->judge = 1;
    } else if (player->bestScore > dealer->bestScore) {
        printScreenWinOrLose(showCard, player, dealer, bet, "win");
        player->judge = 1;
    } else if (player->bestScore < dealer->bestScore) {
        printScreenWinOrLose(showCard, player, dealer, bet, "lose");
        player->judge = 0;
    } else {
        printScreenWinOrLose(showCard, player, dealer, bet, "draw");
        player->judge = 2;
    }

    sleep(waitTime);
    
    printScreenTop();

    char judgeText[6];

    if (player->judge == 0) {
        strcpy(judgeText, "lose");
        printf("Your tip: %d -> %d (-%d)\n", player->tip, player->tip - bet, bet);
        player->tip -= bet;
    } else if(player->judge == 1) {
        strcpy(judgeText, "win");
        printf("Your tip: %d -> %d (+%d)\n", player->tip, player->tip + bet, bet);
        player->tip += bet;
    } else if(player->judge == 2) {
        strcpy(judgeText, "draw");
        printf("Your tip: %d -> %d (±0)\n", player->tip, player->tip);
    }
    printf("You have %d tip\n", player->tip);
    printf("----------------------------------------\n");
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    printf("You %s!\n", judgeText);
    printSpace(3);
    printScreenBottom();
}

void pPlayAgain(char showCard[N][3], Actor *player, Actor *dealer, int bet, char *wantToPlayAgain) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenFirstDrawDeck(showCard, player, dealer, bet);
    printf("----------------------------------------\n");
    printSpace(1);
    
    char judgeText[6];
    if (player->judge == 0) {
        strcpy(judgeText, "lose");
    } else if(player->judge == 1) {
        strcpy(judgeText, "win");
    } else if(player->judge == 2) {
        strcpy(judgeText, "draw");
    }
    printf("You %s!\n", judgeText);

    printSpace(3);
    printScreenBottom();
    printf("Play again? (y/n):");
    scanf(" %c", wantToPlayAgain);
}

void pGameOver(Actor *player) {
    printScreenTop();
    printScreenHaveTip(player);
    printScreenMidSection("You don't have enough tip. Game Over");
    printScreen3rdSection();
    printScreenBottom();
}

void pGameResult(Actor *player) {
    player->finalScore = (player->maxTip / player->firstTip) * 30 + (player->tip / player->firstTip) * 50;

    printScreenTop();
    printScreenHaveTip(player);
    printSpace(3);
    printf("Your first tip is %d\n", player->firstTip);
    printSpace(1);
    printf("Your max tip is %d\n", player->maxTip);
    printSpace(1);
    printf("Your final tip is %d\n", player->tip);
    printSpace(3);
    printf("----------------------------------------\n");
    printSpace(2);
    printf("Score: %d\n", player->finalScore);
    printSpace(2);
    printScreenBottom();
}

void pEndGame(Actor *player) {
    printScreenTop();
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
    printScreenBottom();
}
    