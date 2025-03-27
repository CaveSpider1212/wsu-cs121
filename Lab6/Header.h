// Lab 6 - 10/2/24

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int readInteger(FILE* infile);
int sumDigits(int num);
void checkPrime(int originalNum, int digitSum);
int findFactorial(int num);
void displayFibonacci(int term);
int generateRandomNumber(void);