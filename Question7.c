#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){


	int val3Index, k3, val2Index, sigIndex, stoIndex;

	for(val3Index = 0; val3Index < k1; val3Index++){		//copies val1 and pos1 to val3 and position 3
		val3[val3Index] = val1[val3Index];
		pos3[val3Index] = pos1[val3Index];
	}

	for(k3 = k1, val3Index = 0, val2Index = 0; val2Index < k2; val2Index += 1, val3Index = sigIndex){
		while(val3Index < k3){
			if(val2[val2Index] == 0){								//if val2[val2Index] is null the vector is finished, break the loops
				break;
				break;
			}

			else if(val2Index >= k3){								//if val2Index is larger than the dimension of val3, no need to add anything, just insert the entry in val2 into val3
				val3[val2Index] = val2[val2Index];
				pos3[val2Index] = pos2[val2Index];
			}

			else{
				if(pos2[val2Index] == pos3[val3Index]){				//if the positions of 2 non-zero elements are the same between val2 and val3, add them
					val3[val3Index] += val2[val2Index];
					sigIndex = val3Index + 1;						//the significant index is the current val3Index + 1 because there is no need to check against entries preceding val3Index
					break;											//break to check the remaining entries of val2 against the remaining entries of val3
				}

				else if(pos2[val2Index] < pos3[val3Index]){			//if the position checked in val2 < the one checked in val3, insert the val2 and pos2 right before the upcoming val3 & pos3
					for(stoIndex = 0; stoIndex < val3Index - 1; stoIndex += 1){
						val3[k3 - stoIndex] = val3[k3 - stoIndex - 1];				//this is performed by cloning each val & pos in val3 & pos3 in the proceeding ones
						pos3[k3 - stoIndex] = pos3[k3 - stoIndex - 1];
					}
					val3[val3Index] = val2[val2Index];								//the val2 and pos2 are then inserted into the cloned val3 & pos3
					pos3[val3Index] = pos2[val2Index];
					k3 += 1;
					sigIndex = val3Index + 1;										//significant index for val3 to be checked against is now one greater than the current one
					break;
				}

				else{
					val3Index += 1;													//if none of the above is met, check the remaining pos2's against the next pos3
					sigIndex = val3Index;
				}
			}
		}
	}

	for(val3Index = 0; val3Index < k3; val3Index += 1){
		if(val3[val3Index] == 0){													//eliminate non-zero val'ss and pos's that added up to 0
			for(stoIndex = val3Index; stoIndex < k3; stoIndex += 1){
				val3[stoIndex] = val3[stoIndex + 1];
				pos3[stoIndex] = pos3[stoIndex + 1];
			}
			k3 -= 1;
		}
	}
}
