/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Programming Assignment: Lab 1 Task 2
* Date: August 28, 2024
* Description: Takes inputs of 2 integer values and 2 floating point values and performs operations on them.
*/

#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings
#define PI 3.14159
#include <stdio.h> // necessary to use printf () and scanf ()
int main(void) // the starting point for all C programs
{
	// PART A
	printf("PART A -\n\n");

	// we need to request memory for
	int number1_int = 0, number2_int = 0; // 2 variable declarations - reserves two memory blocks for integers and sets them to 0's
	double number1_float = 0.0, number2_float = 0.0; // reserves two memory blocks for numbers with high precision (floating-point)

	printf("Enter two integer values: "); // prompt/ask the user
	scanf("%d%d", &number1_int, &number2_int); // read the integers typed through the keyboard - %d is for "decimal", i.e. integers

	printf("Enter two floating-point values: "); // prompt/ask the user
	scanf("%lf%lf", &number1_float, &number2_float); // read the integers typed through the keyboard - %lf is for "long float", i.e. double precision numbers

   // place all code for the subtasks/operations below here

	// add number1_int and number2_int together and print the result as an integer value
	int sum_a = number1_int + number2_int;
	printf("Sum of number1_int and number2_int: %d\n", sum_a);

	// subtract number1_float from number2_float and print the result as a floating-point value
	double difference_b = number2_float - number1_float;
	printf("Difference between number1_float and number2_float: %f\n", difference_b);

	// multiply number1_int by number1_float and print the result as an integer value
	int product_c = number1_int * number1_float;
	printf("Product of number1_int and number1_float: %d\n", product_c);

	// divide number1_int by number2_int and print the result as an integer and a floating-point value
	float quotient_d = number1_int / number2_int;
	printf("Quotient of number1_int by number2_int: %f\n", quotient_d);

	// divide number1_int by number2_float and print the result as an integer and a floating-point value
	float quotient_e = number1_int / number2_float;
	printf("quotient of number1_int by number2_float: %f\n", quotient_e);

	// explicitly cast number1_int as a floating-point value and divide by number2_int...print the result as a floating-point value
	float quotient_f = (float)number1_int / number2_int;
	printf("Quotient of number1_int by number2_int: %f\n", quotient_f);

	// try to mod number1_float by number2_float
	int mod_g = (int) number1_float % (int) number2_float;
	printf("Modulus of number1_float by number2_float: %d\n", mod_g);

	// determine if nummber1_int and number2_int are even or odd...print 0 if even and 1 if odd
	int even_or_odd1_h = number1_int % 2;
	printf("number1_int even (0) or odd (1): %d\n", even_or_odd1_h);
	int even_or_odd2_h = number2_int % 2;
	printf("number2_int even (0) or odd (1): %d\n", even_or_odd2_h);
	
	// PART B
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("PART B -\n\n");

	int current = 0, resistance_b = 0, voltage_b = 0;

	printf("Enter the current value:\n");
	scanf("%d", &current);

	printf("Enter the resistance value:\n");
	scanf("%d", &resistance_b);

	voltage_b = current * resistance_b;
	printf("Voltage: %d\n", voltage_b);

	// PART C
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("PART C -\n\n");

	int voltage_c = 0, resistance_c = 0, power = 0;

	printf("Enter the voltage value:\n");
	scanf("%d", &voltage_c);

	printf("Enter the resistance value:\n");
	scanf("%d", &resistance_c);

	power = (voltage_c * voltage_c) / resistance_c;
	printf("Power: %d\n", power);

	// PART D
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("PART D -\n\n");

	int x = 0, y = 0, a = 0, b = 0, c = 0, d = 0;

	printf("Enter the values for x, a, b, c, and d:\n");
	scanf("%d%d%d%d%d", &x, &a, &b, &c, &d);

	y = (3 * a * x * x * x) + (((double) 1 / (double) 4) * b * x * x) + (10 * c * x) + (-5 * d);
	printf("y = %d\n", y);

	// PART E
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("PART E -\n\n");

	float radius = 0, circumference = 0;

	printf("Enter the radius:\n");
	scanf("%f", &radius);

	circumference = 2 * PI * radius;
	printf("Circumference: %f\n", circumference);

	return 0; // return a success status (value 0) indicating the program worked fine

} // end of the main () function