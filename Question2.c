#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise

	int dim = N2;
	double entry;
	double diag;

	for(int i = 0; i < dim; i++){		//start a loop that will go through each row of mat up to the dimension
		double rowSum = 0;
		for(int j = 0; j < dim; j++){	//go through each sequential entry in the selected row i
			entry = fabs(mat[i][j]);	//use fabs() in math.h for absolute value of the entry
			rowSum += entry;
		}
		diag = fabs(mat[i][i]);			//use fabs() in math.h for absolute value of the diagonal of the row
		if(diag <= rowSum - diag){
			isDiag = 0;
			break;						//if the diagonal is less than row sum for any row the matrix is not
		}								//diagonally dominant and the loop breaks
		else{							//otherwise the matrix is diagonally dominant
			isDiag = 1;
		}
	}


    return isDiag;
}
