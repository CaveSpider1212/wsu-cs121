/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: PA 6
* Created: 10/28/24
* Description: This file contains all of the function declarations of the program.
*/

#include "Header.h"




/*
* Function name: startGame()
* Programmer: Aabhwan Adhikary
* Description: Runs the game of Battleship
* Input parameters: 2 pointers to Player and Stat structs each representing each player's data and stats, and pointer to file representing output file
* Returns: none
*/
void startGame(Player *p1, Player *p2, Stats *s1, Stats *s2, FILE* dataFile) {
	int playerNum = 0;

	welcomeScreen();
	initializeGameBoard(p1, p2);
	initalizeShips(p1, p2);
	initializeStats(s1, s2);

	printf("Do you want to...\n1) Manually place your ships\n2) Have them randomly placed\n(type 1 or 2)\n");
	int playerChoice = 0;
	scanf("%d", &playerChoice);

	// for the player
	setVisibleBoard(p1);
	if (playerChoice == 1) {
		manuallyPlaceShipsOnBoard(p1);
	}
	else {
		randomlyPlaceShipsOnBoard(p1);
	}
	
	// for the computer
	setVisibleBoard(p2);
	randomlyPlaceShipsOnBoard(p2);

	system("cls");

	p1->shipsRemaining = 5, p2->shipsRemaining = 5;

	playerNum = selectWhoStartsFirst();
	
	while (!isWinner(p1, p2, s1, s2)) { // continues as long as there isn't a winner
		printf("Player 1's board:\n");
		displayBoard(p1);

		printf("\nPlayer 2's board:\n");
		displayBoard(p2);

		int xGuess = 0, yGuess = 0, shotHit = -1;

		if (playerNum == 1) { // if it's the player's turn
			printf("\nIt's your turn. Enter the coordinates you would like to aim at separated by spaces.\n");
			scanf("%d %d", &xGuess, &yGuess);
			
			while (shotHit == -1) {
				checkShot(p2, s1, &shotHit, xGuess, yGuess);
				
				if (shotHit == -1) { // if the player guessed a spot they already guessed, then guess again
					printf("Invalid guess!\n");
					scanf("%d %d", &xGuess, &yGuess);
				}
				else {
					updateBoard(p2, shotHit, xGuess, yGuess);
					outputCurrentMove(dataFile, playerNum, xGuess, yGuess, shotHit);
					checkIfSunkShip(p2);
				}
			}
		}
		else { // if it's the computer's turn
			printf("\nIt's the computer's turn. They will guess randomly.\n");
			int xGuess = rand() % 10, yGuess = rand() % 10;

			while (shotHit == -1) {
				checkShot(p1, s2, &shotHit, xGuess, yGuess);
				
				if (shotHit != -1) { // if the computer hit a location it hasn't hit before
					updateBoard(p1, shotHit, xGuess, yGuess);
					outputCurrentMove(dataFile, playerNum, xGuess, yGuess, shotHit);
					checkIfSunkShip(p1);
				}
				else { // computer guesses again
					xGuess = rand() % 10, yGuess = rand() % 10;
				}
			}
		}

		switchPlayers(&playerNum);
		system("pause");
		system("cls");
	}
}




/*
* Function name: welcomeScreen()
* Programmer: Aabhwan Adhikary
* Description: Displays the rules of the game
* Input parameters: none
* Returns: none
*/
void welcomeScreen(void) {
	printf("Welcome to Battleship!\n\n");
	printf("Rules:\n");
	printf("The players will either place their 5 ships themselves or have the program randomly place it for them.\n");
	printf("Each player will guess a coordinate on the opposing player's board.\n");
	printf("The program will show if the guess hit or missed one of the opposing player's ships.\n");
	printf("If a player hits all of the parts of the opposing player's ships, the ship will sink.\n");
	printf("The first player to sink all 5 of the opponent's ships wins the game.\n\n");
}



/*
* Function name: initializeGameBoard()
* Programmer: Aabhwan Adhikary
* Description: Sets all cells in both players' game boards to '-'
* Input parameters: Pointers to both Player structs to access their gameBoard 2D array
* Returns: none
*/
void initializeGameBoard(Player *p1, Player *p2) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			p1->gameBoard[i][j] = '-';
			p2->gameBoard[i][j] = '-';
		}
	}
}




