#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){

	int sourIndex, valPosIndex;
	for(sourIndex = 0, valPosIndex = 0; sourIndex < size; sourIndex++, valPosIndex++){	//iterate through source, val and pos
		if(source[sourIndex] != 0){														//if an entry at source isn't 0 insert it and its index into val and pos respectively
			val[valPosIndex] = source[sourIndex];
			pos[valPosIndex] = sourIndex;
		}
		else{
			valPosIndex--;																//if a source entry is 0 decrement valPosIndex to counter the increment
		}
	}
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

	int sourIndex, valPosIndex;
	for(sourIndex = 0, valPosIndex = 0; valPosIndex < n; valPosIndex++, sourIndex++){
		while(sourIndex < pos[valPosIndex]){											//insert 0s into source at sourIndex up to a position with a non-zero component
			source[sourIndex] = 0;
			sourIndex++;
		}
		source[pos[valPosIndex]] = val[valPosIndex];
	}

	while(sourIndex < m){																//sourIndex = 1 + the position with the last non-zero entry;
		source[sourIndex] = 0;															//remaining entries are filled with 0s up to dimension m
		sourIndex++;
	}
}
