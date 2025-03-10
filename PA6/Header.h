#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: PA 6
* Created: 10/28/24
* Description: This file contains all of the function prototypes, structures, and preprocessor directives of the program.
*/

#define SIDE 10
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ship {
	int size; // represents the size of the ship
	int cells[5][2]; // represents the cells this ship takes up (-1 means the ship was either sunk at that cell or never placed)
	int sunk; // represents if the ship has been sunk or not (0 for no, 1 for yes)
} Ship;

typedef struct player {
	int number;
	char gameBoard[SIDE][SIDE]; // represents the player's game board
	char visibleBoard[SIDE][SIDE]; // represents the board that is visible to the player
	Ship carrier; // player's carrier ship
	Ship battleship; // player's battleship
	Ship cruiser; // player's cruiser ship
	Ship submarine; // player's submarine
	Ship destroyer; // player's destroyer
	int shipsRemaining; // number of ships remaining for the player
} Player;

typedef struct stat {
	int hits;
	int misses;
	int shots;
	int ratio;
	int won;
} Stats;

void startGame(Player *p1, Player *p2, Stats *s1, Stats *s2, FILE* dataFile);
void welcomeScreen(void);
void initializeGameBoard(Player *p1, Player *p2);
void initalizeShips(Player* p1, Player* p2);
void initializeStats(Stats *s1, Stats *s2);
int selectWhoStartsFirst(void);
void switchPlayers(int* p);
void manuallyPlaceShipsOnBoard(Player *p);
int verifyShip(char orientation, char ship, int x, int y, Player *p);
void placeShip(char orientation, char ship, int x, int y, Player *p);
void setShipCells(Player* p, char ship, int *row, int x, int y);
void setVisibleBoard(Player* p);
void randomlyPlaceShipsOnBoard(Player *p);
void checkShot(Player *p, Stats *s, int *shotHit, int x, int y);
void changeCell(Player* p, int x, int y);
int isWinner(Player *p1, Player *p2, Stats *s1, Stats *s2);
void updateBoard(Player *p, int shotHit, int x, int y);
void displayBoard(Player *p);
void outputCurrentMove(FILE* dataFile, int playerNum, int x, int y, int shotHit);
void checkIfSunkShip(Player *p);
void outputStats(FILE* dataFile, Stats *s1, Stats *s2);