/*
* Function name: initializeShips()
* Programmer: Aabhwan Adhikary
* Description: Sets each of the ships cells to -1 (meaning they haven't been placed yet), and initializes other ship values
* Input parameters: Pointers to both Player structs to access their ships, whose values will be accessed
* Returns: none
*/
void initalizeShips(Player* p1, Player* p2) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			p1->carrier.cells[i][j] = -1, p2->carrier.cells[i][j] = -1;
			p1->battleship.cells[i][j] = -1, p2->battleship.cells[i][j] = -1;
			p1->cruiser.cells[i][j] = -1, p2->cruiser.cells[i][j] = -1;
			p1->submarine.cells[i][j] = -1, p2->submarine.cells[i][j] = -1;
			p1->destroyer.cells[i][j] = -1, p2->destroyer.cells[i][j] = -1;
		}
	}

	p1->carrier.size = 5, p1->carrier.sunk = 0;
	p1->battleship.size = 4, p1->battleship.sunk = 0;
	p1->cruiser.size = 3, p1->cruiser.sunk = 0;
	p1->submarine.size = 3, p1->submarine.sunk = 0;
	p1->destroyer.size = 2, p1->destroyer.sunk = 0;

	p2->carrier.size = 5, p2->carrier.sunk = 0;
	p2->battleship.size = 4, p2->battleship.sunk = 0;
	p2->cruiser.size = 3, p2->cruiser.sunk = 0;
	p2->submarine.size = 3, p2->submarine.sunk = 0;
	p2->destroyer.size = 2, p2->destroyer.sunk = 0;
}




/*
* Function name: initializeStats()
* Programmer: Aabhwan Adhikary
* Description: Resets all of the stat values
* Input parameters: Pointers to both player's Stats structs that allows for access to the values
* Returns: none
*/
void initializeStats(Stats *s1, Stats *s2) {
	s1->hits = 0, s1->misses = 0, s1->shots = 0, s1->ratio = 0, s1->won = 0;
	s2->hits = 0, s2->misses = 0, s2->shots = 0, s2->ratio = 0, s2->won = 0;
}




/*
* Function name: selectWhoStartsFirst()
* Programmer: Aabhwan Adhikary
* Description: Generates random number between 1 and 2, representing which player starts first
* Input parameters: none
* Returns: Random number between 1 and 2, representing which player starts first
*/
int selectWhoStartsFirst(void) {
	int playerStart = rand() % 2 + 1;
	return playerStart;
}




/*
* Function name: switchPlayers()
* Programmer: Aabhwan Adhikary
* Description: Switches the current player of the game
* Input parameters: Pointer that would change the variable's value to 1 or 2 depending on the current player
* Returns: none
*/
void switchPlayers(int* p) {
	if (*p == 1) {
		*p = 2;
	}
	else {
		*p = 1;
	}
}




/*
* Function name: manuallyPlaceShipsOnBoard()
* Programmer: Aabhwan Adhikary
* Description: Controls the player's manual placing of ships
* Input parameters: Pointer to a player's struct that will be passed to other functions to place the ship
* Returns: none
*/
void manuallyPlaceShipsOnBoard(Player *p) {
	int allShipsPlaced = 0;
	int shipNumber = 1;
	
	while (!allShipsPlaced) {
		char orientation = '\0', ship = '\0';
		int goodPlacement = 0, x = 0, y = 0;

		displayBoard(p);

		if (shipNumber == 1) {
			printf("Please place the carrier ship first. Would you like to place it vertically or horizontally? Type 'v' or 'h'\n");
			ship = 'c';
		}
		else if (shipNumber == 2) {
			printf("Please place the battleship next. Would you like to place it vertically or horizontally? Type 'v' or 'h'\n");
			ship = 'b';
		}
		else if (shipNumber == 3) {
			printf("Please place the cruiser. Would you like to place it vertically or horizontally? Type 'v' or 'h'\n");
			ship = 'r';
		}
		else if (shipNumber == 4) {
			printf("Please place the submarine. Would you like to place it vertically or horizontally? Type 'v' or 'h'\n");
			ship = 's';
		}
		else {
			printf("Please place the destroyer. Would you like to place it vertically or horizontally? Type 'v' or 'h'\n");
			ship = 'd';
		}
		scanf("\n%c", &orientation);

		while (!goodPlacement) {
			if (orientation == 'v') {
				printf("Where do you want the top-most side of the ship to be? Please enter the x- and y-coordinates separated by spaces. Rows and columns start from 0.\n");
			}
			else {
				printf("Where do you want the left-most side of the ship to be? Please enter the x- and y-coordinates separated by spaces. Rows and columns start from 0.\n");
			}
			scanf("%d %d", &x, &y);

			goodPlacement = verifyShip(orientation, ship, x, y, p);
			if (goodPlacement) {
				placeShip(orientation, ship, x, y, p);
			}
			else {
				printf("Invalid placement!\n");
			}
		}

		if (shipNumber == 5) { // this means all ships have been placed
			allShipsPlaced = 1;
		}
		else {
			shipNumber++;
		}
	}
}




