// LAB 12 - 11/13/24

#include "Header.h"

int main(void) {
	printf("TASK 1 - \n\n");

	char word[21];
	printf("Please input a string that will be reversed (max 20 characters:\n");
	scanf("%s", word);

	printf("----------------------------------------------------------------------------------\n");
	printf("TASK 2 - \n\n");

	int digits = 0, sum = 0;
	printf("Please input a number:\n");
	scanf("%d", &digits);

	sum = sumDigits(digits);
	printf("The sum is: %d\n", sum);

	printf("----------------------------------------------------------------------------------\n");
	printf("TASK 3 - \n\n");

	int row = 0, col = 1, i = 0;
	char maze[8][8] = {
		{' ', ' ', ' ', 'x', ' ', ' ', ' ', ' '},
		{' ', 'x', ' ', ' ', ' ', 'x', ' ', ' '},
		{' ', ' ', 'x', ' ', ' ', 'x', ' ', ' '},
		{' ', 'x', ' ', ' ', ' ', 'x', ' ', ' '},
		{' ', 'x', ' ', ' ', 'x', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'x', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
	};
	char been[100][2];

	determinePath(maze, been, row, col, &i);
	printPath(been);

	return 0;
}