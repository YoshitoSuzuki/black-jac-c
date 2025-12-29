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


    // start game
    sleep(waitTime);

    pWelcome();

    sleep(waitTime);

    pDecideOwnedTip(&player);

    // while (1) {
    //     int res = scanf(" %d", &player.tip);
    //     printf("\n");

    //     if (res && player.tip >= 1 && player.tip <= 2147483647) {
    //         break;
    //     }

    //     printf("Please enter a available number.\n");
    //     while (getchar() != '\n');
    //     sleep(waitTime);
    //     printf("Decide your owned tip (1 ~ 2147483647): ");
    // }

    player.firstTip = player.tip;
    player.maxTip = player.tip;

    sleep(waitTime);
    
    pHaveTip(&player);

    sleep(waitTime);
    
    pShuffling(&player);

    // in game
    while (1) {

        int bet;

        pBet(&player, &bet);

        // while (1) {
        //     int res = scanf(" %d", &bet);
        //     printf("\n");
        //     if (res && bet >= 1 && bet <= player.tip) {
        //         break;
        //     }
        //     printf("Please enter a available number.\n");
        //     while (getchar() != '\n');
        //     sleep(waitTime);
        //     printf("How much would you bet? (1 ~ %d): ", player.tip);
        // }


        sleep(waitTime);

        if (bet > player.tip) {
            pBetError(&player, bet);
            sleep(waitTime);
            continue;
        }

        pBetedBet(&player, &bet);


        char turn = 'p';
        
        sleep(waitTime);
        
        pDrawingCards(&player, bet);

        // first draw
        drawCard(deck, scoreDeck, &dealer);
        drawCard(deck, scoreDeck, &player);
        dealer.isBust = drawCard(deck, scoreDeck, &dealer);
        player.isBust = drawCard(deck, scoreDeck, &player);

        pFirstDrawResult(showCard, &player, &dealer, bet);

        if (player.score[0]==21 || player.score[1]==21 || player.score[2]==21 || player.score[3] == 21) {
            sleep(waitTime);
            pBlackjack(showCard, &player, &dealer, bet);
            sleep(waitTime);
            turn = 'n';
        }


        // player's turn
        while (turn == 'p') {
            sleep(waitTime);
            pPlayerTurn(showCard, &player, &dealer, bet);

            char input = player.action;

            // while (1) {
            //     scanf(" %c", &input);
            //     printf("\n");
            //     if (input == 'h' || input == 's') {
            //         break;
            //     }
            //     printf("Please enter a available character.\n");
            //     while (getchar() != '\n');
            //     sleep(waitTime);
            //     printf("Hits or Stand? (h/s): ");
            // }
            
            sleep(waitTime);

            if (input =='s') {
                turn = 'd';
            }
            // if (input == 'h' && player.isBust == 0) {
            //     player.isBust = drawCard(deck, scoreDeck, &player);
            //     printActor(showCard, &player);
            //     printf("\n");
            //     if (player.isBust) {
            //         sleep(waitTime);
            //         printf("Player busts! Dealer wins!\n");
            //         printf("\n");
            //         break;
            //     }
            // } else if (input == 's') {
            //     turn = 'd';
            // }
        }


        // dealer's turn
        if (turn == 'd') {
            sleep(waitTime);
            pDealerTurn(showCard, &player, &dealer, bet);
        }

        while (turn == 'd' && dealer.score[0] < 17 && dealer.score[1] < 17 && dealer.score[2] < 17 && dealer.score[3] < 17) {
            sleep(waitTime);
            pDealerDrawingCard(showCard, &player, &dealer, bet);
            dealer.isBust = drawCard(deck, scoreDeck, &dealer);
            sleep(waitTime);
            pDealerHitResult(showCard, &player, &dealer, bet);
            if (dealer.isBust) {
                sleep(waitTime);
                pDealerBusts(showCard, &player, &dealer, bet);
                break;
            }
        }


        if (turn != 'n') {
            sleep(waitTime);
        }

        
        overWriteScore(&dealer);
        overWriteScore(&player);


        // result
        pJudge(showCard, &player, &dealer, bet);
        // if (dealer.isBust) {
        //     printHaveTip(&player, bet, 1);
        // } else if (player.isBust) {
        //     printHaveTip(&player, bet, 0);
        // }else if (dealer.score[3] > player.score[3] && dealer.isBust == 0) {
        //     printHaveTip(&player, bet, 0);
        // } else if (dealer.score[3] < player.score[3] && player.isBust == 0) {
        //     printHaveTip(&player, bet, 1);
        // } else if (dealer.score[3] == player.score[3] && dealer.isBust == 0) {
        //     printHaveTip(&player, bet, 2);
        // }

        if (player.tip > player.maxTip) {
            player.maxTip = player.tip;
        }

        sleep(waitTime);


        // game over
        if (player.tip <= 0) {
            pGameOver(&player);
            sleep(waitTime);
            break;
        }

        int wantToPlay;

        // play again
        while (1) {
            char wantToPlayAgain;
            pPlayerAgain(showCard, &player, &dealer, bet, &wantToPlayAgain);
            if (wantToPlayAgain == 'y') {
                wantToPlay = 1;
                break;
            } else if (wantToPlayAgain == 'n') {
                wantToPlay = 0;
                break;
            }
        }

        if (!wantToPlay) {
            break;
        }

        initializeDeck(deck);
        initializeScoreDeck(scoreDeck);
        initializeShowCard(showCard);
        initializeActor(&dealer);
        initializeActor(&player);

        sleep(waitTime);

        pShuffling(&player);

        sleep(waitTime);
    }


    // game result
    sleep(waitTime);
    pGameResult(&player);


    // end game
    sleep(waitTime);
    pEndGame(&player);

    return 0;
}