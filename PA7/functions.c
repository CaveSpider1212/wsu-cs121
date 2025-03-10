/*
* Programmer: Aabhwan Adhikary
* Created: 11/13/2024
* Assignment: PA7
* Class: CptS 121, Fall 2024; Lab Section 19
* Description: This file contains all of the function declarations of the program.
*/

#include "Header.h"



/*
* Function name: printGameMenu()
* Programmer: Aabhwan Adhikary
* Description: Displays the rules of the game and asks player if they want to play a round
* Input parameters: character pointer "play" that will be passed into another function
* Returns: none
*/
void printGameMenu(char *play) {
	printf("Welcome to Poker! Here are the rules:\n\n");
	printf("Both players will be given 5 cards.\n");
	printf("Each player can choose to swap out up to 3 cards from their hand for better cards.\n");
	printf("The player with the stronger hand wins a point.\n");
	printf("If both players have the same hand strength, the player with the higher card wins.\n");
	printf("The player with the most points wins.\n\n");

	askToContinue(play);
}



/*
* Function name: askToContinue()
* Programmer: Aabhwan Adhikary
* Description: Asks player if they want to continue a round
* Input parameters: character pointer "play" that is an output variable representing whether the user wants to continue playing or not
* Returns: none
*/
void askToContinue(char *play) {
	printf("Do you want to play another round, or do you want to exit? (y/n)\n");
	scanf("\n%c", play);
}



/*
* Function name: askToReplaceCards()
* Programmer: Aabhwan Adhikary
* Description: Asks the user which cards from their hand they want to replace (they can replace up to 3).
* Input parameters: integer array "replace" that represents the values that the player will be replacing
* Returns: none
*/
void askToReplaceCards(int replace[5]) {
	int cardsReplaced = 0;

	for (int i = 0; i < 5; i++) {
		replace[i] = 0;
	}

	printf("Which cards do you want to replace? Type the number slot (starting from 1) of the card, and type 0 when finished. You can replace up to 3 cards.\n");
	int cardSlot = 0;
	do {
		scanf("%d", &cardSlot);
		if (cardSlot != 0 && (cardSlot > 5 || cardSlot < 1)) {
			printf("Invalid slot!\n");
		}
		else {
			if (cardSlot != 0) {
				replace[cardSlot - 1] = 1;
				cardsReplaced++;
			}
		}
	} while (cardSlot != 0 && cardsReplaced < 3);
}



/*
* Function name: resetDeckArray()
* Programmer: Aabhwan Adhikary
* Description: Resets the deck when the program reshuffles.
* Input parameters: integer array "wDeck" representing the game deck
* Returns: none
*/
void resetDeckArray(int wDeck[4][13]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			wDeck[i][j] = 0;
		}
	}
}



/*
* Function name: shuffle()
* Programmer: Aabhwan Adhikary
* Description: Shuffles the cards in the deck
* Input parameters: integer array "wDeck" representing the game deck
* Returns: none
*/
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4; // chooses a random suit
			column = rand() % 13; // chooses a random face value
		} while (wDeck[row][column] != 0); // keeps looping until program finds an empty deck slot for current card

		/* place card number in randomly chosen slot of deck */
		wDeck[row][column] = card;
	}
}



