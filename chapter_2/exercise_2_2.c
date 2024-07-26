/*
 * This program is write a function getline without using for loop.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
/** MAIN PROGRAM */
/*
 * main: funtion to loop from the input funciton getline.
 */

int main(){
	int iLim = 10; /* limit for get line */
	int iCharacter; /* get character from the input*/ 
	int iGetstring[iLim]; /* store characters of given input. */
 
	for(int iIndex=0;iIndex<iLim-1;++iIndex){
		if(iCharacter=getchar() != '\n'){
			if(iCharacter != EOF){
				iGetstring[iIndex] = iCharacter;
			}
		}
	}

}
