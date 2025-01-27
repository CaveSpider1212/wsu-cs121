#pragma once

/*
* Programmer: Aabhwan Adhikary
* Class: CptS 121, Fall 2024; Lab Section 19
* Programming Assignment: PA 2
* Created: 9/7/2024
* Description: This file contains all of the function prototypes and preprocessor directives for the program.
*/

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14159
#define G 6.67e-11

#include <stdio.h>
#include <math.h>

double calculate_newtons_2nd_law(double mass, double acceleration);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character, int offset);
double calculateGravityForce(double mass1, double mass2, double distance);
double calculateCelsius(double fahrenheit);
double calculateDistance(double x1, double x2, double y1, double y2);
double evaluateEquation(double z, double x, int a);