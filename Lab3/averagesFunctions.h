#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 3 - Problem 3
* Created: 9/11/2024
* Description: This function contains all of the function prototypes and preprocessor directives of the program.
*/

double inputScores(void);
double calculateAvg(double score1, double score2);
double calculateWeightedAvg(double examAvg, double labAvg, double projectAvg);
void displayAvg(double weightedAvg);