/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: PA 5
* Created: 10/11/24
* Description: This file contains all of the functions for the program.
*/

#include "Header.h"

/*
* Function name: gameMenu()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Prompts the user with options on whether to print the rules, start the game, or exit
* Input parameters: none
* Returns: choice on which option on the menu to choose (integer)
*/
int gameMenu(void) {
	int choice = 0;

	while (choice != 1 && choice != 2 && choice != 3) {
		printf("Please choose an option:\n1) Print game rules\n2) Start a game of Yahtzee\n3) Exit\n");
		scanf("%d", &choice);

		if (choice != 1 && choice != 2 && choice != 3) {
			printf("\nPlease choose one of the 3 options with their number!\n");
		}
	}

	system("cls");
	return choice;
}



/*
* Function name: printGameRules()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Displays the rules of the game to the user
* Input parameters: none
* Returns: none
*/
void printGameRules(void) {
	printf("YAHTZEE:\n");
	printf("Each player will roll 5 dice, and they can either choose if they want to select a combination right away or re-roll specific dice of their choice.\n");
	printf("There are 13 combinations for each player to choose from, and once a player chooses a combination, they can't choose it again for the remainder of the game.\n");
	printf("These combinations consist of upper section (sum of 1-6) or lower section (everything else besides \"chance\").\n");
	printf("Once a player rolls 3 times in the round, they must choose a combination.\n");
	printf("Player 2 will do the same thing, and this will continue for a total of 13 rounds (where both Player 1 and 2 play).\n");
	printf("After the 13th round, if a player got at least 63 points from the upper section alone, they will be awarded 35 bonus points.\n");
	printf("The player with the highest score wins.\n");
	printf("\n");
}



