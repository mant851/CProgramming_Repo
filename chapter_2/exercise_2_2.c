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
	int ilim = 10; //limit for get line
	int ic; // get character from the input
	int igetstring[ilim]; // store characters of given input. 
	for(int i=0;i<ilim-1;++i){
		if(ic=getchar() != '\n'){
			if(ic != EOF){
				igetstring[i] = ic;
			}
		}
	}

}
