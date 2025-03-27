#include "Header.h"

char* reverseString(char word[], int i) {
	char reversedWord[21];

	if (i == 0) {
		return word[i];
	}
	else {
		
	}
}

int sumDigits(int num) {
	int sum = 0;

	sum = num % 10;
	
	if (num > 0) {
		sum += sumDigits(num / 10);
	}

	return sum;
}

void determinePath(char array[8][8], int been[100][2], int row, int col, int i) {
	int pathExists = 1;

	if (array[7][7] == 'x') {
		pathExists = 0;
	}
	else {
		if (array[row + 1][col] != 'x' && row < 8) {
			determinePath(array, been, row + 1, col, i);
		}
		else {
			determinePath(array, been, row, col + 1, i);

			if (array[row][col + 1] == 'x' || col >= 8) {
				determinePath(array, been, row, col - 1, i);

				if (array[row][col - 1] == 'x' || col < 0) {
					determinePath(array, been, row - 1, col, i);
				}
			}
		}

		if (array[row][col + 1] != 'x' && col < 8) {
			determinePath(array, been, row, col + 1, i);
		}
		else {
			determinePath(array, been, row + 1, col, i);

			if (array[row + 1][col] == 'x' || row >= 8) {
				determinePath(array, been, row, col - 1, i);

				if (array[row][col - 1] == 'x' || col < 0) {
					determinePath(array, been, row - 1, col, i);
				}
			}
		}

		been[i][0] = row, been[i][1] = col;
		(i)++;
	}
}

void printPath(int been[100][2]) {
	int i = 0;
	while (been[i][0] != NULL) {
		for (int j = 0; j < 2; j++) {
			printf("(%d, %d)\n", been[i][j]);
		}

		i++;
	}
}