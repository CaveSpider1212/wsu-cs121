// LAB 11 - 11/6/24

#include "Header.h"

int main(void) {
	Employee payroll[200];
	FILE* payrollFile = NULL;
	FILE* paidFile = NULL;

	payrollFile = fopen("payroll.txt", "r");
	paidFile = fopen("paid.txt", "w");

	readFromFile(payroll, payrollFile);
	computePayments(payroll);

	int count = 0;
	double min = payroll[0].payment, max = payroll[0].payment, totalPayments = 0.0, averagePerEmployee = 0.0;

	computeTotalPayments(payroll, &totalPayments);
	computeAveragePayment(totalPayments, &count, &averagePerEmployee, payroll);
	findMinMaxPayment(&min, &max, count, payroll);
	outputToFile(paidFile, totalPayments, averagePerEmployee, max, min);

	fclose(payrollFile);
	fclose(paidFile);

	return 0;
}