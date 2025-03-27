// LAB 9 - 10/23/2024

#include "Header.h"

int main(void) {
	// TASK 1
	printf("TASK 1:\n\n");

	char str1[] = { 'h', 'e', 'l', 'l', 'o', '\0'};
	string_reverseArray(str1);
	printf("%s\n", str1);

	char str2[] = { 'w', 'o', 'r', 'l', 'd', '\0' };
	string_reversePointer(str2);
	printf("%s\n", str2);

	printf("----------------------------------------------------------------------\n");

	printf("TASK 2:\n\n");

	char src1[] = { 'c', 'p', 't', 's', '\0' };
	char dest1[] = { '\0', '\0', '\0', '\0', '\0' };
	my_strcpy(dest1, src1);
	printf("%s\n", dest1);

	char src2[] = { 'w', 'o', 'r', 'l', 'd', '\0' };
	char dest2[80] = { 'h', 'e', 'l', 'l', 'o', ' ', '\0' };
	my_strcat(dest2, src2);
	printf("%s\n", dest2);

	char s1[] = { 'm', 'o', 'n', 'i', 't', 'o', 'r', '\0' };
	char s2[] = { 'p', 'h', 'o', 'n', 'e', '\0' };
	printf("%d\n", my_strcmp(s1, s2));

	char s[] = { 'o', 'u', 't', 'l', 'e', 't', '\0' };
	printf("%d\n", my_strlen(s));

	return 0;
}