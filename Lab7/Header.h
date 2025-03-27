#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void getInitials(char* fInitial, char* mInitial, char* lInitial);
void charges(int hours, double* totalCharge, double* avgPerHour);
double roundMoney(double number);
int predict(int target);
void revenue(double* r, int t);