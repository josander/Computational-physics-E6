/*
E6_func.c
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141592653589

// Function for the Gauss-Seidel method. Returns the maximal error
double gauss_seidel(double **u, int grid_size){

	
	int i, j;
	int grid_midpoint = (grid_size -1)/2;	
	
	double h_inv_sq = pow(1/(grid_size - 1),2);
	double temp;
	double itError = 0.0;

	// Gauss-Seidel
	for(i = 1; i < grid_size - 1; i++){
		for(j = 1; j < grid_size - 1; j++){
			
			temp = u[i][j];
			//If the point is on the dipole
			if(j == grid_midpoint){
				if(i == grid_midpoint*4/5){
					u[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]) + 0.25; //h_inv_sq * h_sq = 1
				}
				else if(i == grid_midpoint*6/5){
					u[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]) - 0.25;
				}
				else{
					u[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]);
			
				}
			//  GS-algorithm
			}else{ 

				u[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] + u[i][j+1] + u[i][j-1]);
			}


			// Calculate maximal error
			if(fabs(u[i][j] - temp) > itError){
				itError = fabs(u[i][j] - temp);
			}
		}
	}

	return(itError);
}