/*
* Function name: verifyShip()
* Programmer: Aabhwan Adhikary
* Description: Verifies that the ship placement is good (in bounds, not conflicting with other ships)
* Input parameters: orientation (char) representing the desired orientation (vertical or horizontal); ship (char) representing the ship being placed; x and y (ints) representing
*					the coordinates; Pointer to Player struct representing the player where the board would be checked
* Returns: integer representing if the ship placement is good (1) or not (0)
*/
int verifyShip(char orientation, char ship, int x, int y, Player *p) {
	int goodPlacement = 1; // variable representing whether the placement of the ship is good or not
	int spaces = 0;

	switch (ship) {
		case 'c':
			spaces = 5;
			break;
		case 'b':
			spaces = 4;
			break;
		case 'r':
			spaces = 3;
			break;
		case 's':
			spaces = 3;
			break;
		default:
			spaces = 2;
			break;
	}

	if (x < 0 || x > 9) { // if the x-coordinate is out of bounds
		goodPlacement = 0;
	}
	else { // if the x-coordinate is good
		if (y < 0 || y > 9) { // if the y-coordinate is out of bounds
			goodPlacement = 0;
		}
		else { // if the y-coordinate is good
			if (orientation == 'v') { // checks if bottom y-coordinate is out of bounds depending on the ship
				if (y + spaces > 10) {
					goodPlacement = 0;
				}
			}
			else { // (horizontal) checks if right x-coordinate is out of bounds depending on the ship
				if (x + spaces > 10) {
					goodPlacement = 0;
				}
			}
		}
	}

	// checks if a ship is already in the spot
	if (orientation == 'v') {
		for (int i = y; i < y + spaces; i++) {
			if (p->gameBoard[i][x] != '-') {
				goodPlacement = 0;
			}
		}
	}
	else {
		for (int j = x; j < x + spaces; j++) {
			if (p->gameBoard[y][j] != '-') {
				goodPlacement = 0;
			}
		}
	}


	return goodPlacement;
}




/*
* Function name: placeShips()
* Programmer: Aabhwan Adhikary
* Description: Places the ship into the corresponding board squares
* Input parameters: orientation (char) representing the orientation of the ship (vertical or horizontal); ship (char) representing the ship being placed; x and y (ints) representing
*					the positions of the ship; Pointer to a Player struct representing the player whose board the ship will be placed on
* Returns: none
*/
void placeShip(char orientation, char ship, int x, int y, Player *p) {
	int spaces = 0;
	int starting = 0;

	int shipCellsRow = 0;
	
	switch (ship) {
	case 'c':
		spaces = 5;
		break;
	case 'b':
		spaces = 4;
		break;
	case 'r':
		spaces = 3;
		break;
	case 's':
		spaces = 3;
		break;
	default:
		spaces = 2;
		break;
	}

	if (orientation == 'v') { // place ships vertically
		for (int i = y; i < y + spaces; i++) {
			p->gameBoard[i][x] = ship;

			// BELOW SETS THE SHIP CELLS IN THE SHIPS STRUCTURE
			setShipCells(p, ship, &shipCellsRow, x, i);
		}
	}
	else { // place ships horizontally
		for (int j = x; j < x + spaces; j++) {
			p->gameBoard[y][j] = ship;

			// BELOW SETS THE SHIP CELLS IN THE SHIPS ARRAY
			setShipCells(p, ship, &shipCellsRow, j, y);
		}
	}

	setVisibleBoard(p);
}




