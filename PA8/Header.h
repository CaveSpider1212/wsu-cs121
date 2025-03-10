#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Created: 11/24/2024
* Assignment: PA 8
* Description: This file contains all of the preprocessor directives, function prototypes, and structures of the program.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct occurrences {
	int numOccurences;
	double frequency;
} Occurrences;

char* my_str_n_cat(char* destination, char* source, int n);
int binary_search(int* sorted, int n, int target);
void bubble_sort(char* strPointers[], int n);
int is_palindrome(char* str, int len);
int sum_primes(int n);
int isPrime(int num, int divisor);
void maximum_occurences(char* str, Occurrences arr[], int* maxOccurrences, char* character);
void max_consecutive_integers(int **arr, int rows, int columns, int** address, int* number);