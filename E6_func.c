/*
E6_func.c
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141592653589

void gauss_seidel(double **u_new, double **u_old, int grid_size, double *error){
	
	int i, j;	
	
	for(i = 1; i < grid_size - 1; i++){
		for(j = 1; j < grid_size - 1; j++){
			u_new[i][j] = 0.25 * (u_old[i+1][j] + u_new[i-1][j] + u_old[i][j+1] + u_new[i][j-1]);
		}
	}

}

double get_error(double **u_new, double **u_old, int grid_size){

	int i, j;
	double error = 0;


	for(i = 1; i < grid_size - 1; i++){
		for(j = 1; j < grid_size - 1; j++){
			if(fabs(u_new[i][j] - u_old[i][j])) > error){
				error = fabs(u_new[i][j] - u_old[i][j]);
			}	
		}
	}
	return(error);
}



