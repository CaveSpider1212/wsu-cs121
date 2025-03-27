/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 4
* Created: 9/18/2024
* Description:
*/

#include "Header.h"

int main() {
	// TASK 1
	printf("TASK 1 - Calories (check output.txt)\n\n");

	FILE* caloriesInputFile = NULL;
	FILE* caloriesOutputFile = NULL;

	double weight = 0.0, height = 0.0;
	int age = 0;
	char gender = "\0", activity = "\0";

	double bmr = 0.0, calories = 0.0;

	caloriesInputFile = fopen("calorieInputs.txt", "r");
	caloriesOutputFile = fopen("calorieOutputs.txt", "a");

	age = readInteger(caloriesInputFile);
	gender = readCharacter(caloriesInputFile);
	weight = readDouble(caloriesInputFile);
	height = readDouble(caloriesInputFile);
	activity = readCharacter(caloriesInputFile);

	bmr = calcBMR(weight, height, age, gender);
	calories = calcCalories(bmr, activity);

	printDouble(caloriesOutputFile, calories);
	
	fclose(caloriesInputFile);
	fclose(caloriesOutputFile);

	printf("------------------------------------------------------------------------------------\n");


	// TASK 2
	printf("TASK 2 - Baseball Player Bonus\n\n");

	char allStar = "\0", regSeason = "\0", worldSeries = "\0", goldGlove = "\0", silverSlugger = "\0", homeRun = "\0", battingAvg = "\0";
	int bonus = 0;

	printf("Did the player appear in an All-Star Game?: ");
	scanf(" %c", &allStar);

	printf("Did the player win Regular Season MVP?: ");
	scanf(" %c", &regSeason);

	printf("Did the player win World Series MVP?: ");
	scanf(" %c", &worldSeries);

	printf("Did the player win the Gold Glove award?: ");
	scanf(" %c", &goldGlove);

	printf("Did the player win the Silver Slugger award?: ");
	scanf(" %c", &silverSlugger);

	printf("Was the player the home run champion?: ");
	scanf(" %c", &homeRun);

	printf("Was the player the batting average champion?: ");
	scanf(" %c", &battingAvg);

	bonus = calcBonus(allStar, regSeason, worldSeries, goldGlove, silverSlugger, homeRun, battingAvg);
	displayBonus(bonus);

	printf("------------------------------------------------------------------------------------\n");


	// TASK 3
	printf("TASK 3 - Numbers\n\n");

	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
	int operation = 0;

	FILE* numbersInputFile = NULL;

	numbersInputFile = fopen("numberInputs.txt", "r");

	num1 = readInteger(numbersInputFile);
	num2 = readInteger(numbersInputFile);
	num3 = readInteger(numbersInputFile);
	num4 = readInteger(numbersInputFile);
	num5 = readInteger(numbersInputFile);

	printf("Which operation do you want to do? Type the number.\n1. Average\n2. High value\n3. Low value\n");
	scanf("%d", &operation);

	displayResult(operation, num1, num2, num3, num4, num5);

	return 0;
}