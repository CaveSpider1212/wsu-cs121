/*
	Author: Aabhwan Adhikary
	Date: 8/26/24

	Description: This program prompts the user for 3 exam scores, computes the average of the 3 exam scores,
	and displays the average to the screen.
*/

#define _CRT_SECURE_NO_WARNINGS
#define NUM_SCORES 3 // no semicolon here....constant macro

#include <stdio.h> // printf (), scanf ()

int main(void) { // starting point of execution for all C programs
	int score1 = 0,
		score2 = 0,
		score3 = 0,
		sumScores = 0;
		//examAverage = 0;

	//float average = 0.0;
	double examAverage = 0.0;

	// 1. Prompt the user for exam score 1
	printf("Please enter exam score 1: ");

	// 2. Get the score for exam 1 from the user
	scanf("%d", &score1); // & address of operator

	// 3. Prompt the user for exam score 2
	printf("Please enter exam score 2: ");

	// 4. Get the score for exam 2 from the user
	scanf("%d", &score2);

	// 5. Get the score for exam 3 from the user
	printf("Please enter exam score 3: ");

	// 6. Get the score for exam 3 from the user
	scanf("%d", &score3);

	// 7. Sum up the scores
	sumScores = score1 + score2 + score3;

	// 8. Compute the average of the 3 exam scores
	examAverage = (double) sumScores / NUM_SCORES; // integer division

	// 9. Display the average to the screen
	//printf("Exam Average: %d\n", examAverage);
	printf("Exam Average: %1f\n", examAverage);
	
	return 0; // indicate that our program executed successfully
}