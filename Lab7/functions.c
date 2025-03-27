#include "Header.h"

void getInitials(char* fInitial, char* mInitial, char* lInitial) {
	printf("Enter your first initial:\n");
	scanf("\n%c", fInitial);

	printf("Enter your middle initial:\n");
	scanf("\n%c", mInitial);

	printf("Enter your last initial:\n");
	scanf("\n%c", lInitial);

	printf("Your three initials: %c %c %c", *fInitial, *mInitial, *lInitial);
}

void charges(int hours, double* totalCharge, double* avgPerHour) {
	if (hours <= 10) {
		*totalCharge = 7.99 * hours;
	}
	else {
		*totalCharge = (7.99 * 10) + (1.99 * (hours - 10));
	}

	*avgPerHour = *totalCharge / hours;
}

double roundMoney(double number) {
	return ("%.2f", number);
}

int predict(int target) {
	int t = 0;
	double revenue = 0.0;

	do {
		revenue = 203.265 * pow(1.071, t);
		if (revenue < target) {
			t++;
		}
	} while (revenue < target);

	return t;
}

void revenue(double* r, int t) {
	*r = 203.265 * pow(1.071, t);
}