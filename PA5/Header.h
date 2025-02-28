#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: PA 5
* Created: 10/11/24
* Description: This file contains all of the function headers and preprocessor directives of the program.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gameMenu(void);
void printGameRules(void);
void startGame(void);
int rollDie(void);
void switchPlayer(int* player);
void displayScores(int p1Score, int p2Score);
void displayUpperScores(int p1Upper, int p2Upper);
void displayCombinations(int values[], int playerNum, int *p1Available[], int *p2Available[]);
int calculateScore(int values[], int combNumber, int playerNum, char calculateUpper, int *p1Upper, int *p2Upper);
void addUpperScore(char calculateUpper, int playerNum, int score, int* p1Upper, int* p2Upper);
int sumDiceValues(int values[]);
int numberOfAKind(int number, int values[], int *currentValue);
void findUniques(int* values, int* uniqueValues);
void sortArray(int* arr);
int checkStraight(int* arr, char combination);
int countZeroes(int *arr, int size);
void selectCombination(int values[], int *p1Availability, int *p2Availability, int playerNum, int *p1Score, int *p2Score, int *p1Upper, int *p2Upper);
int verifyCombinationAvailability(int* p1Availability, int *p2Availability, int number, int playerNum);
void checkForAvailableCombinations(int array[], int values[]);
void giveBonus(int* p1Upper, int* p2Upper, int *p1Score, int *p2Score);
void displayWinner(int p1Score, int p2Score);