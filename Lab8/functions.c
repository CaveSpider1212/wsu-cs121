#include "Header.h"

int populateArrayFromFile(FILE* ifstream, int* arrayNumbers) {
	int currentNumber = 0, arraySize = 0;

	while (fscanf(ifstream, "%d", &currentNumber) == 1) {
		arrayNumbers[arraySize] = currentNumber;
		++arraySize;
		currentNumber = 0;
	}

	return arraySize;
}

void reverseArray(int* arrayNumbers, int arraySize) {
	for (int i = 0; i < arraySize / 2; i++) {
		int temp = arrayNumbers[i];
		arrayNumbers[i] = arrayNumbers[arraySize - i - 1];
		arrayNumbers[arraySize - i - 1] = temp;
	}
}

void printIntegerArray(int *arrayNumbers, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		printf("Position %d number: %d\n", (i + 1), arrayNumbers[i]);
	}
}

int removeWhiteSpace(char* characters, int arraySize) {
	int numberWhiteSpace = 0;

	for (int i = 0; i < arraySize; i++) {
		if (characters[i] == ' ') {
			int whiteSpaceIndex = i;
			for (int j = whiteSpaceIndex; j < arraySize - 1; j++) {
				characters[j] = characters[j + 1];
			}
			numberWhiteSpace++;
		}
	}

	return numberWhiteSpace;
}

void printCharacterArray(char* characters, int arraySize, int whiteSpaceRemoved) {
	printf("Whitespace characters removed: %d\n", whiteSpaceRemoved);

	for (int i = 0; i < arraySize; i++) {
		printf("%c\n", characters[i]);
	}
}

void populateArrayFromRandoms(int* randoms) {
	for (int i = 0; i < 20; i++) {
		int number = rand() % 100 + 1;
		randoms[i] = number;
	}
}

void countNumbersGenerated(int* randoms, int *counts) {
	for (int i = 0; i < 20; i++) {
		counts[randoms[i]]++;
	}

	for (int j = 0; j < 101; j++) {
		if (counts[j] != 0) {
			printf("Number of instances of %d: %d\n", j, counts[j]);
		}
	}
}

char guessLetter(void) {
	char guess = '\0';
	printf("Guess a letter in the word:\n");
	scanf("\n%c", &guess);
	return guess;
}

int checkGuess(char* word, char* guessed, char guess) {
	int foundInWord = 0;
	for (int i = 0; i < 7; i++) {
		if (word[i] == guess) {
			guessed[i] = guess;
			foundInWord = 1;
		}
	}

	return foundInWord;
}

void printWord(char* word) {
	for (int i = 0; i < 7; i++) {
		printf("%c", word[i]);
	}
	printf("\n");
}

void displayGuessed(char* guessed) {
	for (int j = 0; j < 7; j++) {
		printf("%c", guessed[j]);
	}
}

int checkIfWordFound(char* word, char* guessed) {
	int wordGuessed = 1;
	for (int k = 0; k < 7; k++) {
		if (guessed[k] != word[k]) {
			wordGuessed = 0;
		}
	}

	return wordGuessed;
}