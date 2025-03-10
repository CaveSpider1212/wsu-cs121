/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Created: 11/24/2024
* Assignment: PA 8
* Description: This program is mainly about solving 6 different challenges or interview questions using functions.
*/

#include "Header.h"

int main(void) {
	// TASK 1
	printf("TASK 1 -\n\n");

	char src[] = "table";
	char dest[] = "pool";
	my_str_n_cat(dest, src, 4); // should concatenate "tabl"

	int i = 0;
	printf("%s\n", dest);

	printf("-----------------------------------------------------------------------------------------\n");


	// TASK 2
	printf("TASK 2 -\n\n");

	int list[] = { 1, 3, 5, 6, 7, 9 };
	int size = 6, target = 6;

	printf("%d is located at index %d.\n", target, binary_search(list, size, target));
	
	printf("-----------------------------------------------------------------------------------------\n");


	// TASK 3
	printf("TASK 3 -\n\n");

	char *strings[] = { "hello", "world", "computer" };

	printf("Old array before bubble sort:\n");
	for (int i = 0; i < 3; i++) {
		puts(strings[i]);
	}

	bubble_sort(strings, 3);

	printf("\nNew array after bubble sort:\n");
	for (int i = 0; i < 3; i++) {
		puts(strings[i]);
	}

	printf("-----------------------------------------------------------------------------------------\n");

	
	// TASK 4
	printf("TASK 4 -\n\n");

	char* word1 = "race car", *word2 = "computer";
	printf("%s: %d\n", word1, is_palindrome(word1, 8));
	printf("%s: %d\n", word2, is_palindrome(word2, 8));

	printf("-----------------------------------------------------------------------------------------\n");


	// TASK 5
	printf("TASK 5 -\n\n");

	int num = 17;
	printf("The sum of all prime numbers from 2 to %d is %d.\n", num, sum_primes(num));
	
	printf("-----------------------------------------------------------------------------------------\n");


	// TASK 6
	printf("TASK 6 -\n\n");

	Occurrences occ[100] = { 0 };
	char *str = "test string";
	int maxNum = 0;
	char maxChar = '\0';

	maximum_occurences(str, occ, &maxNum, &maxChar);
	printf("The most common character in \"%s\" is '%c' with %d occurrences.\n", str, maxChar, maxNum);
	return 0;
}