/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Programming Assignment: Lab 2
* Created: 9/24/2024
* Description:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	printf("TASK 1\n\n\n");

	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	printf("Please enter the x- and y-coordinates of the first point, as integer values and on separate lines:\n");
	scanf("%d%d", &x1, &y1);

	printf("Please enter the x- and y-coordinates of the second point, as integer values and on separate lines:\n");
	scanf("%d%d", &x2, &y2);

	int slope_Line = (y2 - y1) / (x2 - x1);
	int midpoint_Y = (y2 + y1) / 2;
	int midpoint_X = (x2 + x1) / 2;
	int slope_PB = -1 / slope_Line;
	int y_intercept_PB = midpoint_Y - (slope_PB * midpoint_X);

	printf("\nPerpendicular bisector equation of the points (%d, %d) and (%d, %d):\n", x1, y1, x2, y2);
	printf("y = mx + b --> y = %dx + %d\n", slope_PB, y_intercept_PB);

	printf("---------------------------------------------------------------------------------------------\n");

	printf("TASK 2\n\n\n");

	float weight = 0.0, height = 0.0;

	printf("Please input the weight (in pounds) and height (in feet) values below, as floating-point values and on separate lines:\n");
	scanf("%f%f", &weight, &height);

	float heightInches = height * 12;
	float bmi = ((weight) / (heightInches * heightInches)) * 703;

	printf("\nBMI with a weight of %.1f pounds and a height of %.1f feet: %f\n", weight, height, bmi);

	return 0;
}