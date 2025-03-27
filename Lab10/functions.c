// LAB 10 - 10/30/24

#include "Header.h"

void createSentences(char *article, char* noun, char* verb, char* prep, char *sentence[]) {
	int sentenceIndex = 0;

	for (int i = 0; i < 20; i++) {
		int articleRandom = rand() % 4;
		printf("%s\n");
		char* selectedArticle = *(article + articleRandom);
		printf("%s\n", selectedArticle);
		int articleLength = countWordLength(selectedArticle);
		int selectedArticleIndex = 0;

		while (sentenceIndex < sentenceIndex + articleLength) {
			//sentence[i][sentenceIndex] = selectedArticle[selectedArticleIndex];
			
			sentenceIndex++;
			selectedArticleIndex++;
		}
	}

	return sentence;
}

int countWordLength(char* word) {
	int i = 0;

	while (word[i] != '\0') {
		i++;
	}
	
	return i;
}

void displaySentences(char* sentence) {
	for (int i = 0; i < 20; i++) {
		printf("%c", sentence[i]);
	}
}

void inputCoordinates(int* row, int* column) {
	scanf("%d %d", row, column);
}