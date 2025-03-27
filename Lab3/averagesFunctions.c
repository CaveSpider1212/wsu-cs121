/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 3 - Problem 3
* Created: 9/11/24
* Description: This file contains all of the function definitions of this problem.
*/

// prompts the user for a score, then returns the score

#include "averagesFunctions.h"

double inputScores(void) {
	double score = 0.0;
	scanf("%lf", &score);
	return score;
}

// calculates the average using 2 scores
double calculateAvg(double score1, double score2) {
	double average = (score1 + score2) / 2;
	return average;
}

// calculates the weighted average using the exam, lab, and project averages
double calculateWeightedAvg(double examAvg, double labAvg, double projectAvg) {
	double weightedAvg = (examAvg * 0.6) + (labAvg * 0.1) + (projectAvg * 0.3);
}

// displays the weighted average to the screen
void displayAvg(double weightedAvg) {
	printf("Weighted Average: %.2f%%/100%%\n", weightedAvg);
}