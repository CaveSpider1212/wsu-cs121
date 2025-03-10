#pragma once

/*
* Programmer: Aabhwan Adhikary
* Created: 11/13/2024
* Assignment: PA7
* Class: CptS 121, Fall 2024; Lab Section 19
* Description: This file contains the structures, function prototypes, and preprocessor directives of the program.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {
	int faceValIndex;
	int suitIndex;
} Card;

typedef struct hand {
	Card cards[5];
} Hand;

void printGameMenu(char *play);
void askToContinue(char *play);
void askToReplaceCards(int replace[5]);
void resetDeckArray(int wDeck[4][13]);
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int *currentCard, Hand *h, int replace[5]);
void printHand(Hand* h, const char* wFace[], const char* wSuit[]);
int numberOfAKind(Hand* h, int number, int checkingValue);
void sortFaceValues(int sortedValues[5], Hand *h);
int containsPair(Hand *h);
int containsTwoPairs(Hand *h);
int containsThreeOfAKind(Hand *h);
int containsFourOfAKind(Hand *h);
int containsFullHouse(Hand *h);
int containsFlush(Hand *h);
int containsStraight(Hand *h);
void displayAvailableHands(Hand* h);
void evaluateHands(Hand* h1, Hand* h2, int *p1Score, int *p2Score);
int findHighCard(Hand* h);
void simulateDealer(Hand* h, int replace[5]);
int countSuits(Hand* h, int *mostCommonSuitIndex);
void findThreeLowest(Hand* h, int replace[5]);