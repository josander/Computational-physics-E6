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
	double l, lInv;
	double d;
	double r, r_c, r_plus, r_minus;
	double phi;
	double x, y, xInt;
	int grid_size. grid_midpoint;
	double error;
	double h_sq;

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
	grid_midpoint = (grid_size -1)/2;
	error = 1.0;
	h_sq = pow(grid_midpoint*2/l,2)

	// Declaration of arrays
	double** u1; 
	double** u2;
	double** temp;
	u1 = (double**) malloc(grid_size * sizeof(double*));
	u2 = (double**) malloc(grid_size * sizeof(double*));
	temp = (double**) malloc(grid_size * sizeof(double*));

	for(i = 0; i < grid_size; i++){
		u1[i] = (double*) malloc(grid_size * sizeof(double));
		u2[i] = (double*) malloc(grid_size * sizeof(double));
		temp[i] = (double*) malloc(grid_size * sizeof(double));
	}

	// Initiation of arrays
	for(i = 0; i < grid_size; i++){
		for(j = 0; j < grid_size; j++){
			u1[i][j] = 0.0;
		}
	}

	// Initiate arrays with a dipole
	u1[grid_midpoint][grid_midpoint*4/5] = -h_sq;
	u1[grid_midpoint][grid_midpoint*6/5] = h_sq;	

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
	// Use Gauss-Seidel method to solve the problem
	while(error >= pow(10,-5)){


		gauss_seidel(u1, u2, grid_size,  &error);


		// Use Gauss-Seidel method, returns the error
		error = gauss_seidel(u1, u2, grid_size, error);

		// Print error in terminal
		printf("Error: %f \n", error);

		// Change pointers
		temp = u1; 
		u1 = u2;
		u2 = temp;
	}
	
	// Close file
	fclose(file);

}

