#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab
* Programming Assignment: PA3
* Created: 9/16/2024
* Description: This file contains all of the preprocessor directives and function prototypes of the program.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double readDouble(FILE* infile);
int readInteger(FILE* infile);
double calculateSum(double number1, double number2, double number3, double number4, double number5);
double calculateMean(double sum, int number);
double calculateDeviation(double number, double mean);
double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculateStandardDeviation(double variance);
double findMax(double number1, double number2, double number3, double number4, double number5);
double findMin(double number1, double number2, double number3, double number4, double number5);
void printDouble(FILE* outfile, double number);