/*
* Function name: startGame()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Main method for the game (does all of the game functions)
* Input parameters: none
* Returns: none
*/
void startGame(void) {
	int playerNum = 1, roundNum = 1, p1Score = 0, p2Score = 0, p1UpperScore = 0, p2UpperScore = 0;
	int p1CombinationAvailability[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; // shows which one of player 1's combinations are available (1 means it is available)
	int p2CombinationAvailability[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; // shows which one of player 2's combinations are available (1 means it is available)

	printf("\n");

	while (roundNum < 14) {
		printf("ROUND %d - PLAYER %d's TURN\n", roundNum, playerNum);
		system("pause");

		char rollCombination = '\0'; // resets this when new player begins turn
		int rollDieNumbers[] = { 1, 1, 1, 1, 1 }; // array of 1's indicating which dice should be rolled (in this case, all of them)
		int diceValues[5]; // resets this array when new player begins turn...this is an array representing the values rolled on the die
		int numRolls = 0;

		while (numRolls < 3 && rollCombination != 'y') { // keeps looping for the player's turn until they hit 3 rolls for the turn or they select to roll for a combination
			for (int i = 0; i < 5; i++) { // roll the dice
				if (rollDieNumbers[i] == 1) { // checks if we are supposed to be rolling dice #(i+1)
					diceValues[i] = rollDie();
				}
				printf("Dice %d value: %d\n", (i + 1), diceValues[i]);
			}

			for (int j = 0; j < 5; j++) {
				rollDieNumbers[j] = 0; // sets all values in rollDieNumbers to 0, meaning the program will assume the player won't roll the die for the remainder of their turn unless they say otherwise
			}

			numRolls++;
			if (numRolls < 3) { // checks if the number of rolls is less than 3
				rollCombination = '\0'; // resets the roll combination decision by the user
				while (rollCombination != 'n' && rollCombination != 'y') { // keeps looping until user types 'n' or 'y' (basically loops if they type something other than that)
					printf("Do you want to roll for one of the game combinations? (y/n)\n");
					scanf("\n%c", &rollCombination);

					if (rollCombination == 'n') {
						printf("Which dice or die would you like to reroll? Enter numbers from 1-5 (each on a new line), and type -1 when finished.\n");
						int rerollDie = 0;

						while (rerollDie != -1) { // keeps looping until user enters -1
							scanf("%d", &rerollDie);
							if (rerollDie != -1 && (rerollDie < 1 || rerollDie > 5)) {
								printf("Choose a number from 1-5.\n");
							}
							else {
								rollDieNumbers[rerollDie - 1] = 1; // changes the corresponding index in the dice number rerolls array to 1, indicating it should be rerolled
							}
						}
					}
					else if (rollCombination == 'y') {
						selectCombination(diceValues, p1CombinationAvailability, p2CombinationAvailability, playerNum, &p1Score, &p2Score, &p1UpperScore, &p2UpperScore);
					}
					else {
						printf("You need to type either 'y' or 'n'!\n");
					}
				}
			}
			else {
				selectCombination(diceValues, p1CombinationAvailability, p2CombinationAvailability, playerNum, &p1Score, &p2Score, &p1UpperScore, &p2UpperScore);
			}
		}

		if (playerNum == 2) {
			roundNum++;
		}

		switchPlayer(&playerNum);
		system("cls");
		displayScores(p1Score, p2Score);
		displayUpperScores(p1UpperScore, p2UpperScore);
	}

	giveBonus(p1UpperScore, p2UpperScore, &p1Score, &p2Score);
	displayWinner(p1Score, p2Score);
}



/*
* Function name: rollDie()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Generates a random number from 1-6, and returns it
* Input parameters: none
* Returns: random number from 1-6 (integer)
*/
int rollDie(void) {
	int value = rand() % 6 + 1; // random number from 1 to 6
	return value;
}



/*
* Function name: switchPlayer()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Switches the player number value (if it's 1, switch to 2, otherwise switch to 1)
* Input parameters: integer pointer of a player number value representing which player is currently playing, and switches the value
* Returns: none
*/
void switchPlayer(int* player) {
	if (*player == 1) {
		*player = 2;
	}
	else {
		*player = 1;
	}
}



/*
* Function name: displayScores()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Displays the total scores of both of the players
* Input parameters: 2 integer parameters representing the scores of players 1 and 2 that will be printed
* Returns: none
*/
void displayScores(int p1Score, int p2Score) {
	printf("PLAYER 1 SCORE: %d\n", p1Score);
	printf("PLAYER 2 SCORE: %d\n", p2Score);
	printf("\n");
}



/*
* Function name: displayUpper()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Displays the total upper section scores of both of the players
* Input parameters: 2 integer parameters representing the upper section scores of players 1 and 2 that will be printed
* Returns: none
*/
void displayUpperScores(int p1Upper, int p2Upper) {
	printf("PLAYER 1 UPPER SECTION SCORE: %d\n", p1Upper);
	printf("PLAYER 2 UPPER SECTION SCORE: %d\n", p2Upper);
	printf("\n");
}



/*
* Function name: displayCombinations()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Displays the available combinations available to the player along with their scores based on which player is playing
* Input parameters: "values" array used to show scores from each combination; playerNum used to display the combinations
*					available to that specific player; *p1Available and *p2Available used to display which combinations are available
* Returns: none
*/
void displayCombinations(int values[], int playerNum, int *p1Available[], int *p2Available[]) {
	printf("\nPlease select one of the combinations below by entering the number if it is available (1-13):\n");

	if (playerNum == 1) {
		checkForAvailableCombinations(p1Available, values);
	}
	else {
		checkForAvailableCombinations(p2Available, values);
	}
}



/*
* Function name: calculateScore()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Calculates the score based on the selected combination number
* Input parameters: "values" array is used for scoring; compNumber used to select which one to score; playerNu, *p1Upper, and *p2Upper
*					used to give the upper section points to the current player; calculateUpper used to see if we're actually calculating
*					the upper section score at the time
* Returns: calculated score to add to the player's score (integer)
*/
int calculateScore(int values[], int compNumber, int playerNum, char calculateUpper, int *p1Upper, int *p2Upper) {
	int score = 0;

	if (compNumber == 1) { // Sum of 1's
		for (int i = 0; i < 5; i++) {
			if (values[i] == 1) {
				score += 1;

				addUpperScore(calculateUpper, playerNum, 1, p1Upper, p2Upper);
			}
		}
	}
	else if (compNumber == 2) { // Sum of 2's
		for (int i = 0; i < 5; i++) {
			if (values[i] == 2) {
				score += 2;

				addUpperScore(calculateUpper, playerNum, 2, p1Upper, p2Upper);
			}
		}
	}
	else if (compNumber == 3) { // Sum of 3's
		for (int i = 0; i < 5; i++) {
			if (values[i] == 3) {
				score += 3;

				addUpperScore(calculateUpper, playerNum, 3, p1Upper, p2Upper);
			}
		}
	}
	else if (compNumber == 4) { // Sum of 4's
		for (int i = 0; i < 5; i++) {
			if (values[i] == 4) {
				score += 4;

				addUpperScore(calculateUpper, playerNum, 4, p1Upper, p2Upper);
			}
		}
	}
	else if (compNumber == 5) { // Sum of 5's
		for (int i = 0; i < 5; i++) {
			if (values[i] == 5) {
				score += 5;

				addUpperScore(calculateUpper, playerNum, 5, p1Upper, p2Upper);
			}
		}
	}
	else if (compNumber == 6) { // Sum of 6's
		for (int i = 0; i < 5; i++) {
			if (values[i] == 6) {
				score += 6;

				addUpperScore(calculateUpper, playerNum, 6, p1Upper, p2Upper);
			}
		}
	}
	else if (compNumber == 7) { // Three of a kind
		int tripleValue = 0; // pointer used to fill in the pointer argument in numberOfAKind()
		if (numberOfAKind(3, values, &tripleValue)) {
			score += sumDiceValues(values);
		}
	}
	else if (compNumber == 8) { // Four of a kind
		int quadrupleValue = 0; // pointer used to fill in the pointer argument in numberOfAKind()
		if (numberOfAKind(4, values, &quadrupleValue)) {
			score += sumDiceValues(values);
		}
	}
	else if (compNumber == 9) { // Full House
		int tripleValue = 0; // variable representing the number that is the three-of-a-kind
		if (numberOfAKind(3, values, &tripleValue)) { // checks if there is actually a three-of-a-kind in the array
			int remainingPair[] = { 0, 0 };
			for (int i = 0; i < 5; i++) {
				if (values[i] != tripleValue) { // checks if the current value is different from the three-of-a-kind number
					if (remainingPair[0] != 0) { // checks if there already has been a value placed in the first spot of remainingPair
						remainingPair[1] = values[i];
					}
					else {
						remainingPair[0] = values[i];
					}
				}
			}

			if (remainingPair[0] == remainingPair[1]) { // checks if the two values in the remaining pair are equal, which would make it a full house (otherwise no)
				score += 25;
			}
		}
	}
	else if (compNumber == 10) { // Small straight
		int uniqueValues[] = { 0, 0, 0, 0, 0 };
		findUniques(values, uniqueValues);
		sortArray(uniqueValues); // sorts the uniqueValues array in ascending order

		if (countZeroes(uniqueValues, 5) <= 1) { // checks if there are less than or equal to one 0 in the uniqueValues array, meaning it might be a small straight (otherwise it isn't)
			if (checkStraight(uniqueValues, 's')) {
				score += 30;
			}
		}
	}
	else if (compNumber == 11) { // Large straight
		int uniqueValues[] = { 0, 0, 0, 0, 0 };
		findUniques(values, uniqueValues);
		sortArray(uniqueValues);

		if (countZeroes(uniqueValues, 5) == 0) { // checks if there are no 0's in the uniqueValues array, meaning it might be a large straight (otherwise it isn't)
			if (checkStraight(uniqueValues, 'l')) {
				score += 40;
			}
		}
	}
	else if (compNumber == 12) { // Yahtzee (Five of a kind)
		int quintupleValue = 0; // pointer used to fill in the pointer argument in numberOfAKind()
		if (numberOfAKind(5, values, &quintupleValue)) {
			score += 50;
		}
	}
	else { // Chance
		score += sumDiceValues(values);
	}

	return score;
}



/*
* Function name: addUpperScore()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Adds the score to the current player if we are actually supposed to be calculating it
* Input parameters: calculateUpper used to determine if we are actually supposed to be calculating the upper section score; playerNum,
*					score, *p1Upper, *p2Upper used to add the score value to the current player's upper section score
* Returns: none
*/
void addUpperScore(char calculateUpper, int playerNum, int score, int* p1Upper, int* p2Upper) {
	if (calculateUpper == 'y') {
		if (playerNum == 1) {
			*p1Upper += score;
		}
		if (playerNum == 2) {
			*p2Upper += score;
		}
	}
}



/*
* Function name: sumDiceValues()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Takes the sum of all of the values in the "values" array and returns it
* Input parameters: "values" array represents all of the dice values rolled, where all of the elements will be added up
* Returns: Sum of all the values in the "values" array (integer)
*/
int sumDiceValues(int values[]) {
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		sum += values[i];
	}

	return sum;
}



/*
* Function name: numberOfAKind()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Checks if the "values" array has "number" of a kind
* Input parameters: "number" represents how many of a kind the program should look for in the "values" array; *currentValue represents
*					the exact number that has "number" of a kind
* Returns: hasNumberOfKind, which represents whether the "values" array actually has "number" of a kind (integer)
*/
int numberOfAKind(int number, int values[], int *currentValue) { // full house keeps freezing here
	int hasNumberOfAKind = 0;

	for (int i = 0; i < 5; i++) {
		int count = 1;
		*currentValue = values[i]; // will compare other values in array to this value

		for (int j = i + 1; j < 5; j++) {
			if (values[j] == *currentValue) {
				count++;

				if (count == number) { // checks if the program has counted the exact number of instances as the requested number in the parameters
					hasNumberOfAKind = 1;
					i = 5, j = 5; // ends both loops
				}
			}
		}
	}

	return hasNumberOfAKind;
}



/*
* Function name: findUniques()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Finds all unique values in the "values" array and stores them in the "uniqueValues" array
* Input parameters: *values represents the array of dice values rolled; *uniqueValues represents the array where the unique values rolled
*					will be stored
* Returns: none
*/
void findUniques(int* values, int* uniqueValues) {
	int uniqueValuesIndex = 0;
	for (int i = 0; i < 5; i++) {
		int j = 0;
		while (j < 4) { // iterate through the uniqueValues array to check if the current entry in values is in that array (if it isn't, add that value to uniqueValues)
			if (values[i] == uniqueValues[j]) { // checks if the current entry for "values" is already in uniqueValues...if it is, then end the inner loop and go the next number in "values"
				break;
			}
			j++;
		}

		if (j == 4) { // done if the program made it through the entire while loop (meaning it didn't find the current value already in uniqueValues)
			uniqueValues[uniqueValuesIndex] = values[i];
			uniqueValuesIndex++; // now the program will update uniqueValues at its next index
		}
	}
}



/*
* Function name: sortArray()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Sorts an array using a selection sort algorithm
* Input parameters: *arr, representing the array that will be sorted
* Returns: none
*/
void sortArray(int* arr) {
	for (int i = 0; i < 5; i++) {
		int smallest = arr[i];
		int smallestIndex = i;

		for (int j = i + 1; j < 5; j++) { // loops thorugh array for the smallest value
			if (arr[j] < smallest) {
				smallest = arr[j]; // this is the smallest value in the array
				smallestIndex = j; // this is the smallest value's index
			}
		}

		// replaces current value in array with smallest value
		int temp = arr[i];
		arr[i] = smallest;
		arr[smallestIndex] = temp;
	}
}



/*
* Function name: checkStraight()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Checks if *arr has a straight based on the "combination" value (small or large straight)
* Input parameters: *arr, representing the array where the straight will be checked (integer pointer); "combination" represents 
					exactly which combination the program should be looking for (char)
* Returns: isAStraight, representing whether *arr is actually a straight (small or large) (integer)
*/
int checkStraight(int* arr, char combination) {
	int isAStraight = 1;
	int straights = 1;
	int i = 1;

	while (i < 5) {
		if (arr[i] == 0 || arr[i - 1] == 0) {
			i++; // ignores the 0 if it is encountered in the array
		}

		if (arr[i] != arr[i - 1] + 1) { // if the current element isn't equal to the previous element plus one (meaning it isn't a straight)
			if ((combination == 's' && straights != 4) || (combination == 'l' && straights != 5)) {
				isAStraight = 0; // if we're looking for a small straight or large straight but it doesn't have enough straight values, then it isn't a straight
			}
		}
		else {
			straights++;
		}
		i++;
	}

	return isAStraight;
}



/*
* Function name: countZeroes()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Counts the number of zeroes in the array
* Input parameters: *arr and size represent the array and size used for looping through
* Returns: Number of zeroes in the array (integer)
*/
int countZeroes(int *arr, int size) {
	int zeroes = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] == 0) {
			zeroes++;
		}
	}

	return zeroes;
}



