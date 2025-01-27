/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Programming Assignment: PA 2
* Created: 9/7/2024
* Description: This program contains a series of parts that each use functions to solve the problems (the parts are described below).
*	- PART 1: This part of the program takes user input for mass and acceleration and uses those values to compute the force by multiplying them together.
*
*	- PART 2: This part of the program takes user input for the radius and height, and also uses the preprocessor directive constant macro PI, and uses those values to compute
* the volume of a cylinder.
*
*	- PART 3: This part of the program takes user input for the offset value and a plain text character and performs operations on them using ASCII codes. The resulting ASCII code
* from that operation is converted into a different character, which is the encoded character.
*
*	- PART 4: This part of the program takes user input for mass1, mass2, and distance, and, along with the preproccessor directive constant macro G, computes the gravitational force
* using all of those values.
*
*	- PART 5: This part of the program takes user input for the Fahrenheit value, and uses it to convert it to a Celsius value.
*
*	- PART 6: This part of the program takes the x and y coordinates of 2 different points, and uses those coordinates to compute the distance between the two points using the
* distance formula.
*
*	- PART 7: This part of the program takes user input for z, x, and a, and uses it in an equation, y, to find the value of the equation.
*/

#include "equations.h"

int main(void) {


	// PART 1
	printf("PART 1 - NEWTON'S SECOND LAW OF MOTION\n\n\n");

	float mass = 0.0, acceleration = 0.0, force = 0.0; // creates mass, acceleration, and force variables as floats set to 0.0

	printf("Please input the mass (floating-point value):\n");
	scanf("%f", &mass); // takes user input for mass

	printf("Please input the acceleration (floating-point value):\n");
	scanf("%f", &acceleration); // takes user input for acceleration

	force = calculate_newtons_2nd_law(mass, acceleration); // calculates the force using the calculate_newtons_2nd_law() function
	printf("force = mass * acceleration = %f * %f = %.2f\n\n", mass, acceleration, force); // outputs the force

	printf("----------------------------------------------------------------------------------------------------------------\n");




	// PART 2
	printf("PART 2 - VOLUME OF A CYLINDER\n\n\n");

	float radius = 0.0, height = 0.0, volume_cylinder = 0.0; // creates radius, height, and volume_cylinder variables as floats set to 0.0

	printf("Please input the radius (floating-point value):\n");
	scanf("%f", &radius); // takes user input for radius

	printf("Please input the height (floating-point value):\n");
	scanf("%f", &height); // takes user input for height

	volume_cylinder = calculate_volume_cylinder(radius, height); // calculates the volume of the cylinder using the calculate_volume_cylinder() function
	printf("volume_cylinder = PI * radius^2 * height =  %f * %f^2 * %f = %.2f\n\n", PI, radius, height, volume_cylinder); // outputs the volume of the cylinder

	printf("----------------------------------------------------------------------------------------------------------------\n");




	// PART 3
	printf("PART 3 - CHARACTER ENCODING\n\n\n");

	char encoded_character = '\0', plaintext_character = '\0'; // creates encoded_character and plaintext_character char variables with values set to a null character (ASCII code = 0)
	int offset = 0; // creates an offset int variable with value 0

	printf("Please input the offset (integer):\n");
	scanf("%d", &offset); // takes user input for offset

	printf("Please input the plain text character (character):\n");
	scanf(" %c", &plaintext_character); // takes user input for plain text character

	encoded_character = perform_character_encoding(plaintext_character, offset); // generates the encoded character using the perform_character_encoding() function
	printf("encoded_character = offset + (plaintext_character - 'a') + 'A' = %d + (%c - 'a') + ('A') = %c\n\n", offset, plaintext_character, encoded_character); // outputs the encoded character

	printf("----------------------------------------------------------------------------------------------------------------\n");




	// PART 4
	printf("PART 4 - GRAVITY\n\n\n");

	float gravity = 0.0, mass1 = 0.0, mass2 = 0.0, distance = 0.0; // creates gravity, mass1, mass2, and distance variables as floats with values 0.0

	printf("Please input the first mass (floating-point value):\n");
	scanf("%f", &mass1); // takes user input for mass1

	printf("Please input the second mass (floating-point value):\n");
	scanf("%f", &mass2); // takes user input for mass2

	printf("Please input the distance (floating-point value):\n");
	scanf("%f", &distance); // takes user input for mass3

	gravity = calculateGravityForce(mass1, mass2, distance); // calculates gravitational force using the calculateGravityForce() function
	printf("force = G * mass1 * mass2 / distance^2 = %.13lf * %f * %f / %f^2 = %.13lf\n\n", G, mass1, mass2, distance, gravity); // outputs value for gravity

	printf("----------------------------------------------------------------------------------------------------------------\n");




	// PART 5
	printf("PART 5 - FAHRENHEIT TO CELSIUS CONVERSION\n\n\n");

	float celsius = 0.0, fahrenheit = 0.0; // creates celsius and fahrenheit variables as floats with values 0.0

	printf("Please input the Fahrenheit value (floating-point value):\n");
	scanf("%f", &fahrenheit); // takes user input for fahrenheit

	celsius = calculateCelsius(fahrenheit); // calculates the celsius value using the calculateCelsius() function
	printf("celsius = (fahrenheit - 32) / (9 / 5) = (%f - 32) / (9 / 5) = %.2f\n\n", fahrenheit, celsius); // outputs celsius value

	printf("----------------------------------------------------------------------------------------------------------------\n");




	// PART 6
	printf("PART 6 - DISTANCE BETWEEN TWO POINTS\n\n\n");

	float distance1 = 0.0, x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0; // creates distance1, x1, x2, y1, and y2 variables as floats with no value

	printf("Please input the first set of x and y coordinates on separate lines (floating-point values):\n");
	scanf("%f%f", &x1, &y1); // takes user input for x1 and y1

	printf("Please input the second set of x and y coordinates on separate lines (floating-point values):\n");
	scanf("%f%f", &x2, &y2); // takes user input for x2 and y2

	distance1 = calculateDistance(x1, x2, y1, y2); // calculates distance between the points using the calculateDistance() function
	printf("distance = square root of ((x1 - x2)^2 + (y1 - y2)^2) = square root of ((%f - %f)^2 + (%f - %f)^2) = %.2f\n\n", x1, x2, y1, y2, distance1); // outputs value for distance

	printf("----------------------------------------------------------------------------------------------------------------\n");




	// PART 7
	printf("PART 7 - GENERAL EQUATION\n\n\n");

	float y = 0.0, z = 0.0, x = 0.0; // creates y, z, and x variables as floats with no value
	int a = 0; // creates int variable a with no value

	printf("Please input the value for z (floating-point value):\n");
	scanf("%f", &z); // takes user input for z

	printf("Please input the value for x (floating-point value):\n");
	scanf("%f", &x); // takes user input for x

	printf("Please input the value for a (integer):\n");
	scanf("%d", &a); // takes user input for a

	y = evaluateEquation(z, x, a); // evaluates the equation using the evaluateEquation() function
	printf("y = (89 / 27) - z * x + a / (a %% 2) = (89 / 27) - %f * %f + %d / (%d %% 2) = %.2f\n\n", z, x, a, a, y); // outputs value for y


	return 0;
}