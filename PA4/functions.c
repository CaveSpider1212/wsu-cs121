/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: PA 4
* Created: 9/27/2024
* Description: This file contains all of the function declarations of the program.
*/

#include "Header.h"

/*
* Function name: printGameRules()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: Displays the rules of the game using print statements
* Input parameters: none
* Returns: none
*/
void printGameRules(void) {
	printf("RULES OF CRAPS:\n");
	printf("A player rolls two dice. Each dice has six faces, which contain 1, 2, 3, 4, 5, and 6 spots.\n");
	printf("After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (\"craps\"), the player loses.\n");
	printf("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, the sum becomes the players \"point.\"\n");
	printf("To win, you must continue rolling the dice until you \"make your point.\" The player loses by rolling a 7 before making the point.\n\n");
}

/*
* Function name: getBankBalance()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user to input their initial bank balance
* Input parameters: none
* Returns: balance
*/
double getBankBalance(void) {
	double balance = 0.0;
	
	printf("\nPlease input your initial bank balance:\n");
	scanf("%lf", &balance);

	if (balance <= 0) {
		printf("\nYou need to input a balance greater than 0!");
	}

	return balance;
}

/*
* Function name: getWagerAmount()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user for their wager amount
* Input parameters: none
* Returns: wager amount
*/
double getWagerAmount(void) {
	double wagerAmount = 0.0;

	printf("\nPlease input your wager amount for this roll:\n");
	scanf("%lf", &wagerAmount);

	return wagerAmount;
}

/*
* Function name: checkWagerAmount()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: checks if the wager amount is greater than the balance, and displays a message if so
* Input parameters: wager (double) will be compared with balance (double) to see if it is greater than the balance
* Returns: number representing whether the wager is greater than the balance or not (check)
*/
int checkWagerAmount(double wager, double balance) {
	int check = 1;

	if (wager > balance) {
		printf("\nYou can't wager an amount greater than your balance!");
		check = 0;
	}

	return check;
}

/*
* Function name: rollDie()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: Generates a random number from 1 to 6 ("rolling the dice")
* Input parameters: none
* Returns: value representing random number (rolled dice value)
*/
int rollDie(void) {
	int value = 0;
	
	value = rand() % 6 + 1; // random number from 1 to 6

	return value;
}

/*
* Function name: calculateSumDice()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: Computes the sum of the 2 dice values and displays it to the user
* Input parameters: die1Value (int) will be added to die2Value (int) for the sum
* Returns: sum of the first dice value and second dice value
*/
int calculateSumDice(int die1Value, int die2Value) {
	int sum = die1Value + die2Value;
	printf("\nYou rolled a %d.", sum);
	return sum;
}

/*
* Function name: isWinLossOrPoint()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: Checks if the sum of the dice leads to a win, loss, or point value
* Input parameters: sumDice (int) will be evaluated in if-statements to see whether the user won, lost, or has a point value
* Returns: value representing whether the user won, lost, or has a point value
*/
int isWinLossOrPoint(int sumDice) {
	int value = 0;

	if (sumDice == 7 || sumDice == 11) { // wins
		value = 1;
	}
	else if (sumDice == 2 || sumDice == 3 || sumDice == 12) { // loses
		value = 0;
	}
	else { // point value
		value = -1;
	}

	return value;
}

/*
* Function name: isPointLossorNeither()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: Checks if the sum of the dice leads to making the point, losing, or continuing to roll
* Input parameters: sumDice (int) will be evaluated in if-statements to see whether the user made their point, lost, or has to continue rolling
* Returns: value representing whether the user made the point, lost, or has to continue rolling
*/
int isPointLossOrNeither(int sumDice, int pointValue) {
	int value = 0;

	if (sumDice == pointValue) { // makes the point
		value = 1;
	}
	else if (sumDice == 7) { // loses
		value = 0;
	}
	else { // any other case...has to continue rolling
		value = -1;
	}

	return value;
}

/*
* Function name: adjustBankBalance()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: adjusts the balance by adding or subtracting the wager amount from it, depending on whether the user won or lost
* Input parameters: wagerAmount (double) will be added to or subtracted from bankBalance (double) depending on what the value of addOrSubtract (int) is
* Returns: new balance after adding or subtracting wager to it (bal)
*/
double adjustBankBalance(double bankBalance, double wagerAmount, int addOrSubtract) {
	double bal = 0.0;

	if (addOrSubtract == 1) { // win
		bal = bankBalance + wagerAmount;
	}
	
	if (addOrSubtract == 0) { // loss
		bal = bankBalance - wagerAmount;
	}

	return bal;
}

/*
* Function name: chatterMessages()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: Displays messages to the user depending on situations
* Input parameters: numberRolls (int), winLossNeither (int), initialBankBalance (double), and currentBankBalance (double) used in if-statements to display certain messages to the user
* Returns: none
*/
void chatterMessages(int numberRolls, int winLossNeither, double initialBankBalance, double currentBankBalance) {
	printf("\n\n");

	if (numberRolls > 4) {
		printf("That took %d rolls. That is a lot.\n", numberRolls);
	}
	else {
		if (numberRolls == 1) {
			printf("That was quick.\n");
		}
	}

	if (winLossNeither == 1) {
		printf("You won! Your wager amount has been added to your bank balance.\n");
	}
	else {
		printf("You lost. Your wager amount has been subtracted from your balance.\n");
	}

	if (currentBankBalance - initialBankBalance > 0) {
		printf("You have been gaining money since you started. You should wager more.\n");
	}
	else {
		printf("You have been losing money since you started.\n");
	}
}

/*
* Function name: checkPlaying()
* Date created: 10/4/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user on whether they want to continue playing or not after showing their balance; also makes sure they type the right character
* Input parameters: bal (double) is shown to the user in a print statement
* Returns: character representing whether the user wants to continue playing or not (stillPlaying)
*/
char checkPlaying(double bal) { // extra function
	char stillPlaying = '\0';
	
	while (stillPlaying != 'y' && stillPlaying != 'n') { // loops until user inputs the correct character
		printf("\nYour balance is currently $%.2f. Would you like to continue playing? Type 'y' for yes or 'n' for no:\n", bal);
		scanf("\n%c", &stillPlaying);

		if (stillPlaying != 'y' && stillPlaying != 'n') { // done if user doesn't input y or n
			printf("Please enter a character that is either 'y' or 'n'!\n");
		}
	}
	
	return stillPlaying;
}