/*
* Function name: deal()
* Programmer: Aabhwan Adhikary
* Description: Deal the cards in the deck
* Input parameters: integer array "wDeck" representing the deck of cards; constant character arrays "wFace" and "wSuit" representing
*					the different face and suit values possible for the cards; integer pointer "currentCard" representing the current
*					card being drawn in the deck; Hand struct pointer "h" representing the hand the program is dealing to; integer
*					array "replace" representing the slots in the player's hand that the program will be drawing to
* Returns: none
*/
void deal(int wDeck[][13], const char* wFace[], const char* wSuit[], int *currentCard, Hand *h, int replace[5])
{
	int row = 0;    /* row number */
	int column = 0; /* column number */
	int card = *currentCard;   /* card counter */

	/* deals a fixed number of cards */
	for (int i = 0; i < 5; i++) {
		if (replace[i] == 1) {
			int handCardIndex = i; // index of the card slot that will be replaced

			for (row = 0; row <= 3; row++)
			{
				/* loop through columns of wDeck for current row */
				for (column = 0; column <= 12; column++)
				{
					/* if slot contains current card, display card */
					if (wDeck[row][column] == *currentCard)
					{
						// printf("%5s of %-8s%c", wFace[column], wSuit[row], *currentCard % 2 == 0 ? '\n' : '\t');
						h->cards[handCardIndex].faceValIndex = column, h->cards[handCardIndex].suitIndex = row;
						(*currentCard)++;
						column = 13, row = 4; // ends this loop and loop outside of it to prevent from drawing too many cards

						if (*currentCard > 52) { // reshuffle the deck once the current card is past the 52nd one
							resetDeckArray(wDeck);
							shuffle(wDeck);
							printf("Deck is being reshuffled.\n");
							*currentCard = 1;
						}
					}
				}
			}
		}
	}
}



/*
* Function name: printHand()
* Programmer: Aabhwan Adhikary
* Description: Prints a player's hand to the screen
* Input parameters: Hand struct pointer "h" representing the player's hand, where the program will access the Card struct's fields to
*					use in outputting; constant character arrays "wFace" and "wSuit" representing the different face and suit values
*					that could be printed to the screen
* Returns: none
*/
void printHand(Hand* h, const char* wFace[], const char* wSuit[]) {
	for (int i = 0; i < 5; i++) {
		printf("%5s of %-8s\n", wFace[h->cards[i].faceValIndex], wSuit[h->cards[i].suitIndex]);
	}
}



/*
* Function name: numberOfAKind()
* Programmer: Aabhwan Adhikary
* Description: Checks to see if a player's hand contains "number" of the same card
* Input parameters: Hand struct pointer "h" representing the hand the program is checking; integer "number" representing the count
*					of "checkingValue" in the player's hand; integer "checkingValue" represents the value that the program will be
*					checking and determine the count
* Returns: integer "hasNumberOfAKind" representing whether the program found "number" of "checkingValue" (1 for yes, 0 for no)
*/
int numberOfAKind(Hand *h, int number, int checkingValue) {
	int values = 0;
	int hasNumberOfAKind = 0;

	for (int i = 0; i < 5; i++) {
		values = 0;

		for (int j = 0; j < 5; j++) {
			if (h->cards[j].faceValIndex == checkingValue) {
				values++;
			}
		}

		if (values == number) {
			hasNumberOfAKind = 1;
			break;
		}
	}

	return hasNumberOfAKind;
}



/*
* Function name: sortFaceValues()
* Programmer: Aabhwan Adhikary
* Description: Sorts the face values of the player's hand
* Input parameters: integer array "sortedValues" represents the new sorted values of the player's hand; Hand struct pointer "h"
*					represents the player's hand whose face values will be sorted into another array
* Returns: none
*/
void sortFaceValues(int sortedValues[5], Hand *h) {
	for (int a = 0; a < 5; a++) { // sets each value in sortedValues array to the corresponding h.cards.faceValIndex value
		sortedValues[a] = h->cards[a].faceValIndex;
	}

	for (int i = 0; i < 5; i++) { // sorts the sortedValues array in descending order
		int currentFaceVal = sortedValues[i];
		int greatestValIndex = i;

		for (int j = i + 1; j < 5; j++) {
			if (sortedValues[j] > currentFaceVal) {
				greatestValIndex = j;
			}
		}

		int temp = sortedValues[i];
		sortedValues[i] = sortedValues[greatestValIndex];
		sortedValues[greatestValIndex] = temp;
	}
}



/*
* Function name: containsPair()
* Programmer: Aabhwan Adhikary
* Description: Checks if a player contains a pair of cards in their hand
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking
* Returns: integer "isPair" representing whether the program found a pair in the player's hand or not (1 for yes, 0 for no)
*/
int containsPair(Hand* h) {
	int isPair = 0;

	int i = 0;
	while (i < 5) {
		int checkingVal = h->cards[i].faceValIndex;
		if (numberOfAKind(h, 2, checkingVal)) {
			isPair = 1;
			break;
		}
		i++;
	}
	
	return isPair;
}



