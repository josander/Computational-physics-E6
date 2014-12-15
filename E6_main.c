/*
 E6.c
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "E6_func.h"
#define PI 3.141592653589
#define kB 0.000086173324
#define c 299792458 // Units: [m/s]

/* Main program */
int main()
{

	// Declaration of variables
	int i, j, m, n;
	int m_max, n_max;
	double lambda;
	double epsilon0;
	double l;
	double d;
	double r_c, r_plus, r_minus;
	double phi;

	// Initiation of variables
	m_max = 50; // 10, 50, 100
	n_max = 50;
	lambda = 1;
	epsilon0 = 1;
	l = 1;
	d = 0.2 * l;
	r_c = 1;
	r_plus = r_c + d / 2.0;
	r_minus = r_c - d / 2.0;

	// File to save data 
	FILE *file;
	file = fopen("phi.data","w");

	// Get phi
	phi = 0;
	//phi = - lambda / (2 * PI * epsilon0) * (log(r - r+) - log(r - r-));

	fprintf(file,"%f\n", phi);

	
	// Close file
	fclose(file);

}

