#include "Header.h"

char* string_reverseArray(char* str) {
	int stringSize = 0;

	while (str[stringSize] != '\0') {
		stringSize++;
	}

	stringSize--;

	for (int i = 0; i < stringSize / 2; i++) {
		char temp = str[i];
		str[i] = str[stringSize - i - 1];
		str[stringSize - i - 1] = temp;
	}
}

char* string_reversePointer(char* str) {
	int stringSize = 0;

	while (*(str + stringSize) != '\0') {
		stringSize++;
	}

	for (int i = 0; i < stringSize / 2; i++) {
		char temp = *(str + i);
		*(str + i) = *(str + stringSize - i - 1);
		*(str + stringSize - i - 1) = temp;
	}
}

char* my_strcpy(char* destination, const char* source) {
	int sourceSize = 0;
	while (*(source + sourceSize) != '\0') {
		sourceSize++;
	}

	for (int i = 0; i < sourceSize; i++) {
		*(destination + i) = *(source + i);
	}
}

char* my_strcat(char* destination, const char* source) {
	int destSize = 0, sourceSize = 0, indexNull = 0;
	
	while (*(destination + destSize) != '\0') { // finds the size of the destination array (used to set the null character index)
		destSize++;

		if (*(destination + destSize) == '\0') {
			indexNull = destSize; // sets the index of the null character in the destination string
		}
	}
	destSize--;

	while (*(source + sourceSize) != '\0') { // finds the size of the source array (loop will go up to here when concatenating)
		sourceSize++;
	}
	sourceSize++;

	for (int i = 0; i < sourceSize; i++) { // adds the whole source array to the destination string, starting from the null character index
		*(destination + i + indexNull) = *(source + i);
	}
}

int my_strcmp(const char* s1, const char* s2) {
	int s1Size = 0, s2Size = 0;
	int comparison = 0;
	while (s1[s1Size] != '\0') {
		s1Size++;
	}
	s1Size--;

	while (s2[s2Size] != '\0') {
		s2Size++;
	}
	s2Size--;

	if (s1Size >= s2Size) {
		for (int i = 0; i < s1Size; i++) {
			if (*(s1 + i) != *(s2 + i)) {
				if (*(s1 + i) < *(s2 + i)) {
					comparison = -1;
				}
				if (*(s1 + i) > *(s2 + i)) {
					comparison = 1;
				}
				break;
			}
		}
	}
	else {
		for (int j = 0; j < s2Size; j++) {
			if (*(s1 + j) != *(s2 + j)) {
				if (*(s1 + j) < *(s2 + j)) {
					comparison = -1;
				}
				if (*(s1 + j) > *(s2 + j)) {
					comparison = 1;
				}
				break;
			}
		}
	}

	return comparison;
}

int my_strlen(const char* s) {
	int len = 0;
	while (s[len] != '\0') {
		len++;
	}

	return len;
}