/*
* Function name: selectCombination()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Displays the combinations and prompts the user to select one, and verifies whether that combination is available to the player
* Input parameters: "values" represent the dice values the player rolled; *p1Availability and *p2Availability represent which combinations
*					are available to the current player, playerNum; *p1Score, *p2Score, *p1Upper, *p2Upper represent the scores and upper
*					section scores of both of the players
* Returns: none
*/
void selectCombination(int values[], int* p1Availability, int *p2Availability, int playerNum, int *p1Score, int *p2Score, int *p1Upper, int *p2Upper) {
	int combinationNumber = 0; // represents the number of the combination that the player wants to select
	int combinationSelected = 0; // variable representing whether a combination was selected or not, set to "not selected" by default

	while (combinationSelected != 1) { // keeps looping until the player selects a valid combination
		displayCombinations(values, playerNum, p1Availability, p2Availability);
		scanf("%d", &combinationNumber);

		if (combinationNumber < 1 || combinationNumber > 13) {
			printf("Please enter a number out of the combination!\n");
		}
		else {
			if (!verifyCombinationAvailability(p1Availability, p2Availability, combinationNumber, playerNum)) { // if the combination is not available
				printf("Player %d has already selected this combination previously. Please choose another one.\n", playerNum);
			}
			else { // if the combination is available, updates the current player's score
				combinationSelected = 1; // indicates that a combination has now been selected

				if (playerNum == 1) { // if it's player 1's turn
					*p1Score += calculateScore(values, combinationNumber, 1, 'y', p1Upper, p2Upper);
				}
				else { // if it's player 2's turn
					*p2Score += calculateScore(values, combinationNumber, 2, 'y', p1Upper, p2Upper);
				}
			}
		}
	}
}



