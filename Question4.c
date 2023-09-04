#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){

	int wordIndex = 0, freqIndex = 0, ASCII = 65;
	char chara;

	while(1){
		chara = word[wordIndex];
		if(chara == '\0'){
			break;								//if the end of the array has been reached stop the loop
		}
		/*
		 * Assuming the index of freq is the decimal value of chara,
		 * starting at ASCII decimal 65, check if the chara is decimal freqIndex
		 * or freqIndex + 32, where uppercase letters start.
		 * since freq[freqIndex] pertains to word[wordIndex], freq[freqIndex - 65]
		 * will be the respective index of chara
		 */
		for(freqIndex = 65; freqIndex < 91; freqIndex++ ){
			if(chara == freqIndex || chara == freqIndex + 32){
				freq[freqIndex - 65]++;
			}
		}
		wordIndex++;
		ASCII++;
	}
}
