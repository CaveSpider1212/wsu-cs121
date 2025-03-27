#pragma once

// LAB 11 - 11/6/24

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct employee {
	char name[100];
	char title;
	double hoursWorked;
	double payrate;
	double payment;
} Employee;

void readFromFile(Employee* payroll, FILE *payrollFile);
void computePayments(Employee* payroll);
void computeTotalPayments(Employee* payroll, double *totalPayment);
void computeAveragePayment(double total, int *count, double *average, Employee* payroll);
void findMinMaxPayment(double* min, double* max, int count, Employee* payroll);
void outputToFile(FILE* paidFile, double total, double average, double max, double min);