/*
* Function name: verifyCombinationAvailability()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Checks if the combination selected by the player is actually available or not
* Input parameters: *p1Availability and *p2Availability represents an array of the combinations available to both players; "number" is
*					an integer representing which combination was selected by the current player, playerNum
* Returns: isAvailable, representing whether the combination is actually availabe or not (integer)
*/
int verifyCombinationAvailability(int* p1Availability, int *p2Availability, int number, int playerNum) {
	int isAvailable = 1;

	if (playerNum == 1) { // if it's player 1's turn
		int selectedCombination = p1Availability[number - 1];
		if (selectedCombination == 0) { // checks if the selected combination is not available
			isAvailable = 0; // this means that the combination is not available
		}
		else {
			p1Availability[number - 1] = 0; // combination is available now, but won't be after this
		}
	}
	else { // if it's player 2's turn
		int selectedCombination = p2Availability[number - 1];
		if (selectedCombination == 0) { // checks if the selected combination is not available
			isAvailable = 0; // this means that the combination is not available
		}
		else {
			p2Availability[number - 1] = 0; // combination is available now, but won't be after this
		}
	}

	return isAvailable;
}



/*
* Function name: checkForAvailableCombinations()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Displays the combinations to the current player that are currently available to them
* Input parameters: "array" represents the array of available combinations of the current player; "values" represents the dice values rolled
* Returns: none
*/
void checkForAvailableCombinations(int array[], int values[]) { // ERROR ---- SOME OF THEM RANDOMLY DISAPPEAR EVEN IF WE DIDN'T SELECT THEM (AND SOME APPEAR EVEN WHEN WE DO SELECT THEM)
	int ptr = 0; // created to fill in pointer space in calculateScore methods used later

	if (array[0] == 1) {
		printf("1) Sum of 1's (Score: %d)\n", calculateScore(values, 1, 0, 'n', &ptr, &ptr));
	}
	if (array[1] == 1) {
		printf("2) Sum of 2's (Score: %d)\n", calculateScore(values, 2, 0, 'n', &ptr, &ptr));
	}
	if (array[2] == 1) {
		printf("3) Sum of 3's (Score %d)\n", calculateScore(values, 3, 0, 'n', &ptr, &ptr));
	}
	if (array[3] == 1) {
		printf("4) Sum of 4's (Score: %d)\n", calculateScore(values, 4, 0, 'n', &ptr, &ptr));
	}
	if (array[4] == 1) {
		printf("5) Sum of 5's (Score: %d)\n", calculateScore(values, 5, 0, 'n', &ptr, &ptr));
	}
	if (array[5] == 1) {
		printf("6) Sum of 6's (Score: %d)\n", calculateScore(values, 6, 0, 'n', &ptr, &ptr));
	}
	if (array[6] == 1) {
		printf("7) Three-of-a-kind (Score: %d)\n", calculateScore(values, 7, 0, 'n', &ptr, &ptr));
	}
	if (array[7] == 1) {
		printf("8) Four-of-a-kind (Score: %d)\n", calculateScore(values, 8, 0, 'n', &ptr, &ptr));
	}
	if (array[8] == 1) {
		printf("9) Full house (Score: %d)\n", calculateScore(values, 9, 0, 'n', &ptr, &ptr));
	}
	if (array[9] == 1) {
		printf("10) Small straight (Score: %d)\n", calculateScore(values, 10, 0, 'n', &ptr, &ptr));
	}
	if (array[10] == 1) {
		printf("11) Large straight (Score: %d)\n", calculateScore(values, 11, 0, 'n', &ptr, &ptr));
	}
	if (array[11] == 1) {
		printf("12) Yahtzee (Score: %d)\n", calculateScore(values, 12, 0, 'n', &ptr, &ptr));
	}
	if (array[12] == 1) {
		printf("13) Chance (Score: %d)\n", calculateScore(values, 13, 0, 'n', &ptr, &ptr));
	}
}



