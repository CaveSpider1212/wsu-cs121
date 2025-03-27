/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Programming Assignment: Lab 3
* Created: 9/11/2024
* Description:
*/

#define _CRT_SECURE_NO_WARNINGS

#include "projectileFunctions.h"
#include "averagesFunctions.h"

#include <stdio.h>
#include <math.h>

// prompts the user for weight in pounds, then returns the weight
double get_weight(void) {
	double weight = 0.0;
	
	printf("Please input the weight in pounds:\n");
	scanf("%lf", &weight);

	return weight;
}

// prompts the user for height in feet, then return the height
double get_height(void) {
	double height = 0.0;

	printf("Please input the height in feet:\n");
	scanf("%lf", &height);

	return height;
}

// converts the height of the user from feet to inches
double convert_feet_to_inches(double height_in_feet) {
	double height_in_inches = height_in_feet * 12;
	return height_in_inches;
}

// evaluates the BMI based on the weight in pounds and height in inches, and returns the BMI
double calculate_bmi(double weight_in_pounds, double height_in_feet) {
	double bmi = (weight_in_pounds / pow(convert_feet_to_inches(height_in_feet), 2)) * 703;
	return bmi;
}

// display the resultant BMI to the tenths place
void display_bmi(double bmi) {
	printf("BMI: %.1f\n", bmi);
}

int main() {
	printf("PART 1 - BMI\n\n");

	double weight = 0.0, height1 = 0.0, bmi = 0.0;

	weight = get_weight();
	height1 = get_height();
	bmi = calculate_bmi(weight, height1);
	display_bmi(bmi);

	printf("-------------------------------------------------------------------------------------\n");



	printf("PART 2 - Projectile\n\n");

	double distance = 0.0, velocity = 0.0, theta = 0.0, time = 0.0, height2 = 0.0;

	distance = getDistance();
	velocity = getVelocity();
	theta = getTheta();

	time = calculateTime(distance, velocity, theta);
	height2 = calculateHeight(velocity, theta, time);

	displayResults(time, height2);

	printf("-------------------------------------------------------------------------------------\n");



	printf("PART 3 - Exam Scores\n\n");

	double exam1 = 0.0, exam2 = 0.0, lab1 = 0.0, lab2 = 0.0, project1 = 0.0, project2 = 0.0, examAvg = 0.0, labAvg = 0.0, projectAvg = 0.0, weightedAvg = 0.0;

	printf("Please input the Exam 1 score:\n");
	exam1 = inputScores();

	printf("Please input the Exam 2 score:\n");
	exam2 = inputScores();

	printf("Please input the Lab 1 score:\n");
	lab1 = inputScores();

	printf("Please input the Lab 2 score:\n");
	lab2 = inputScores();

	printf("Please input the Project 1 score: \n");
	project1 = inputScores();

	printf("Please input the Project 2 score:\n");
	project2 = inputScores();

	examAvg = calculateAvg(exam1, exam2);
	labAvg = calculateAvg(lab1, lab2);
	projectAvg = calculateAvg(project1, project2);

	weightedAvg = calculateWeightedAvg(examAvg, labAvg, projectAvg);
	displayAvg(weightedAvg);

	return 0;
}