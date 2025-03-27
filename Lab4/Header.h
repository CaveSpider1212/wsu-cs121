#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 4
* Created: 9/18/2024
* Description: This file contains all of the function prototypes and preprocessor directives of the program.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// TASK 1
double readDouble(FILE* inputFile);
double readInteger(FILE* inputFile); // used for Task 3
char readCharacter(FILE* inputFile);
double calcBMR(double weight, double height, int age, int gender);
double calcCalories(double bmr, char activity);
void printDouble(FILE* outputFile, double calories);

// TASK 2
int calcBonus(char allStar, char regSeason, char worldSeries, char goldGlove, char silverSlugger, char homeRun, char battingAvg);
void displayBonus(int bonus);

// TASK 3
double calcAvg(int num1, int num2, int num3, int num4, int num5);
int findHigh(int num1, int num2, int num3, int num4, int num5);
int findLow(int num1, int num2, int num3, int num4, int num5);
void displayResult(int operation, int num1, int num2, int num3, int num4, int num5);