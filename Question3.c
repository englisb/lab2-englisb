#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){
	
	int i, j, entry, nextRow;
	int arrIndex = 0;

	//init a loop that starts indexing at i = 0 and once the nested loop is over start at i+1
	//this loop stops after the middle diagonal
	for(nextRow = 0; nextRow < N3; nextRow++){
		/*
		 *starting at the leftmost entry of row i, set the entry then set each
		 *subsequent entry to the one diagonally up-right by one on each repetition
		 *loop stops after the top row is reached
		 */
		for(i = nextRow, j = 0; i >= 0; i--, j++, arrIndex++){
			entry = mat[i][j];
			arr[arrIndex] = entry;
		}
	}

	/*
	*this loop picks up at the diagonal following the middle diagonal
	*init a loop that starts indexing at i = 1 and once the nested loop is over indexes at i+1
	*stop once i is equal to the dimension of the matrix
	*/
	for(nextRow = 1; nextRow < N3; nextRow++){
		/*
		 * starting at the entry to the right of the first entry in the bottom,
		 * set the entry then set each subsequent entry diagonally up-right by one
		 * until the final entry in the diagonal is reached
		 */
		for(i = N3 - 1, j = nextRow; j < N3; i--, j++, arrIndex++){
			entry = mat[i][j];
			arr[arrIndex] = entry;
		}
	}
}
