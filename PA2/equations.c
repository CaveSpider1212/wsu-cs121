/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Programming Assignment: PA 2
* Created: 9/7/2024
* Description: This file contains all of the function definitions for the function prototypes in the header file.
*/


#include "equations.h"

/*
* Function name: calculate_newtons_2nd_law()
* Date created: 9/7/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user for mass and acceleration, and returns the product of those values.
* Input parameters: mass, acceleration
* Returns: mass * acceleration
*/
double calculate_newtons_2nd_law(double mass, double acceleration) {
	return mass * acceleration;
}


/*
* Function name: calculate_volume_cylinder()
* Date created: 9/7/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user for radius and height, and returns the product of PI, radius squared, and height.
* Input parameters: radius, height
* Returns: PI * radius * radius * height
*/
double calculate_volume_cylinder(double radius, double height) {
	return PI * radius * radius * height;
}


/*
* Function name: perform_character_encoding()
* Date created: 9/7/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user for a plain text character and an offset value, then returns an encoded character.
* Input parameters: plaintext_character, offset
* Returns: encoded character
*/
char perform_character_encoding(char plaintext_character, int offset) {
	return offset + (plaintext_character - 'a') + 'A';
}


/*
* Function name: calculateGravityForce()
* Date created: 9/7/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user for 2 mass values and a distance, then calculates gravitational force using those values.
* Input parameters: mass1, mass2, distance
* Returns: gravitational force
* Preconditions: distance != 0
*/
double calculateGravityForce(double mass1, double mass2, double distance) {
	return (G * mass1 * mass2) / (distance * distance);
}


/*
* Function name: calculateCelsius()
* Date created: 9/7/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user for a fahrenheit value, then converts it to a celsius value.
* Input parameters: fahrenheit
* Returns: celsius
*/
double calculateCelsius(double fahrenheit) {
	return (fahrenheit - 32) / ((float)9 / (float)5);
}


/*
* Function name: calculateDistance()
* Date created: 9/7/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user for the x and y values of 2 coordinates, then finds the distance between the coordinates using the values.
* Input parameters: x1, x2, y1, y2
* Returns: distance
*/
double calculateDistance(double x1, double x2, double y1, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


/*
* Function name: evaluateEquation()
* Date created: 9/7/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user for values, which are plugged into the equation and returned.
* Input parameters: z, x, a
* Returns: y value
* Precondition: a must be odd
*/
double evaluateEquation(double z, double x, int a) {
	return ((float)89 / (float)27) - (z * x) + (a / (a % 2));
}