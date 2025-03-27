// LAB 11 - 11/6/24

#include "Header.h"

void readFromFile(Employee* payroll, FILE *payrollFile) {
	char scannedValue[100] = "";
	int i = 0;

	while (fgets(scannedValue, 100, payrollFile) && i < 200) {
		strcpy(payroll[i].name, strtok(scannedValue, "\n"));
		fgets(scannedValue, 100, payrollFile);
		payroll[i].title = scannedValue[0];
		fgets(scannedValue, 100, payrollFile);
		payroll[i].hoursWorked = strtod(scannedValue, NULL);
		fgets(scannedValue, 100, payrollFile);
		payroll[i].payrate = strtod(scannedValue, NULL);

		i++;
	}
}

void computePayments(Employee* payroll) {
	int i = 0, normalPayment = 0, overtime = 0, total = 0;

	while (i < 200 && (payroll[i].title == 'M' || payroll[i].title == 'B')) {
		if (payroll[i].title == 'B') {
			if (payroll[i].hoursWorked > 40) {
				overtime = (payroll[i].hoursWorked - 40) * 1.5 * payroll[i].payrate;
				normalPayment = 40 * payroll[i].payrate;
			}
			else {
				normalPayment = payroll[i].hoursWorked * payroll[i].payrate;
			}
		}
		else {
			if (payroll[i].hoursWorked > 40) {
				overtime = (payroll[i].hoursWorked - 40) * 1.8 * payroll[i].payrate;
				normalPayment = 40 * payroll[i].payrate;
			}
			else {
				normalPayment = payroll[i].hoursWorked * payroll[i].payrate;
			}
		}

		payroll[i].payment = normalPayment + overtime;
		i++;
	}
}

void computeTotalPayments(Employee* payroll, double *totalPayment) {
	int i = 0;
	while (i < 200 && (payroll[i].title == 'M' || payroll[i].title == 'B')) {
		*totalPayment += payroll[i].payment;
		++i;
	}
}

void computeAveragePayment(double total, int *count, double *average, Employee* payroll) {
	int i = 0;
	while (i < 200 && (payroll[i].title == 'M' || payroll[i].title == 'B')) {
		(*count)++;
		i++;
	}

	*average = total / (*count);
}

void findMinMaxPayment(double* min, double* max, int count, Employee* payroll) {
	int i = 1;
	while (i < count) {
		if (payroll[i].payment < *min) {
			*min = payroll[i].payment;
		}

		if (payroll[i].payment > *max) {
			*max = payroll[i].payment;
		}

		i++;
	}
}

void outputToFile(FILE* paidFile, double total, double average, double max, double min) {
	fprintf(paidFile, "Total payments: $%.2f\n", total);
	fprintf(paidFile, "Average payment per employee: $%.2f\n", average);
	fprintf(paidFile, "Maximum payment: $%.2f\n", max);
	fprintf(paidFile, "Minimum payment: $%.2f\n", min);
}