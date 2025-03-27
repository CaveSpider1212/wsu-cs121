// Lab 6 - 10/2/24

#include "Header.h"

int main(void) {
	printf("PART 1 - PRIME\n\n");

	FILE* numbersFile = NULL;

	numbersFile = fopen("numbers.txt", "r");

	while (!feof(numbersFile)) { // runs until we reach the end of the file
		int num = readInteger(numbersFile); // reads integers from the text file
		int digitSum = sumDigits(num); // computes the sum of the digits of the number
		checkPrime(num, digitSum); // checks if the sum of the digits is prime
	}

	printf("--------------------------------------------------------------------------------------------------------\n");

	printf("PART 2 - FACTORIAL\n\n");

	int num = 0, factorial = 0;
	
	printf("Please enter a value for n to find its factorial:\n");
	scanf("%d", &num);

	if (num >= 0) {
		int factorial = findFactorial(num); // finds the factorial of num
		printf("The factorial of %d is %d.\n", num, factorial);
	}

	printf("--------------------------------------------------------------------------------------------------------\n");

	printf("PART 3 - FIBONACCI\n\n");

	int term = 0;

	printf("Please enter the number of terms for the fibonacci sequence (starts from term 0):\n");
	scanf("%d", &term);

	displayFibonacci(term);

	printf("--------------------------------------------------------------------------------------------------------\n");

	printf("PART 4 - RANDOM NUMBER\n\n");

	int randomNumber = 0, guess = 0, totalGuesses = 0;
	
	randomNumber = generateRandomNumber();

	do { // iterates the loop until the guess equals the random number
		printf("Please guess a number from -100 up to 100:\n");
		scanf("%d", &guess);

		if (guess < -100 || guess >= 100) { // checks that the user's guess is in the range
			printf("Re-enter a number between -100 up to 100.\n\n");
		}
		else {
			totalGuesses++;

			if (guess > randomNumber) { // done if the guess is too high
				printf("Your guess is too high.\n\n");
			}
			else if (guess < randomNumber) { // done if the guess is too low
				printf("Your guess is too low.\n\n");
			}
			else { // done if the guess is correct
				printf("You got it right! It took %d guesses.\n", totalGuesses);
			}
		}
	} while (guess != randomNumber);

	return 0;
}