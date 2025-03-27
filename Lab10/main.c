// LAB 10 - 10/30/24

#include "Header.h"

int main(void) {
	srand((unsigned int)time(NULL));

	// TASK 1
	printf("TASK 1\n\n");

	char *article[5] = { "the", "a", "one", "some", "any"};
	char* noun[5] = { "boy", "girl", "dog", "town", "car" };
	char* verb[5] = { "drove", "jumped", "ran", "walked", "skipped" };
	char* preposition[5] = { "to", "from", "over", "under", "on" };
	char sentence[20][MAX_SIZE] = { 0 };

	printf("%s\n", article[0]);

	// createSentences(article, noun, verb, preposition, sentence);
	// displaySentences(sentence);
	
	// TASK 2
	printf("TASK 2\n\n");

	char playAgain = 'y';
	int currentPlayer = 1;

	do {
		typedef struct
		{
			int row;
			int column;
		} Coordinate;

		typedef struct {
			int occupied;
			char symbol;
			Coordinate location;
		} Cell;

		typedef struct {
			int wins;
			int losses;
		} GameInfo;

		Cell cells[9];
		cells[0].occupied = 0, cells[0].location.row = 0, cells[0].location.column = 0;
		cells[1].occupied = 0; cells[1].location.row = 0, cells[1].location.column = 1;
		cells[2].occupied = 0, cells[2].location.row = 0, cells[2].location.column = 2;
		cells[3].occupied = 0, cells[3].location.row = 1, cells[3].location.column = 0;
		cells[4].occupied = 0; cells[4].location.row = 1, cells[4].location.column = 1;
		cells[5].occupied = 0, cells[5].location.row = 1, cells[5].location.column = 2;
		cells[6].occupied = 0, cells[6].location.row = 2, cells[6].location.column = 0;
		cells[7].occupied = 0; cells[7].location.row = 2, cells[7].location.column = 1;
		cells[8].occupied = 0, cells[8].location.row = 2, cells[8].location.column = 2;

		Coordinate p1Coords, p2Coords;

		printf("Player %d, enter the coordinates separated by spaces (starting from 0):\n", currentPlayer);
		if (currentPlayer == 1) {
			inputCoordinates(&p1Coords.row, &p1Coords.column);
		}
		else {
			inputCoordinates(&p2Coords.row, &p2Coords.column);
		}

		for (int i = 0; i < 9; i++) {
			if (currentPlayer == 1) {
				if (cells[i].location.row == p1Coords.row && cells[i].location.column == p1Coords.column) {
					if (cells[i].occupied != 1) {
						cells[i].symbol = 'X';
						cells[i].occupied = 0;
						break;
					}
					else {
						printf("This cell is occupied!");
					}
				}
			}
			else {
				if (cells[i].location.row == p2Coords.row && cells[i].location.column == p2Coords.column) {
					if (cells[i].occupied != 1) {
						cells[i].symbol = 'O';
						cells[i].occupied = 0;
						break;
					}
					else {
						printf("This cell is occupied!");
					}
				}
			}
		}

		printf("Do you want to play again? (y/n)");
		scanf("\n%c", &playAgain);
	} while (playAgain != 'n');

	return 0;
}