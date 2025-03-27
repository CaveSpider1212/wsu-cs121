// LAB 7 - 10/9/24

#include "Header.h"

int main(void) {
	// TASK 1
	printf("TASK 1 - INITIALS\n\n");

	char firstInitial = '\0', middleInitial = '\0', lastInitial = '\0';
	getInitials(&firstInitial, &middleInitial, &lastInitial);

	printf("\n-----------------------------------------------------------------------------------------------\n");

	// TASK 2
	printf("TASK 2 - INTERNET COST\n\n");

	FILE* internetInputs = NULL, * internetOutputs = NULL;
	int hours = 0, month = 0, year = 0, customerNumber = 0;
	double totalCharge = 0.0, averageCost = 0.0;

	internetInputs = fopen("internetInputs.txt", "r");
	internetOutputs = fopen("internetOutputs.txt", "w");

	fscanf(internetInputs, "%d %d", &month, &year);
	fscanf(internetInputs, "%d", &customerNumber);
	fscanf(internetInputs, "%d", &hours);

	charges(hours, &totalCharge, &averageCost);

	totalCharge = roundMoney(totalCharge);
	averageCost = roundMoney(averageCost);

	fprintf(internetOutputs, "Customer #%d's Total Charge: $%.2f\nCustomer #%d's Average Cost per Hour: $%.2f", customerNumber, totalCharge, customerNumber, averageCost);

	fclose(internetInputs);
	fclose(internetOutputs);

	printf("Check \"internetOutputs.txt\" for the output");
	printf("\n-----------------------------------------------------------------------------------------------\n");

	// TASK 3
	printf("TASK 3 - REVENUE\n\n");

	FILE* revenueOutputs = NULL;
	int targetYear = 0, currentYear = 0;
	double rev = 0.0;

	revenueOutputs = fopen("revenueOutputs.txt", "w");

	targetYear = predict(1000000);

	while (currentYear <= targetYear) {
		revenue(&rev, currentYear);
		fprintf(revenueOutputs, "%d - $%.2f\n", (currentYear + 1984), rev);
		currentYear++;
	}

	printf("Check \"revenueOutputs.txt\" for the output\n");

	return 0;
}