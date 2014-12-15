/*
E6_func.c
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.141592653589

void gauss_seidel(double **u_new, double **u_old, int grid_size, double *error){

	int i, j;

	for(i = 1; i < grid_size; i++){
		for(j = 1; j < grid_size; j++){
			u_new[i][j] = 0.25 * (u_old[i+1][j] + u_new[i-1][j] + u_old[i][j+1] + u_new[i][j-1]);
		}
	}

}





