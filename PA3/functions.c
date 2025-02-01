/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab
* Programming Assignment: PA3
* Created: 9/16/2024
* Description: This file contains all of the function declaration of the program.
*/

#include "functions.h"

/*
* Function name: readDouble()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Scans the file for floats and puts it in a num variable, and returns the num.
* Input parameters: infile
* Returns: num
*/
double readDouble(FILE* infile) {
	double num = 0.0;
	fscanf(infile, "%lf", &num);
	return num;
}


/*
* Function name: readInteger()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Scans the file for integer value, puts it in num, and returns the num variable
* Input parameters: infile
* Returns: num
*/
int readInteger(FILE* infile) {
	int num = 0;
	fscanf(infile, "%d", &num);
	return num;
}


/*
* Function name: calculateSum()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Takes multiple numbers as parameters and returns the sum of all of them.
* Input parameters: number1, number2, number3, number4, number5
* Returns: sum
*/
double calculateSum(double number1, double number2, double number3, double number4, double number5) {
	double sum = number1 + number2 + number3 + number4 + number5;
	return sum;
}


/*
* Function name: calculateMean()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Takes the sum and number values in the parameters, divides them to get the mean, and returns the mean
* Input parameters: sum, number
* Returns: mean
* Precondition: number must not be 0
*/
double calculateMean(double sum, int number) {
	double mean = sum / number;
	return mean;
}


/*
* Function name: calculateDeviation()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Takes a number and a mean value, subtracts them to find the deviation, and returns it.
* Input parameters: number, mean
* Returns: deviation
*/
double calculateDeviation(double number, double mean) {
	double deviation = number - mean;
	return deviation;
}


/*
* Function name: calculateVariance()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Takes 5 deviation values and a number in the parameters, calculates the variance, and returns it.
* Input parameters: deviation1, deviation2, deviation3, deviation4, deviation5, number
* Returns: variance
* Precondition: number must not be 0
*/
double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {
	double variance = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / number;
	return variance;
}


/*
* Function name: calculateStandardDeviation()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Takes the variance value in the parameters and finds standard deviation by taking the square root of the variance.
* Input parameters: variance
* Returns: standardDeviation
* Precondition: variance must be positive
*/
double calculateStandardDeviation(double variance) {
	double standardDeviation = sqrt(variance);
	return standardDeviation;
}


/*
* Function name: findMax()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Takes 5 number values, and uses if statements to see if any of them are greater than or equal to the rest, and sets that as the max if they are.
* Input parameters: number1, number2, number3, number4, number5
* Returns: max
*/
double findMax(double number1, double number2, double number3, double number4, double number5) {
	double max = 0.0;

	if (number1 >= number2 && number1 >= number3 && number1 >= number4 && number1 >= number5) {
		max = number1;
	}
	if (number2 >= number1 && number2 >= number3 && number2 >= number4 && number2 >= number5) {
		max = number2;
	}
	if (number3 >= number1 && number3 >= number2 && number3 >= number4 && number3 >= number5) {
		max = number3;
	}
	if (number4 >= number1 && number4 >= number2 && number4 >= number3 && number4 >= number5) {
		max = number4;
	}
	if (number5 >= number1 && number5 >= number2 && number5 >= number3 && number5 >= number4) {
		max = number5;
	}

	return max;
}


/*
* Function name: findMin()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Takes 5 number values, and uses if statements to see if any of them are less than or equal to the rest, and sets that as the min if they are.
* Input parameters: number1, number2, number3, number4, number5
* Returns: min
*/
double findMin(double number1, double number2, double number3, double number4, double number5) {
	double min = 0.0;

	if (number1 <= number2 && number1 <= number3 && number1 <= number4 && number1 <= number5) {
		min = number1;
	}
	if (number2 <= number1 && number2 <= number3 && number2 <= number4 && number2 <= number5) {
		min = number2;
	}
	if (number3 <= number1 && number3 <= number2 && number3 <= number4 && number3 <= number5) {
		min = number3;
	}
	if (number4 <= number1 && number4 <= number2 && number4 <= number3 && number4 <= number5) {
		min = number4;
	}
	if (number5 <= number1 && number5 <= number2 && number5 <= number3 && number5 <= number4) {
		min = number5;
	}

	return min;
}


/*
* Function name: printDouble()
* Date created: 9/16/2024
* Programmer: Aabhwan Adhikary
* Description: Takes an output file and number as parameters, and inputs the number (as a formatted float in a string) out to the file.
* Input parameters: outfile, number
*/
void printDouble(FILE* outfile, double number) {
	fprintf(outfile, "%.2f\n", number);
}