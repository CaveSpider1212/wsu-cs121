/*
* Programmer: Aabhwan Adhikary
* Created: 11/13/2024
* Assignment: PA7
* Class: CptS 121, Fall 2024; Lab Section 19
* Description: This is an implementation of a game of poker.
*/

#include "Header.h"

int main(void)
{
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	Hand h1, h2;
	int currentCardNumber = 1;
	int p1Score = 0, p2Score = 0;

	srand((unsigned)time(NULL)); /* seed random-number generator */
	shuffle(deck);

	char play = '\0';
	printGameMenu(&play);
	
	while (play == 'y') { // continues until player no longer wants to play
		system("cls");

		int p1CardDraw[5] = { 1, 1, 1, 1, 1 };
		int p2CardDraw[5] = { 1, 1, 1, 1, 1 };

		deal(deck, face, suit, &currentCardNumber, &h1, p1CardDraw);
		deal(deck, face, suit, &currentCardNumber, &h2, p2CardDraw);

		printf("\nYour hand:\n");
		printHand(&h1, face, suit);

		printf("\n");
		displayAvailableHands(&h1);

		askToReplaceCards(p1CardDraw);
		deal(deck, face, suit, &currentCardNumber, &h1, p1CardDraw);

		simulateDealer(&h2, p2CardDraw);
		deal(deck, face, suit, &currentCardNumber, &h2, p2CardDraw);

		printf("\nPlayer 1 final hand:\n");
		printHand(&h1, face, suit);

		printf("\nPlayer 2 final hand:\n");
		printHand(&h2, face, suit);

		evaluateHands(&h1, &h2, &p1Score, &p2Score);

		printf("\nPlayer 1 score: %d\nPlayer 2 score: %d\n", p1Score, p2Score);
		askToContinue(&play);
	}

	system("cls");
	if (p1Score > p2Score) {
		printf("Player 1 wins! Restart to play again.\n");
	}
	else if (p1Score < p2Score) {
		printf("Player 2 wins! Restart to play again.\n");
	}
	else {
		printf("Draw! Restart to play again.\n");
	}

	return 0;
}