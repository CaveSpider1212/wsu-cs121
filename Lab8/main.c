// LAB 8 - 10/16/2024

#include "Header.h"

int main(void) {
	// PART 1
	printf("PART 1 - REVERSE ARRAY\n\n");

	FILE* integerNumbers = NULL;
	int numbers[100], arraySize = 0;

	integerNumbers = fopen("numbers.txt", "r");

	arraySize = populateArrayFromFile(integerNumbers, numbers);
	fclose(integerNumbers);

	reverseArray(numbers, arraySize);
	printIntegerArray(numbers, arraySize);

	printf("-----------------------------------------------------------------------------------------\n");

	// PART 2
	printf("PART 2 - REMOVE WHITESPACE\n\n");

	char characterArray[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ' ', '!' };
	int characterArraySize = 13, whiteSpaceRemoved = 0;

	whiteSpaceRemoved = removeWhiteSpace(characterArray, characterArraySize);
	printCharacterArray(characterArray, characterArraySize, whiteSpaceRemoved);

	printf("-----------------------------------------------------------------------------------------\n");

	// PART 3
	printf("PART 3 - RANDOM INTEGERS\n\n");

	srand((unsigned int)time(NULL));
	int randomNumbers[20], timesGenerated[101];

	for (int i = 0; i < 101; i++) {
		timesGenerated[i] = 0;
	}

	populateArrayFromRandoms(randomNumbers);
	countNumbersGenerated(randomNumbers, timesGenerated);

	printf("-----------------------------------------------------------------------------------------\n");

	// PART 4
	printf("PART 4 - HANGMAN\n\n");

	char word[] = { 'm', 'o', 'n', 'i', 't', 'o', 'r' };
	char guessed[7];
	int mistakes = 0, wordGuessed = 0;

	for (int j = 0; j < 7; j++) {
		guessed[j] = '*';
	}

	while (mistakes < 6 && wordGuessed != 1) {
		displayGuessed(guessed);
		printf("\nYou have %d mistakes currently.\n", mistakes);

		char guess = guessLetter();
		
		if (checkGuess(word, guessed, guess) == 0) {
			mistakes++;
		}

		wordGuessed = checkIfWordFound(word, guessed);
	}

	if (mistakes == 6) {
		printf("\nSorry, you lost. The word was: ");
		printWord(word);
	}
	if (wordGuessed == 1) {
		printf("\nYou won!\n");
	}

	return 0;
}