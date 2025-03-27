#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int populateArrayFromFile(FILE* ifstream, int* arrayNumbers);
void reverseArray(int* arrayNumbers, int arraySize);
void printIntegerArray(int *arrayNumbers, int arraySize);
int removeWhiteSpace(char* characters, int arraySize);
void printCharacterArray(char* characters, int arraySize, int whiteSpaceRemoved);
void populateArrayFromRandoms(int* randoms);
void countNumbersGenerated(int* randoms, int *counts);
char guessLetter(void);
int checkGuess(char* word, char* guessed, char guess);
void printWord(char* word);
void displayGuessed(char* guessed);
int checkIfWordFound(char* word, char* guessed);