/*
* Function name: giveBonus()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Gives 35 bonus points to a player if they have an upper section score of at least 63
* Input parameters: p1Upper and p2Upper represent the upper section scores of both players; *p1Score and *p2Score represent the scores
*					of players 1 and 2, where the bonus points will be added
* Returns: none
*/
void giveBonus(int p1Upper, int p2Upper, int* p1Score, int* p2Score) {
	if (p1Upper >= 63) {
		*p1Score += 35;
		printf("35 bonus points have been added to Player 1's score since they had an upper section score of at least 63 points.\n");
	}
	if (p2Upper >= 63) {
		*p2Score += 35;
		printf("35 bonus points have been added to Player 2's score since they had an upper section score of at least 63 points.\n");
	}
}



/*
* Function name: displayWinner()
* Date created: 10/24/2024
* Programmer: Aabhwan Adhikary
* Description: Displays the winner of the game based on which score is higher
* Input parameters: p1Score and p2Score are the scores of both of the players, which will be compared to determine the winner
* Returns: none
*/
void displayWinner(int p1Score, int p2Score) {
	if (p1Score > p2Score) {
		printf("Player 1 wins!\n\n");
	}
	else if (p1Score < p2Score) {
		printf("Player 2 wins!\n\n");
	}
	else {
		printf("Player 1 and player 2 tie!\n\n");
	}
}