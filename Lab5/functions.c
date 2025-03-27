/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 5
* Date: 9/25/24
*/

#include "Header.h"

int readInteger(FILE* infile) {
	int num = 0;
	fscanf(infile, "%d\n", &num);
	return num;
}

double readDouble(FILE* infile) {
	double num = 0.0;
	fscanf(infile, "%lf\n", &num);
	return num;
}

void printInteger(FILE* outfile, int num) {
	fprintf(outfile, "%d\n", num);
}

void printDouble(FILE* outfile, double num) {
	fprintf(outfile, "%lf\n", num);
}

int greatestCommonDivisor(int num1, int num2) {
	int remainder = 0;
	int lastRemainder = 0;

	do {
		remainder = abs(num1) % abs(num2);
		num1 = num2;
		num2 = remainder;

		if (remainder != 0) {
			lastRemainder = remainder;
		}
	} while (remainder > 0);

	return lastRemainder;
}

int determineGreater(int num1, int num2) {
	int greater = 0;

	if (num1 > num2) {
		greater = num1;
	}
	else {
		greater = num2;
	}

	return greater;
}

int determineLesser(int num1, int num2) {
	int lesser = 0;

	if (num1 < num2) {
		lesser = num1;
	}
	else {
		lesser = num2;
	}

	return lesser;
}