/*
* Function name: setShipCells()
* Programmer: Aabhwan Adhikary
* Description: Sets the cells of a ship to the given x and y coordinates
* Input parameters: Pointer to a Player struct whose ships' cells will be accessed; ship (char) represents the ship being placed;
*					Pointer to an integer representing the row in the 2D array of cells to modify; x and y (ints) represent the coordinates
* Returns: none
*/
void setShipCells(Player* p, char ship, int* row, int x, int y) {
	int shipCellsColumn = 0;
	while (shipCellsColumn < 2) {
		if (shipCellsColumn == 0) {
			if (ship == 'c') {
				p->carrier.cells[*row][shipCellsColumn] = x;
			}
			else if (ship == 'b') {
				p->battleship.cells[*row][shipCellsColumn] = x;
			}
			else if (ship == 'r') {
				p->cruiser.cells[*row][shipCellsColumn] = x;
			}
			else if (ship == 's') {
				p->submarine.cells[*row][shipCellsColumn] = x;
			}
			else {
				p->destroyer.cells[*row][shipCellsColumn] = x;
			}
		}
		else {
			if (ship == 'c') {
				p->carrier.cells[*row][shipCellsColumn] = y;
			}
			else if (ship == 'b') {
				p->battleship.cells[*row][shipCellsColumn] = y;
			}
			else if (ship == 'r') {
				p->cruiser.cells[*row][shipCellsColumn] = y;
			}
			else if (ship == 's') {
				p->submarine.cells[*row][shipCellsColumn] = y;
			}
			else {
				p->destroyer.cells[*row][shipCellsColumn] = y;
			}
		}

		shipCellsColumn++;
	}

	(*row)++;
}




/*
* Function name: setVisibleBoard()
* Programmer: Aabhwan Adhikary
* Description: Sets each player's visible board that would be displayed to the user (ships for Player 1, dashes for Player 2)
* Input parameters: Pointers to a Player structure representing the player whose visible boards will be modified
* Returns: none
*/
void setVisibleBoard(Player* p) {
	for (int i = 0; i < SIDE; i++) {
		for (int j = 0; j < SIDE; j++) {
			if (p->number == 1) {
				p->visibleBoard[i][j] = p->gameBoard[i][j];
			}
			else {
				p->visibleBoard[i][j] = '-';
			}
		}
	}
}




/*
* Function name: randomlyPlaceShipsOnBoard()
* Programmer: Aabhwan Adhikary
* Description: Generates random coordinates and orientations to place the player's ships
* Input parameters: Pointer to a player struct that will be passed to another function to randomly place their ships
* Returns: none
*/
void randomlyPlaceShipsOnBoard(Player *p) {
	int allShipsPlaced = 0;
	int shipNumber = 1;

	while (!allShipsPlaced) {
		char orientation = '\0', ship = '\0';
		int goodPlacement = 0;

		int vertOrHoriz = rand() % 2;
		if (vertOrHoriz == 0) { // vertical
			orientation = 'v';
		}
		else { // horizontal
			orientation = 'h';
		}

		switch (shipNumber) {
		case 1:
			ship = 'c';
			break;
		case 2:
			ship = 'b';
			break;
		case 3:
			ship = 'r';
			break;
		case 4:
			ship = 's';
			break;
		default:
			ship = 'd';
			break;
		}

		int x = rand() % 10, y = rand() % 10; // random number from 0-9

		while (!goodPlacement) {
			goodPlacement = verifyShip(orientation, ship, x, y, p);
			if (goodPlacement) {
				placeShip(orientation, ship, x, y, p);
			}
			else {
				x = rand() % 10, y = rand() % 10; // tries again if the placement is invalid
			}
		}

		if (shipNumber == 5) { // this means all ships have been placed
			allShipsPlaced = 1;
		}
		else {
			shipNumber++;
		}
	}
}




/*
* Function name: checkShot()
* Programmer: Aabhwan Adhikary
* Description: Checks if the player's shot hit or missed a ship, or if the shot was invalid
* Input parameters: Pointer to a Player struct whose board will be checked for a ship; Pointer to a Stats struct that will modify
*					the stats based on whether the shot hit or not; Pointer to an integer representing whether the shot hit or not;
*					x and y (ints) representing the coordinates of the shot
* Returns: none
*/
void checkShot(Player *p, Stats *s, int *shotHit, int x, int y) {
	if (p->visibleBoard[y][x] == 'm' || p->visibleBoard[y][x] == '*' || (x < 0 || x > 9) || (y < 0 || y > 9)) { // invalid guess
		*shotHit = -1;
	}
	else if (p->gameBoard[y][x] == '-') { // miss
		printf("(%d, %d) is a miss!\n", x, y);
		*shotHit = 0;
		s->misses++;
	}
	else { // hit
		printf("(%d, %d) is a hit!\n", x, y);
		*shotHit = 1;
		s->hits++;
		changeCell(p, x, y);
	}
}




