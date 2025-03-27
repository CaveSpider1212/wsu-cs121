#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 5
* Date: 9/25/24
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int readInteger(FILE* infile);
double readDouble(FILE* infile);
void printInteger(FILE* outfile, int num);
void printDouble(FILE* outfile, double num);
int greatestCommonDivisor(int num1, int num2);
int determineGreater(int num, int num2);
int determineLesser(int num1, int num2);