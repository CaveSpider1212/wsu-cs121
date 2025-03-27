#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 3 - Problem 2
* Created: 9/11/2024
* Description: This function contains all of the function prototypes and preprocessor directives of this problem.
*/

#define _CRT_SECURE_NO_WARNINGS
#define G 32.17

#include <stdio.h>
#include <math.h>

double getDistance(void);
double getVelocity(void);
double getTheta(void);
double calculateTime(double distance, double velocity, double theta);
double calculateHeight(double velocity, double theta, double time);
void displayResults(double time, double height);