/*
* Function name: changeCell()
* Programmer: Aabhwan Adhikary
* Description: Changes the corresponding cell of the ship that was just hit to -1
* Input parameters: Pointer to a Player struct whose ship's cells will be modified; x and y (ints) represent the coordinates of the shot
* Returns: none
*/
void changeCell(Player* p, int x, int y) {
	for (int i = 0; i < 5; i++) { // goes through cells of each ship to see if any one of them have the cell that was hit, breaks loop when found
		if (p->carrier.cells[i][0] == x && p->carrier.cells[i][1] == y) {
			p->carrier.cells[i][0] = -1, p->carrier.cells[i][1] = -1;
			break;
		}
		if (p->battleship.cells[i][0] == x && p->battleship.cells[i][1] == y) {
			p->battleship.cells[i][0] = -1, p->battleship.cells[i][1] = -1;
			break;
		}
		if (p->cruiser.cells[i][0] == x && p->cruiser.cells[i][1] == y) {
			p->cruiser.cells[i][0] = -1, p->cruiser.cells[i][1] = -1;
			break;
		}
		if (p->submarine.cells[i][0] == x && p->submarine.cells[i][1] == y) {
			p->submarine.cells[i][0] = -1, p->submarine.cells[i][1] = -1;
			break;
		}
		if (p->destroyer.cells[i][0] == x && p->destroyer.cells[i][1] == y) {
			p->destroyer.cells[i][0] = -1, p->destroyer.cells[i][1] = -1;
			break;
		}
	}
}




/*
* Function name: isWinner()
* Programmer: Aabhwan Adhikary
* Description: Determines if the game has a winner by seeing if any players have no ships left
* Input parameters: Pointers to 2 Player structures to see if either of them have no ships left; Pointers to 2 Stats structures to
*					record the winner if there is one
* Returns: integer representing whether a winner exists or not
*/
int isWinner(Player *p1, Player *p2, Stats *s1, Stats *s2) {
	int winnerExists = 0;

	if (p1->shipsRemaining == 0) { // if Player 1 has no ships left, meaning they lose
		s1->won = 0;
		s2->won = 1;
		winnerExists = 1;
		printf("Player 2 wins!\n");
	}
	if (p2->shipsRemaining == 0) { // if Player 2 has no ships left, meaning they lose
		s1->won = 1;
		s2->won = 0;
		winnerExists = 1;
		printf("Player 1 wins!\n");
	}

	return winnerExists;
}




/*
* Function name: updateBoard()
* Programmer: Aabhwan Adhikary
* Description: Updates the players board based on whether the shot hit or not
* Input parameters: Pointer to a Player structure allowing the program to modify the player's board; integer representing whether the
*					shot hit or not; x and y (ints) representing the coordinates of the location that will be updated
* Returns: none
*/
void updateBoard(Player *p, int shotHit, int x, int y) {
	if (shotHit) { // the shot hit a part of the ship
		p->visibleBoard[y][x] = '*';
	}
	else { // the shot missed
		p->visibleBoard[y][x] = 'm';
	}
}




/*
* Function name: displayBoard()
* Programmer: Aabhwan Adhikary
* Description: Displays a player's board to the screen
* Input parameters: Pointer to a Player struct allowing the program to access their cells field and printing it out
* Returns: none
*/
void displayBoard(Player *p) {
	for (int i = 0; i < SIDE; i++) {
		printf("%d ", i);

		for (int j = 0; j < SIDE; j++) {
			printf("%c ", p->visibleBoard[i][j]);
		}

		printf("\n");
	}

	for (int k = -1; k < SIDE; k++) {
		if (k == -1) {
			printf("  ");
		}
		else {
			printf("%d ", k);
		}
	}

	printf("\n");
}




/*
* Function name: outputCurrentMove()
* Programmer: Aabhwan Adhikary
* Description: Outputs the current player's move to the log file
* Input parameters: Pointer to a file that will write the information on there; integer representing the current player number that
*					will be printed onto the file; x and y (ints) representing the coordinates that will be printed to the file;
*					integer representing whether the shot hit or not
* Returns: none
*/
void outputCurrentMove(FILE* dataFile, int playerNum, int x, int y, int shotHit) {
	if (shotHit) {
		fprintf(dataFile, "Player%d: %d,%d \"hit\"\n", playerNum, x, y);
	}
	else {
		fprintf(dataFile, "Player%d: %d,%d \"miss\"\n", playerNum, x, y);
	}
}




