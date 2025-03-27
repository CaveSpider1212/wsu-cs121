#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char* reverseString(char word[], int i);
int sumDigits(int num);
void determinePath(char array[8][8], int been[100][2], int* row, int* col, int *i);
void printPath(int been[100][2]);