#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
	for(int i = 0; i < size; i++){					//start a loop going through each common entry
		vector3[i] = vector1[i] + vector2[i];		//of vector 1 and vector 2, adding them and
	}												//inserting them into vector 3
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;
	
    for(int i = 0; i < size; i++){					//start a loop iterating through each common
    	prod += vector1[i] * vector2[i];			//entry of vector 1 and vector 2, adding the
    }												//product of the entries to prod for scalar product

	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	
    L2 = sqrt(scalar_prod(vector1, vector1, size));	//use sqrt() from math.h to get sqrt of scalar product

	//finally, return the L2 norm 
    return L2;
}