/*
* Function name: checkIfSunkShip()
* Programmer: Aabhwan Adhikary
* Description: Checks the player's ship's cells to see if all of them are -1 or not (if they are all -1 then it has sunk)
* Input parameters: Pointer to a Player struct whose ship's cells will be checked
* Returns: none
*/
void checkIfSunkShip(Player *p) {
	for (int i = 0; i < 5; i++) {
		if (p->carrier.cells[i][0] != -1 || p->carrier.cells[i][1] != -1) { // this means the ship hasn't been sunk yet
			break;
		}

		if (!p->carrier.sunk && i == 4) { // this means the program went through the entire loop without breaking, meaning the ship sunk
			p->carrier.sunk = 1;
			printf("Player %d's carrier has been sunk!\n", p->number);
			(p->shipsRemaining)--;
		}
	}

	for (int j = 0; j < 5; j++) {
		if (p->battleship.cells[j][0] != -1 || p->battleship.cells[j][1] != -1) { // this means the ship hasn't been sunk yet
			break;
		}

		if (!p->battleship.sunk && j == 4) { // this means the program went through the entire loop without breaking, meaning the ship sunk
			p->battleship.sunk = 1;
			printf("Player %d's battleship has been sunk!\n", p->number);
			(p->shipsRemaining)--;
		}
	}

	for (int k = 0; k < 5; k++) {
		if (p->cruiser.cells[k][0] != -1 || p->cruiser.cells[k][1] != -1) { // this means the ship hasn't been sunk yet
			break;
		}

		if (!p->cruiser.sunk && k == 4) { // this means the program went through the entire loop without breaking, meaning the ship sunk
			p->cruiser.sunk = 1;
			printf("Player %d's cruiser has been sunk!\n", p->number);
			(p->shipsRemaining)--;
		}
	}

	for (int l = 0; l < 5; l++) {
		if (p->submarine.cells[l][0] != -1 || p->submarine.cells[l][1] != -1) { // this means the ship hasn't been sunk yet
			break;
		}

		if (!p->submarine.sunk && l == 4) { // this means the program went through the entire loop without breaking, meaning the ship sunk
			p->submarine.sunk = 1;
			printf("Player %d's submarine has been sunk!\n", p->number);
			(p->shipsRemaining)--;
		}
	}

	for (int m = 0; m < 5; m++) {
		if (p->destroyer.cells[m][0] != -1 || p->destroyer.cells[m][1] != -1) { // this means the ship hasn't been sunk yet
			break;
		}

		if (!p->destroyer.sunk && m == 4) { // this means the program went through the entire loop without breaking, meaning the ship sunk
			p->destroyer.sunk = 1;
			printf("Player %d's destroyer has been sunk!\n", p->number);
			(p->shipsRemaining)--;
		}
	}
}




/*
* Function name: outputStats()
* Programmer: Aabhwan Adhikary
* Description: Output the stats of both players to the log file
* Input parameters: Pointer to a file where the stats will be output; Pointers to 2 Stats structs representing both of the players'
*					stats, whose fields will be output to the file
* Returns: none
*/
void outputStats(FILE* dataFile, Stats *s1, Stats *s2) {
	fprintf(dataFile, ".\n.\n.\n.\n.\n.\n.\n.\n.\n");

	if (s1->won) {
		fprintf(dataFile, "Player 1 wins, Player 2 loses\n\n");
	}
	else {
		fprintf(dataFile, "Player 2 wins, Player 1 loses\n\n");
	}

	fprintf(dataFile, "*** Player 1 Stats ***\n");
	fprintf(dataFile, "Number Hits: %d\n", s1->hits);
	fprintf(dataFile, "Number Misses: %d\n", s1->misses);
	fprintf(dataFile, "Total Shots: %d\n", s1->shots);
	fprintf(dataFile, "Hit/Miss Ratio: %d%%\n\n", s1->ratio);

	fprintf(dataFile, "*** Player 2 Stats *** \n");
	fprintf(dataFile, "Number Hits: %d\n", s2->hits);
	fprintf(dataFile, "Number Misses: %d\n", s2->misses);
	fprintf(dataFile, "Total Shots: %d\n", s2->shots);
	fprintf(dataFile, "Hit/Miss Ratio: %d%%\n", s2->ratio);
}