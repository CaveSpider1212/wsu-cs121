#pragma once

// LAB 10 - 10/30/24

#define MAX_SIZE 200
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createSentences(char article, char* noun, char* verb, char* prep, char *sentence[]);
int* generateRandomNumber(void);
int countWordLength(char* word);
void displaySentences(char* sentence);

void inputCoordinates(int* row, int* column);