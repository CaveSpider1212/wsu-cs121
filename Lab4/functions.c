/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 4
* Created: 9/18/2024
* Description: This file contains all of the function declarations of the program.
*/

#include "Header.h"

// TASK 1
double readDouble(FILE* inputFile) {
	double num = 0.0;
	fscanf(inputFile, "%lf\n", &num);
	return num;
}

double readInteger(FILE* inputFile) {
	int num = 0;
	fscanf(inputFile, "%d\n", &num);
	return num;
}

char readCharacter(FILE* inputFile) {
	char letter = "\0";
	fscanf(inputFile, "%c\n", &letter);
	return letter;
}

double calcBMR(double weight, double height, int age, char gender) {
	double bmr = 0.0;
	
	if (gender == 'W') { // women
		bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
	}
	else { // men
		bmr = 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
	}

	return bmr;
}

double calcCalories(double bmr, char activity) {
	double calories = 0.0;
	
	if (activity == 'S') { // sedentary
		calories = bmr * 1.2;
	}
	else if (activity == 'L') { // low activity
		calories = bmr * 1.375;
	}
	else if (activity == 'M') { // moderate activity
		calories = bmr * 1.55;
	}
	else if (activity == 'H') { // high activity
		calories = bmr * 1.725;
	}
	else { // extra activity
		calories = bmr * 1.9;
	}
}

void printDouble(FILE* outputFile, double calories) {
	fprintf(outputFile, "%.2f\n", calories);
}


// TASK 2
int calcBonus(char allStar, char regSeason, char worldSeries, char goldGlove, char silverSlugger, char homeRun, char battingAvg) {
	int bonus = 0;

	if (allStar == 'y') {
		bonus += 25000;
	}
	if (regSeason == 'y') {
		bonus += 75000;
	}
	if (worldSeries == 'y') {
		bonus += 100000;
	}
	if (goldGlove == 'y') {
		bonus += 50000;
	}
	if (silverSlugger == 'y') {
		bonus += 35000;
	}
	if (homeRun == 'y') {
		bonus += 25000;
	}
	if (battingAvg == 'y') {
		bonus += 25000;
	}

	return bonus;
}

void displayBonus(int bonus) {
	printf("The player's bonus is: $%d\n", bonus);
}


// TASK 3
double calcAvg(int num1, int num2, int num3, int num4, int num5) {
	double average = (num1 + num2 + num3 + num4 + num5) / 5;
	return average;
}

int findHigh(int num1, int num2, int num3, int num4, int num5) {
	int high = 0;

	if (num1 >= num2 && num1 >= num3 && num1 >= num4 && num1 >= num5) {
		high = num1;
	}
	else if (num2 >= num1 && num2 >= num3 && num2 >= num4 && num2 >= num5) {
		high = num2;
	}
	else if (num3 >= num1 && num3 >= num2 && num3 >= num4 && num3 >= num5) {
		high = num3;
	}
	else if (num4 >= num1 && num4 >= num2 && num4 >= num3 && num4 >= num5) {
		high = num4;
	}
	else {
		high = num5;
	}

	return high;
}

int findLow(int num1, int num2, int num3, int num4, int num5) {
	int low = 0;

	if (num1 <= num2 && num1 <= num3 && num1 <= num4 && num1 <= num5) {
		low = num1;
	}
	else if (num2 <= num1 && num2 <= num3 && num2 <= num4 && num2 <= num5) {
		low = num2;
	}
	else if (num3 <= num1 && num3 <= num2 && num3 <= num4 && num3 <= num5) {
		low = num3;
	}
	else if (num4 <= num1 && num4 <= num2 && num4 <= num3 && num4 <= num5) {
		low = num4;
	}
	else {
		low = num5;
	}

	return low;
}

void displayResult(int operation, int num1, int num2, int num3, int num4, int num5) {
	if (operation == 1) {
		printf("The average is: %.2f\n", calcAvg(num1, num2, num3, num4, num5));
	}
	if (operation == 2) {
		printf("The high value is: %d\n", findHigh(num1, num2, num3, num4, num5));
	}
	if (operation == 3) {
		printf("The low value is: %d\n", findLow(num1, num2, num3, num4, num5));
	}
}