/*
* Function name: containsTwoPairs()
* Programmer: Aabhwan Adhikary
* Description: Checks if a player contains two pairs of cards in their hand
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking
* Returns: integer "isTwoPairs" representing whether the program found two pairs in the player's hand or not (1 for yes, 0 for no)
*/
int containsTwoPairs(Hand* h) {
	int isTwoPairs = 0;

	int i = 0;
	while (i < 5) {
		int checkingVal = h->cards[i].faceValIndex;
		if (numberOfAKind(h, 2, checkingVal)) {
			int remainingValues[3] = { 0 };
			int remainingValIndex = 0;

			for (int j = 0; j < 5; j++) {
				if (h->cards[j].faceValIndex != checkingVal) {
					remainingValues[remainingValIndex] = h->cards[j].faceValIndex;
					remainingValIndex++;
				}
			}

			if (remainingValues[0] == remainingValues[1] || remainingValues[0] == remainingValues[2] || remainingValues[1] == remainingValues[2]) {
				isTwoPairs = 1;
				break;
			}
		}
		i++;
	}

	return isTwoPairs;
}



/*
* Function name: containsThreeOfAKind()
* Programmer: Aabhwan Adhikary
* Description: Checks if a player contains three of a kind in their hand
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking
* Returns: integer "isTriple" representing whether the program found three of a kind in the player's hand or not (1 for yes, 0 for no)
*/
int containsThreeOfAKind(Hand* h) {
	int isTriple = 0;

	int i = 0;
	while (i < 5) {
		int checkingVal = h->cards[i].faceValIndex;
		if (numberOfAKind(h, 3, checkingVal)) {
			isTriple = 1;
			break;
		}
		i++;
	}

	return isTriple;
}



/*
* Function name: containsFourOfAKind()
* Programmer: Aabhwan Adhikary
* Description: Checks if a player contains four of a kind in their hand
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking
* Returns: integer "isQuadruple" representing whether the program found four of a kind in the player's hand or not (1 for yes, 0 for no)
*/
int containsFourOfAKind(Hand* h) {
	int isQuadruple = 0;

	int i = 0;
	while (i < 5) {
		int checkingVal = h->cards[i].faceValIndex;
		if (numberOfAKind(h, 4, checkingVal)) {
			isQuadruple = 1;
			break;
		}
		i++;
	}

	return isQuadruple;
}



/*
* Function name: containsFullHouse()
* Programmer: Aabhwan Adhikary
* Description: Checks if a player contains a full house in their hand
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking
* Returns: integer "isFullHouse" representing whether the program found a full house in the player's hand or not (1 for yes, 0 for no)
*/
int containsFullHouse(Hand* h) {
	int isFullHouse = 0;

	int i = 0;
	while (i < 5) {
		int checkingVal = h->cards[i].faceValIndex;
		if (numberOfAKind(h, 3, checkingVal)) { // first checks if there is 3 of a kind in the hand
			int remainingValues[2] = { 0 };
			int remainingValIndex = 0;

			for (int j = 0; j < 5; j++) { // if there is a 3 of a kind, then add the remaining values into another array
				if (h->cards[j].faceValIndex != checkingVal) {
					remainingValues[remainingValIndex] = h->cards[j].faceValIndex;
					remainingValIndex++;
				}
			}

			if (remainingValues[0] == remainingValues[1]) { // checks if the 2 remaining values are equal (making them a pair, and the whole thing a full house)
				isFullHouse = 1;
				break;
			}
		}
		i++;
	}

	return isFullHouse;
}



