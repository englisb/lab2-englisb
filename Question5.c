#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){

	int destIndex;
	for(destIndex = 0; destIndex < n; destIndex++){		//iterate through each entry of the destination array
		if(destIndex == n - 1){
			destination[destIndex] = '\0';				//insert a null character at the end of the destination array
			break;										//stop the loop once the end of the array is reached
		}
		destination[destIndex] = source[destIndex];
		if(source[destIndex] == '\0'){					//if the source array has ended stop the loop
			break;
		}
	}
}
