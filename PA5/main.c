/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: PA 5
* Created: 10/11/24
* Description: This program is an implementation of the dice game "Yahtzee".
*/

#include "Header.h"

int main(void) {
	srand((unsigned int)time(NULL));

	int menuChoice = 0;

	while (menuChoice != 3) {
		menuChoice = gameMenu();
		if (menuChoice == 1) {
			printGameRules();
		}
		if (menuChoice == 2) {
			startGame();
		}
	}

	printf("Thank you for playing!\n");

	return 0;
}