/*
* Function name: containsFlush()
* Programmer: Aabhwan Adhikary
* Description: Checks if a player contains a flush in their hand
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking
* Returns: integer "isFlush" representing whether the program found a flush in the player's hand or not (1 for yes, 0 for no)
*/
int containsFlush(Hand* h) {
	int isFlush = 1;
	int currentSuitIndex = h->cards[0].suitIndex;

	for (int i = 1; i < 5; i++) {
		if (h->cards[i].suitIndex != currentSuitIndex) { // if the suit is different from another suit, meaning no flush
			isFlush = 0;
		}
	}

	return isFlush;
}



/*
* Function name: containsStraight()
* Programmer: Aabhwan Adhikary
* Description: Checks if a player contains a straight in their hand
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking
* Returns: integer "isStraight" representing whether the program found a straight in the player's hand or not (1 for yes, 0 for no)
*/
int containsStraight(Hand* h) {
	int sortedFaceValues[5] = { 0 };
	sortFaceValues(sortedFaceValues, h);
	int isStraight = 1;

	for (int i = 1; i < 5; i++) {
		if (sortedFaceValues[i] != sortedFaceValues[i - 1] - 1) { // checks if the current value isn't 1 less than the previous, meaning not a straight
			isStraight = 0;
		}
	}

	return isStraight;
}



/*
* Function name: displayAvailableHands()
* Programmer: Aabhwan Adhikary
* Description: Displays the highest hand strength that the player currently has on the screen
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking to display the combination
* Returns: none
*/
void displayAvailableHands(Hand* h) {
	if (containsFourOfAKind(h)) {
		printf("Your hand contains four of a kind.\n");
	}
	else if (containsFullHouse(h)) {
		printf("Your hand contains a full house.\n");
	}
	else if (containsFlush(h)) {
		printf("Your hand contains a flush.\n");
	}
	else if (containsStraight(h)) {
		printf("Your hand contains a straight.\n");
	}
	else if (containsThreeOfAKind(h)) {
		printf("Your hand contains three of a kind.\n");
	}
	else if (containsTwoPairs(h)) {
		printf("Your hand contains two pairs.\n");
	}
	else if (containsPair(h)) {
		printf("Your hand contains a pair.\n");
	}
	else {
		printf("You don't have any combinations right now.\n");
	}
}



/*
* Function name: evaluateHands()
* Programmer: Aabhwan Adhikary
* Description: Evaluates both player's hands to determine who has the stronger hand (if both are the same, then check high card)
* Input parameters: Hand struct pointers "h1" and "h2" representing both of the players' hands that the program will be evaluating;
*					integer pointers "p1Score" and "p2Score" representing both of the players' scores that the program will be adding to
* Returns: none
*/
void evaluateHands(Hand* h1, Hand* h2, int *p1Score, int *p2Score) {
	int p1Combination = 0, p2Combination = 0;

	if (containsFourOfAKind(h1)) {
		p1Combination = 7;
	}
	else if (containsFullHouse(h1)) {
		p1Combination = 6;
	}
	else if (containsFlush(h1)) {
		p1Combination = 5;
	}
	else if (containsStraight(h1)) {
		p1Combination = 4;
	}
	else if (containsThreeOfAKind(h1)) {
		p1Combination = 3;
	}
	else if (containsTwoPairs(h1)) {
		p1Combination = 2;
	}
	else if (containsPair(h1)) {
		p1Combination = 1;
	}
	else {
		p1Combination = 0;
	}

	if (containsFourOfAKind(h2)) {
		p2Combination = 7;
	}
	else if (containsFullHouse(h2)) {
		p2Combination = 6;
	}
	else if (containsFlush(h2)) {
		p2Combination = 5;
	}
	else if (containsStraight(h2)) {
		p2Combination = 4;
	}
	else if (containsThreeOfAKind(h2)) {
		p2Combination = 3;
	}
	else if (containsTwoPairs(h2)) {
		p2Combination = 2;
	}
	else if (containsPair(h2)) {
		p2Combination = 1;
	}
	else {
		p2Combination = 0;
	}

	if (p1Combination > p2Combination) { // p1 wins
		printf("\nPlayer 1 has a stronger hand, so they earn the point!\n");
		(*p1Score)++;
	}
	else if (p1Combination < p2Combination) { // p2 wins
		printf("\nPlayer 2 has a stronger hand, so they earn the point!\n");
		(*p2Score)++;
	}
	else { // check high card
		int p1HighCard = findHighCard(h1), p2HighCard = findHighCard(h2);

		if (p1HighCard > p2HighCard) {
			printf("\nPlayer 1 has the higher high card, so they earn the point!\n");
			(*p1Score)++;
		}
		else if (p1HighCard < p2HighCard) {
			printf("\nPlayer 2 has the higher high card, so they earn the point!\n");
			(*p2Score)++;
		}
		else {
			printf("Both players had the same high card, so no one gets the point.\n");
		}
	}
}



