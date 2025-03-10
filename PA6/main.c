/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Assignment: PA 6
* Created: 10/28/24
* Description: This program is an implementation of the game "Battleship."
*/

#include "Header.h"

int main(void) {
	srand((unsigned int)time(NULL));
	Player p1, p2;
	Stats s1, s2;
	FILE* dataFile = NULL;

	p1.number = 1, p2.number = 2;
	dataFile = fopen("battleship.log", "w");

	startGame(&p1, &p2, &s1, &s2, dataFile);

	s1.shots = s1.hits + s1.misses, s2.shots = s2.hits + s2.misses;
	s1.ratio = ((double) s1.hits / s1.misses) * 100, s2.ratio = ((double) s2.hits / s2.misses) * 100;
	outputStats(dataFile, &s1, &s2);

	fclose(dataFile);
	return 0;
}