#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: PA 4
* Created: 9/27/2024
* Description: This file contains all of the function prototypes and preprocessor directives for the program.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printGameRules(void);
double getBankBalance(void);
double getWagerAmount(void);
int checkWagerAmount(double wager, double balance);
int rollDie(void);
int calculateSumDice(int die1Value, int die2Value);
int isWinLossOrPoint(int sumDice);
int isPointLossOrNeither(int sumDice, int pointValue);
double adjustBankBalance(double bankBalance, double wagerAmount, int addOrSubtract);
void chatterMessages(int numberRolls, int winLossNeither, double initialBankBalance, double currentBankBalance);
char checkPlaying(double bal); // extra function