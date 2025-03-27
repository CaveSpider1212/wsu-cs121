// Lab 6 - 10/2/24

#include "Header.h"

int readInteger(FILE* infile) {
	int num = 0;
	fscanf(infile, "%d", &num);
	return num;
}

int sumDigits(int num) {
	int number = num;
	int digitSum = 0;

	while (number > 0) {
		digitSum += number % 10;
		number /= 10;
	}

	return digitSum;
}

void checkPrime(int originalNum, int digitSum) {
	int divisor = 2;

	while (divisor < digitSum) {
		if (digitSum % divisor == 0) { // digitSum can be divided by divisor, which can't be 1 or itself so it is not prime
			printf("The sum of the digits of %d is %d, which is not a prime number.\n", originalNum, digitSum);
			break;
		}
		divisor++;
	}

	if (divisor == digitSum) { // only possible if the program went through the while loop without the if statement being true, so it is prime
		printf("The sum of the digits of %d is %d, which is a prime number.\n", originalNum, digitSum);
	}
}

int findFactorial(int num) {
	int product = 1;

	for (int factor = num; factor > 0; factor--) {
		product *= factor;
	}

	return product;
}

void displayFibonacci(int term) {
	int firstTerm = 0;
	int secondTerm = 1;

	printf("\nFibonacci Sequence:");

	if (term >= 0) { // displays this if the term is greater than 1 (if term equals 1 then the program will display only 0)
		printf(" %d", firstTerm);
	}
	if (term >= 1) { // displays this if the term is greater than or equal to 2 (if term equals 2 then the program will display 0 and 1)
		printf(" %d", secondTerm);
	}
	if (term > 1) { // displays this if the term is greater than 2 (will display 0, 1, and then anything after)
		for (int n = 1; n < term; n++) { // iterates from 2 up to the term value
			int currentTerm = firstTerm + secondTerm;
			printf(" %d", currentTerm);

			firstTerm = secondTerm; // moves to the next term in the sequence
			secondTerm = currentTerm;
		}
	}

	printf("\n");
}

int generateRandomNumber(void) {
	srand((unsigned int)time(NULL)); // seeds the random number
	int number = rand() % 201 - 100; // generates a random number from -100 up to 100 (not including 100)
	return number;
}