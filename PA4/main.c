/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: PA 4
* Created: 9/27/2024
* Description: This program is an implementation of the dice game "Craps".
*/

#include "Header.h"

int main(void) {
	double balance = 0.0, initBalance = 0.0, wagerAmount = 0.0;
	int wagerCheck = 0, die1 = 0, die2 = 0, sumDie = 0;
	int winLossCheck = 0, pointValue = 0;
	char stillPlaying = '\0';

	printGameRules();

	while (balance <= 0) { // checks to make sure the user actually input a balance greater than 0, will keep repeating if user doesn't until they actually do
		initBalance = getBankBalance(); // prompts the user for the initial balance
		balance = initBalance;
	}

	while (balance > 0 && stillPlaying != 'n') { // while the game is still being played
		int numRolls = 0;

		printf("\nBalance: $%.2f", balance); // turn into a function?
		wagerAmount = getWagerAmount(); // prompts the user for a wager amount

		wagerCheck = checkWagerAmount(wagerAmount, balance); // checks that the wager amount isn't greater than the balance

		if (wagerCheck == 1) { // checks that the wager is less than the balance
			srand((unsigned int)time(NULL));

			die1 = rollDie(); // rolls the first dice
			die2 = rollDie(); // rolls the second dice
			numRolls++;

			sumDie = calculateSumDice(die1, die2); // calculates the sum of the roll

			winLossCheck = isWinLossOrPoint(sumDie); // checks the sum to see if the player won the roll
			if (winLossCheck == -1) { // point value
				pointValue = sumDie; // sets the point value to the sum
				printf(" That is now your point value.\n", pointValue); // adds extra part to the "sum" print message

				while (winLossCheck == -1) { // while the player is still trying to roll their point value
					die1 = rollDie(); // rolls the first dice
					die2 = rollDie(); // rolls the second dice
					numRolls++;

					sumDie = calculateSumDice(die1, die2); // calculates the sum of the dice

					winLossCheck = isPointLossOrNeither(sumDie, pointValue); // checks if the player rolled their point value
				}
			}

			balance = adjustBankBalance(balance, wagerAmount, winLossCheck); // changes the bank balance based on whether they won or not
			chatterMessages(numRolls, winLossCheck, initBalance, balance); // displays messages

			if (balance > 0) { // checks if the player still wants to play if their balance hasn't hit 0 yet
				stillPlaying = checkPlaying(balance);
			}
		}
	}

	if (balance == 0) { // done if the while loop ended when the player's balance hit 0
		printf("\nYou're out of money. Restart to play again.\n");
	}
	
	if (balance > 0) { // done if the while loop ended when the player quit the game before their balance hit 0
		printf("\nYou ended with a balance of $%.2f! Restart to play again.\n", balance);
	}

	return 0;
}