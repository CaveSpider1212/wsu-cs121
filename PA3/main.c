/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab
* Programming Assignment: PA3
* Created: 9/16/2024
* Description: This program takes inputs from a data file, does operations with them, and outputs them to another data file.
*/

#include "functions.h"

int main() {
	// creates input/output file stream variables
	FILE* infile = NULL;
	FILE* outfile = NULL;

	// creates variables which will take values from the file
	int studentID1 = 0, studentID2 = 0, studentID3 = 0, studentID4 = 0, studentID5 = 0;
	double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0;
	int class1 = 0, class2 = 0, class3 = 0, class4 = 0, class5 = 0;
	double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0;
	
	// creates variables which will either be used for operations or displayed to the output file
	int classSum = 0;
	double gpaSum = 0.0, ageSum = 0.0;
	double gpaMean = 0.0, ageMean = 0.0, classMean = 0.0;
	double gpaDev1 = 0.0, gpaDev2 = 0.0, gpaDev3 = 0.0, gpaDev4 = 0.0, gpaDev5 = 0.0;
	double gpaVariance = 0.0;
	double gpaStandardDev = 0.0;
	double gpaMin = 0.0, gpaMax = 0.0;

	// opens a file for the input and output stream (one is a read-only input file, and the other is an append-only output file)
	infile = fopen("input.dat", "r");
	outfile = fopen("output.dat", "a");

	// takes values for the first student record file from the input file using either the readInteger() or readDouble() methods
	studentID1 = readInteger(infile);
	gpa1 = readDouble(infile);
	class1 = readInteger(infile);
	age1 = readDouble(infile);

	// takes values for the second student record file from the input file using either the readInteger() or readDouble() methods
	studentID2 = readInteger(infile);
	gpa2 = readDouble(infile);
	class2 = readInteger(infile);
	age2 = readDouble(infile);

	// takes values for the third student record file from the input file using either the readInteger() or readDouble() methods
	studentID3 = readInteger(infile);
	gpa3 = readDouble(infile);
	class3 = readInteger(infile);
	age3 = readDouble(infile);

	// takes values for the fourth student record file from the input file using either the readInteger() or readDouble() methods
	studentID4 = readInteger(infile);
	gpa4 = readDouble(infile);
	class4 = readInteger(infile);
	age4 = readDouble(infile);

	// takes values for the fifth student record file from the input file using either the readInteger() or readDouble() methods
	studentID5 = readInteger(infile);
	gpa5 = readDouble(infile);
	class5 = readInteger(infile);
	age5 = readDouble(infile);

	// calculates the sum of all of the GPAs, classes, and ages that were obtained from the file using the calculateSum() method
	gpaSum = calculateSum(gpa1, gpa2, gpa3, gpa4, gpa5);
	classSum = calculateSum(class1, class2, class3, class4, class5);
	ageSum = calculateSum(age1, age2, age3, age4, age5);

	// calculates the mean of all of the GPAs, classes, and ages that were obtained from the file using the calculateMean() method
	gpaMean = calculateMean(gpaSum, 5);
	classMean = calculateMean(classSum, 5);
	ageMean = calculateMean(ageSum, 5);
	
	// outputs the GPA, class, and age mean values to the output file
	printDouble(outfile, gpaMean);
	printDouble(outfile, classMean);
	printDouble(outfile, ageMean);

	// calculates the deviation of each of the GPA values found in the input file
	gpaDev1 = calculateDeviation(gpa1, gpaMean);
	gpaDev2 = calculateDeviation(gpa2, gpaMean);
	gpaDev3 = calculateDeviation(gpa3, gpaMean);
	gpaDev4 = calculateDeviation(gpa4, gpaMean);
	gpaDev5 = calculateDeviation(gpa5, gpaMean);

	// calculates the variance of all of the GPA deviation values, and uses it to calculate standard deviation and output it to the output file
	gpaVariance = calculateVariance(gpaDev1, gpaDev2, gpaDev3, gpaDev4, gpaDev5, 5);
	gpaStandardDev = calculateStandardDeviation(gpaVariance);
	printDouble(outfile, gpaStandardDev);

	// finds the maximum and minimum value out of all of the GPA values found in the input file using the findMin() and findMax() methods, and outputs both values to the output file
	gpaMin = findMin(gpa1, gpa2, gpa3, gpa4, gpa5);
	gpaMax = findMax(gpa1, gpa2, gpa3, gpa4, gpa5);
	printDouble(outfile, gpaMin);
	printDouble(outfile, gpaMax);

	// closes the input and output files and destroys the file streams
	fclose(infile);
	fclose(outfile);

	return 0;
}