/*
* Function name: findHighCard()
* Programmer: Aabhwan Adhikary
* Description: Finds the high card (highest face value) in a player's hand
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking
* Returns: integer "highCard" representing the high card in the player's hand
*/
int findHighCard(Hand* h) {
	int highCard = -1;

	for (int i = 0; i < 5; i++) {
		if (h->cards[i].faceValIndex > highCard) {
			highCard = h->cards[i].faceValIndex;
		}
	}

	return highCard;
}



/*
* Function name: simulateDealer()
* Programmer: Aabhwan Adhikary
* Description: Simulates the dealer, where the program judges if they should draw cards or not and how many the dealer should draw
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking; integer array "replace"
*					representing the slots that the dealer would be replacing or not replacing
* Returns: none
*/
void simulateDealer(Hand* h, int replace[5]) {
	if (!containsFlush(h) && !containsFourOfAKind(h) && !containsFullHouse(h) && !containsPair(h) && !containsStraight(h) && !containsThreeOfAKind(h) && !containsTwoPairs(h)) {
		for (int i = 0; i < 5; i++) {
			replace[i] = 0;
		}

		int mostCommonSuitIndex = -1;

		if (countSuits(h, &mostCommonSuitIndex) >= 3) {
			for (int j = 0; j < 5; j++) {
				if (h->cards[j].suitIndex != mostCommonSuitIndex) {
					replace[j] = 1;
				}
			}
		}
		else {
			findThreeLowest(h, replace);
		}
	}
}



/*
* Function name: countSuits()
* Programmer: Aabhwan Adhikary
* Description: Counts the number of each suit in the player's hand and returns the maximum count
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking; integer pointer
*					"mostCommonSuitIndex" representing the most common suit index found in the player's hand, which the program
*					will determine
* Returns: integer "maxCount" representing how many of the most common suit in the player's hand is there in the hand currently
*/
int countSuits(Hand* h, int *mostCommonSuitIndex) {
	int maxCount = 0;

	for (int i = 0; i < 5; i++) {
		int currentSuitIndex = h->cards[i].suitIndex;
		int count = 0;

		for (int j = i + 1; j < 5; j++) {
			if (h->cards[j].suitIndex == currentSuitIndex) {
				count++;
			}
		}

		if (count > maxCount) {
			maxCount = count;
			mostCommonSuitIndex = currentSuitIndex;
		}
	}

	return maxCount;
}



/*
* Function name: findThreeLowest()
* Programmer: Aabhwan Adhikary
* Description: Finds the 3 lowest values in the array, takes their indices, and modifies the "replace" array to replace the value
*				at those indices
* Input parameters: Hand struct pointer "h" representing the player's hand that the program will be checking; integer array "replace"
*					representing the slots of the player's hand that the program should replace
* Returns: none
*/
void findThreeLowest(Hand* h, int replace[5]) {
	for (int i = 1; i <= 3; i++) { // does this 3 times for 3 lowest values
		int lowestValIndex = -1, index = -1;

		for (int j = 0; j < 5; j++) { // loop through cards array
			if (h->cards[j].faceValIndex < lowestValIndex && replace[j] != 1) {
				lowestValIndex = h->cards[j].faceValIndex;
				index = j;
			}
		}

		replace[index] = 1;
	}
}