/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 5
* Date: 9/25/24
*/

#include "Header.h"

int main(void) {
	// PART 1
	printf("PART 1 - INCOME\n\n");

	FILE* salaryFile = NULL;
	int salarySum = 0;
	char income = '\0';

	salaryFile = fopen("salaries.txt", "r");

	while (!feof(salaryFile)) {
		salarySum += readInteger(salaryFile);
	}

	if (salarySum < 15000) {
		income = 'l';
	}
	else if (salarySum >= 15000 && salarySum <= 200000) {
		income = 'm';
	}
	else {
		income = 'h';
	}

	fclose(salaryFile);
	printf("%c\n", income);
	
	printf("-----------------------------------------------------------------------------------------------------\n");

	// PART 2
	printf("PART 2 - AVERAGE\n\n");

	FILE* dataFile = NULL;
	FILE* outputFile = NULL;

	dataFile = fopen("data.txt", "r");
	outputFile = fopen("output.txt", "a");

	double sum = 0.0, average = 0.0;
	int count = 0;

	while (!feof(dataFile)) {
		sum += readDouble(dataFile);
		count++;
	}

	average = sum / count;
	printDouble(outputFile, average);
	printf("Check \"output.txt\"\n");

	fclose(dataFile);
	fclose(outputFile);

	printf("-----------------------------------------------------------------------------------------------------\n");

	// PART 3
	printf("PART 3 - GREATEST COMMON DIVISOR\n\n");

	FILE* gcdInputs = NULL;
	FILE* gcdOutputs = NULL;

	gcdInputs = fopen("gcdInputs.txt", "r");
	gcdOutputs = fopen("gcdOutputs.txt", "a");

	int gcd = 0, number1 = 0, number2 = 0;

	number1 = readInteger(gcdInputs);
	number2 = readInteger(gcdInputs);

	gcd = greatestCommonDivisor(number1, number2);
	printInteger(gcdOutputs, gcd);
	printf("Check \"gcdOutputs.txt\"\n");

	fclose(gcdInputs);
	fclose(gcdOutputs);

	printf("-----------------------------------------------------------------------------------------------------\n");

	// PART 4
	printf("PART 4 - HIGHEST AND LOWEST NUMBERS\n\n");

	FILE* minMaxInputs = NULL;

	minMaxInputs = fopen("minMaxInputs.txt", "r");
	int max = 0, min = 0, num = 0;

	while (!feof(minMaxInputs)) {
		num = readInteger(minMaxInputs);
		max = determineGreater(num, max);
		min = determineLesser(num, min);
	}

	printf("Highest: %d\n", max);
	printf("Lowest: %d\n", min);

	fclose(gcdInputs);
	fclose(gcdOutputs);
	
	return 0;
}