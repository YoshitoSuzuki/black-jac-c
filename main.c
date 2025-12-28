#include "header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void) {

    int deck[N];
    initializeDeck(deck);

    int scoreDeck[N];
    initializeScoreDeck(scoreDeck);

    char showCard[N][3];
    initializeShowCard(showCard);

    Actor dealer;
    Actor player;

    dealer.role = DEALER;
    player.role = PLAYER;


    initializeActor(&dealer);
    initializeActor(&player);

    sleep(waitTime);

    printf("\n");
    printf("****************************************\n");
    printf("******** Welcome to Black Jack! ********\n");
    printf("****************************************\n");
    printf("\n");

    sleep(waitTime);

    printf("Decide your owned tip (1 ~ 2147483647): ");

    while (1) {
        int res = scanf(" %d", &player.tip);
        printf("\n");

        if (res && player.tip >= 1 && player.tip <= 2147483647) {
            break;
        }

        printf("Please enter a available number.\n");
        while (getchar() != '\n');
        sleep(waitTime);
        printf("Decide your owned tip (1 ~ 2147483647): ");
    }

    player.firstTip = player.tip;
    player.maxTip = player.tip;

    sleep(waitTime);
    
    printf("----------------------------------------\n");
    printf("You have %d tip\n", player.tip);
    printf("----------------------------------------\n");

    printf("\n");
    sleep(waitTime);
    
    printf("Shuffling the deck...\n");
    sleep(waitTime);

    for (int i=0; i<3; i++) {
        printf("\n");
    }

    while (1) {

        printf("========================================\n");
        printf("========================================\n");
        printf("\n");

        int bet;

        printf("How much would you bet? (1 ~ %d): ", player.tip);

        while (1) {
            int res = scanf(" %d", &bet);
            printf("\n");
            if (res && bet >= 1 && bet <= player.tip) {
                break;
            }
            printf("Please enter a available number.\n");
            while (getchar() != '\n');
            sleep(waitTime);
            printf("How much would you bet? (1 ~ %d): ", player.tip);
        }

        sleep(waitTime);
        printf("----------------------------------------\n");
        printf("\n");
        sleep(waitTime);

        if (bet > player.tip) {
            printf("You don't have enough tip.\n");
            printf("\n");
            sleep(waitTime);
            continue;
        }

        char turn = 'p';
        
        // first draw
        drawCard(deck, scoreDeck, &dealer);
        drawCard(deck, scoreDeck, &player);

        printActor(showCard, &dealer);
        printf("\n");

        sleep(waitTime);
        
        dealer.isBust = drawCard(deck, scoreDeck, &dealer);
        player.isBust = drawCard(deck, scoreDeck, &player);

        printActor(showCard, &player);
        printf("\n");

        if (player.score[0]==21 || player.score[1]==21 || player.score[2]==21 || player.score[3] == 21) {
            sleep(waitTime);
            printf("----------------------------------------\n");
            printf("\n");
            printf("Blackjack! ");
            printf("\n");
            sleep(waitTime);
            turn = 'n';
        }

        if (turn == 'p') {
            sleep(waitTime);

            printf("----------------------------------------\n");
            printf("\n");
            printf("Player's turn\n");
            printf("\n");

            sleep(waitTime);
        }

        while (turn == 'p') {
            printf("Hits or Stand? (h/s): ");

            char input;

            while (1) {
                scanf(" %c", &input);
                printf("\n");
                if (input == 'h' || input == 's') {
                    break;
                }
                printf("Please enter a available character.\n");
                while (getchar() != '\n');
                sleep(waitTime);
                printf("Hits or Stand? (h/s): ");
            }
            
            sleep(waitTime);

            if (input == 'h' && player.isBust == 0) {
                player.isBust = drawCard(deck, scoreDeck, &player);
                printActor(showCard, &player);
                printf("\n");
                if (player.isBust) {
                    sleep(waitTime);
                    printf("Player busts! Dealer wins!\n");
                    printf("\n");
                    break;
                }
            } else if (input == 's') {
                turn = 'd';
            }
        }

        if (turn == 'd') {
            sleep(waitTime);
            printf("----------------------------------------\n");
            printf("\n");
            printf("Dealer's turn\n");
            printf("\n");

            sleep(waitTime);
            printActor(showCard, &dealer);
            printf("\n");
        }

        while (turn == 'd' && dealer.score[0] < 17 && dealer.score[1] < 17 && dealer.score[2] < 17 && dealer.score[3] < 17) {
            sleep(waitTime);
            dealer.isBust = drawCard(deck, scoreDeck, &dealer);
            printActor(showCard, &dealer);
            printf("\n");
            if (dealer.isBust) {
                printf("Dealer busts! Player wins!\n");
                printf("\n");
                break;
            }
        }

        if (turn != 'n') {
            sleep(waitTime);
            printf("----------------------------------------\n");
            printf("\n");
        }

        overWriteScore(&dealer);
        overWriteScore(&player);


        if (dealer.isBust) {
            printHaveTip(&player, bet, 1);
        } else if (player.isBust) {
            printHaveTip(&player, bet, 0);
        }else if (dealer.score[3] > player.score[3] && dealer.isBust == 0) {
            printHaveTip(&player, bet, 0);
        } else if (dealer.score[3] < player.score[3] && player.isBust == 0) {
            printHaveTip(&player, bet, 1);
        } else if (dealer.score[3] == player.score[3] && dealer.isBust == 0) {
            printHaveTip(&player, bet, 2);
        }

        if (player.tip > player.maxTip) {
            player.maxTip = player.tip;
        }

        sleep(waitTime);

        if (player.tip <= 0) {
            printf("You don't have enough tip. Game over.\n");
            printf("\n");
            sleep(waitTime);
            break;
        }

        int wantToPlay;

        while (1) {
            char input;
            printf("Play again? (y/n): ");
            scanf(" %c", &input);
            printf("\n");
            if (input == 'y') {
                wantToPlay = 1;
                break;
            } else if (input == 'n') {
                wantToPlay = 0;
                break;
            }
        }

        if (!wantToPlay) {
            break;
        }

        for (int i=0; i<20; i++) {
            printf("\n");
        }

        initializeDeck(deck);
        initializeScoreDeck(scoreDeck);
        initializeShowCard(showCard);
        initializeActor(&dealer);
        initializeActor(&player);

        sleep(waitTime);
    }

    sleep(waitTime);
    printf("========================================\n");
    printf("\n");
    sleep(waitTime);
    printf("Your tip is %d\n", player.tip);
    printf("\n");
    sleep(waitTime);
    printf("Your first tip is %d\n", player.firstTip);
    printf("\n");
    sleep(waitTime);
    printf("Your max tip is %d\n", player.maxTip);
    printf("\n");
    sleep(waitTime);
    printf("========================================\n");
    printf("\n");
    sleep(waitTime);

    printf("\n");
    printf("\n");
    printf("****************************************\n");
    printf("******** Thank you for playing! ********\n");
    printf("****************************************\n");
    printf("\n");
    printf("\n");
    printf("\n");

    return 0;
}