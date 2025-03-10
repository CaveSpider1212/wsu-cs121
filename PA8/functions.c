/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Created: 11/24/2024
* Assignment: PA 8
* Description: This file contains all of the function definitions of the program.
*/

#include "Header.h"



/*
* Function name: my_str_n_cat()
* Programmer: Aabhwan Adhikary
* Description: This function takes a source string of length "n" and concatenates it to the end of the destination string.
* Input parameters: String (char pointer) "source" representing the word/string that will be concatenated to the end of the
*					String (char pointer) "destination"; integer "n" representing the length of the source string
* Returns: Pointer to the "destination" string
*/
char* my_str_n_cat(char* destination, char* source, int n) {
	int len = 0;
	while (*(destination + len) != '\0') { // determines length of destination array
		len++;
	}

	int i = len; // sets index to the end of the destination array
	while (i < len + n && *(source + i - len) != '\0') {
		*(destination + i) = *(source + i - len);
		i++;
	}
	*(destination + i) = '\0';

	return *destination;
}



/*
* Function name: binary_search()
* Programmer: Aabhwan Adhikary
* Description: Searches through a sorted list of length "n" for a target value
* Input parameters: integer array "*sorted" representing the list of sorted values; integer "n" representing the length of the
*					sorted list array; integer "target" representing the value that the program is searching for in the sorted
*					list
* Returns: integer "targetIndex" representing the index of the "target" value in the sorted list array, returns -1 if not in array
*/
int binary_search(int* sorted, int n, int target) {
	int left = 1, right = n, found = 0, targetIndex = -1;

	while (!found && left <= right) { // keeps going until the target values is found or while the program hasn't gone through the array yet
		int mid = (left + right) / 2;

		if (sorted[mid] == target) {
			found = 1, targetIndex = mid;
		}
		else {
			if (target < sorted[mid]) {
				right = mid - 1;
			}
			if (target > sorted[mid]) {
				right = mid + 1;
			}
		}
	}

	return targetIndex;
}



/*
* Function name: bubble_sort()
* Programmer: Aabhwan Adhikary
* Description: Sorts an array of string pointers using the bubble sort algorithm
* Input parameters: char array "*strPointers[]" representing the array of string pointers that the program will be sorting; integer
*					"n" representing the length of the string pointer array
* Returns: none
*/
void bubble_sort(char *strPointers[], int n) {
	int u = n, count = 0;

	do {
		for (int c = 1; c < u; c++) {
			if (strcmp(strPointers[c], strPointers[c - 1]) < 0) { // compares string to the string to the left (if it's smaller, switch them)
				char *temp = strPointers[c];
				strPointers[c] = strPointers[c - 1];
				strPointers[c - 1] = temp;
			}
		}

		u -= 1;
	} while (u > 0);
}



/*
* Function name: is_palindrome()
* Programmer: Aabhwan Adhikary
* Description: Checks if a string is a palindrome or not (word is the same forward and in reverse)
* Input parameters: String (char pointer) "str" representing the string the program will be checking; integer "len" representing
*					the length of the string, and this value will be decremented during the recursive step.
* Returns: integer "isPalindrome" representing whether the string is a palindrome or not
*/
int is_palindrome(char* str, int len) {
	int isPalindrome = 1, length = 0;

	for (int i = 0; str[i] != '\0'; i++) { // finds the length of the string (different from len)
		length++;
	}

	int first = length - len; // determines the first index we are checking by subtracting the current len value (final index) from the length of the word

	if (isspace(str[len - 1]) || isspace(str[first])) { // checks for white space in the string (decreases len by 1 if there is)
		isPalindrome = is_palindrome(str, len - 1);
	}
	else if (*(str + first) != *(str + len - 1)) { // checks if the character at the "first" index is not equal to the character at the "len - 1" index (not a palindrome)
		isPalindrome = 0;
	}
	else {
		if (*(str + first + 1) != '\0') { // makes sure program won't go out of bounds of the string
			isPalindrome = is_palindrome(str, len - 1);
		}
	}

	return isPalindrome;
}



/*
* Function name: sum_primes()
* Programmer: Aabhwan Adhikary
* Description: Finds the sum of all prime numbers from 2 to "n"
* Input parameters: integer "n" representing the number the program will be going up to when finding the sum of the primes
* Returns: integer "sum" representing the sum of the prime numbers from 2 to "n"
*/
int sum_primes(int n) {
	int sum = 0, i = n;

	if (i <= 2) { // base case, ends the recursion by returning "2" for sum
		sum = 2;
	}
	else {
		if (isPrime(n, 2)) { // if the number is prime, add it to the other sums, otherwise don't add it
			sum = n + sum_primes(n - 1);
		}
		else {
			sum = sum_primes(n - 1);
		}
	}

	return sum;
}



/*
* Function name: isPrime()
* Programmer: Aabhwan Adhikary
* Description: Checks if a number is prime or not (used to help with sum_primes() function)
* Input parameters: integer "num" representing the number the program is checking; integer "divisor" representing what "num" will
*					be divided by to check if it is prime or not, and will be increased during the recursive step
* Returns: integer "prime" representing whether the number is prime or not
*/
int isPrime(int num, int divisor) {
	int prime = 1;

	if (divisor == num) { // base case, ends the recursion
		return;
	}
	else {
		if (num % divisor == 0) { // number is divisible by something other than 1 or itself, so it is prime and will return 0
			prime = 0;
		}
		else {
			prime = isPrime(num, divisor + 1); // recursive step, continues the recursion with the next divisor
		}
	}

	return prime;
}



/*
* Function name: maximum_occurences()
* Programmer: Aabhwan Adhikary
* Description: Finds the character that appears the most in a string and how many times it occurs using the Occurrences struct
* Input parameters: String (char pointer) "str" representing the string that the program will be looking at to determine maximum
*					occurrences; Occurrences struct array "arr" representing the array of different characters in the string, as
*					well as their number of occurrences and frequency; integer pointer "maxOccurrences" representing the number
*					of the most frequent character in the string; char pointer "character" representing the character that appears
*					the most in the string
* Returns: none
*/
void maximum_occurences(char* str, Occurrences arr[], int* maxOccurrences, char* character) {
	int i = 0, count = 0, occurIndex = 0;;
	while (str[i] != '\0') { // loops until end of string
		count++;
		char currentChar = str[i];

		for (int j = i; str[j] != '\0'; j++) { // loops through string to count number of occurrences of the current character
			if (str[j] == currentChar) {
				arr[occurIndex].numOccurences++;
			}
		}

		arr[occurIndex].frequency = arr[occurIndex].numOccurences / count;
		
		if (arr[occurIndex].numOccurences > *maxOccurrences) { // if the current character appears the most, set the character pointer to that character
			*maxOccurrences = arr[occurIndex].numOccurences;
			*character = currentChar;
		}

		occurIndex++;
		i++;
	}
}