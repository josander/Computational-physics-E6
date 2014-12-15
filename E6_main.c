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
	int i,j, m, n;
	int m_max, n_max;
	double lambda;
	double epsilon0;
	double l, lInv;
	double d;
	double r, r_c, r_plus, r_minus;
	double phi;
	double x, y, xInt;
	int grid_size;
	double error;

	// Initiation of variables
	m_max = 10; // 10, 50, 100
	n_max = 10;
	lambda = 1;
	epsilon0 = 1;
	l = 1;
	lInv = 1/l;
	d = 0.2 * l;
	r_c = l/2;
	r_plus = r_c + d / 2.0;
	r_minus = r_c - d / 2.0;
	y = l / 2;
	xInt = 0.0001;
	grid_size = 11;

	// Declaration of arrays
	double u1[grid_size][grid_size];
	double u2[grid_size][grid_size];

	// Initiation of arrays
	for(i = 0; i < grid_size; i++){
		for(j = 0; j < grid_size; j++){
			u1[i][j] = 0.0;
		}
	}
	

	// TASK 1
	// File to save data 
	FILE *file;
	file = fopen("phi10.data","w");

	// Get phi
	for(x = 0; x < l; x += xInt){
		phi = 0;
		for (m = 1; m < m_max + 1; m++){
			for (n = 1; n < n_max + 1; n++){
				phi += (double) pow(-1, m + n) * sin(PI * m * d * lInv) * sin(2.0 * PI * m * x * lInv) * sin(PI * (2.0 * n - 1) * y * lInv) / ((2.0 * 2.0 * m * m) + pow(2 * n - 1, 2));
			}
		}

		phi *= (- 2.0 * lambda * 2 * 2 / (epsilon0 * PI * PI));
		fprintf(file,"%f\n",phi);

	}

	// TASK 2
	while(error >= pow(10,-5)){
		gauss_seidel(u_new, u_old, grid_size,  &error);
	
	
		error = get_error(u_new, u_old,  grid_size);

		
	}

	
	// Close file
	fclose(file);

}

