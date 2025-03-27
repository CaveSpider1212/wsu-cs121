/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: Lab 3 - Problem 2
* Created: 9/11/24
* Description: This file contains all of the function definitions of this problem.
*/

#include "projectileFunctions.h"

// prompts the user for distance in feet, then returns the distance
double getDistance(void) {
	double distance = 0.0;

	printf("Please enter the distance in feet:\n");
	scanf("%lf", &distance);

	return distance;
}

// prompts the user for velocity in feet per second, then returns the velocity
double getVelocity(void) {
	double velocity = 0.0;

	printf("Please enter the velocity in feet per second:\n");
	scanf("%lf", &velocity);

	return velocity;
}

// prompts the user for the angle in radians, then returns the angle (theta)
double getTheta(void) {
	double theta = 0.0;

	printf("Please enter the angle (theta) in radians:\n");
	scanf("%lf", &theta);

	return theta;
}

// calculates the time using distance in feet, velocity in feet per second, and the angle (theta) in radians
double calculateTime(double distance, double velocity, double theta) {
	double time = distance / (velocity * cos(theta));
	return time;
}

// calculates the height using velocity in feet per second, theta in radians, and time in seconds
double calculateHeight(double velocity, double theta, double time) {
	double height = (velocity * sin(theta) * time) - ((G * time * time) / 2);
	return height;
}

// displays the time in seconds and height in feet to the screen
void displayResults(double time, double height) {
	printf("Time of flight: %f seconds\n", time);
	printf("Height above the ground: %f feet\n", height);
}