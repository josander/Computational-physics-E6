/*
 E6.c
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "E5_func.h"
#define PI 3.141592653589
#define kB 0.000086173324
#define c 299792458 // Units: [m/s]

/* Main program */
int main()
{

	// Declaration of variables
	int j, n;
	double r;
	double epsilon;
	double L;
	double a0, alpha;
	int J = 100;
	int x = 101;
	int timesteps = 20000;
	double **y = malloc(x * sizeof(double));
	for(j = 0; j < x; j++){
		y[j] = malloc((timesteps+1) * sizeof(double));
	}

	// Characteristic values for different notes
	double epsilonC2 = 7.5 * pow(10,-6);
	double epsilonC4 = 3.8 * pow(10,-5);
	double epsilonC7 = 8.7 * pow(10,-4);
	double LC2 = 1.9;
	double LC4 = 0.62;
	double LC7 = 0.09;
	
	// Initiation of variables
	a0 = 0.05; // Units: [m]
	alpha = 0.1;
	epsilon = epsilonC7;
	r = 0.1;
	L = LC7; // Units: [m]

	// Create files
	FILE *a_file;
	a_file = fopen("amplitude.data","w");

	// Initiation of y
	for(j = 0; j < x; j++){
	
		// If 0<i<alpha*x
		if(j < alpha*100){
			y[j][0] = (double) a0 * j/(alpha*100);
			y[j][1] = (double) a0 * j/(alpha*100);
		
		// If alpha*x <= i < x
		}else{ 
			y[j][0] = (double) a0 * (1 - j/100.0) / (1 - alpha);
			y[j][1] = (double) a0 * (1 - j/100.0) / (1 - alpha);
		}
	}

	// Save initial values
	for(j = 0; j < x; j++){
		// Print result in file
		fprintf(a_file, "%f\t", y[j][0]);
	}

	fprintf(a_file, "\n");

	// Save initial values
	for(j = 0; j < x; j++){
		// Print result in file
		fprintf(a_file, "%f\t", y[j][1]);
	}

	fprintf(a_file, "\n");

	// For each timestep and every lattice point, calculate the ampl in next timestep
	for(n = 1; n < timesteps + 1; n++){

		y[0][n+1] = 0;
		y[x - 1][n+1] = 0;

		fprintf(a_file, "%f\t", y[0][n+1]);
		
		for(j = 1; j < x - 1; j++){
			
			// If lattice point x=2, set y(x-2) = y(0) = 0
			if(j == 1){

			y[j][n+1] = (2-(2*r*r)-(6*epsilon*r*r*J*J))*y[j][n] - y[j][n-1] + r*r*(1+(4*epsilon*J*J))*(y[j+1][n]+y[j-1][n])-(epsilon*r*r*J*J*y[j+2][n]); 

			// If lattice point x=100, set y(x+2) = y(102) = 0
			}else if(j == x - 2){

			y[j][n+1] = (2-(2*r*r)-(6*epsilon*r*r*J*J))*y[j][n] - y[j][n-1] + r*r*(1+(4*epsilon*J*J))*(y[j+1][n]+y[j-1][n])-(epsilon*r*r*J*J*y[j-2][n]); 

			}else{

			y[j][n+1] = (2-(2*r*r)-(6*epsilon*r*r*J*J))*y[j][n] - y[j][n-1] + r*r*(1+(4*epsilon*J*J))*(y[j+1][n]+y[j-1][n])-epsilon*r*r*J*J*(y[j+2][n] + y[j-2][n]); 

			}

		// Print result in file
		fprintf(a_file, "%f\t", y[j][n+1]);

		}

		fprintf(a_file, "%f\t", y[x - 1][n+1]);

		fprintf(a_file, "\n");


	}

	// Close file
	fclose(a_file);

}

