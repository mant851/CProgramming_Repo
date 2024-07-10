/*
 * This program to count number of 1 bit in the given integer.
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** MAIN PROGRAM */
/*
 * main: prints the count of number of 1 bit in the given integer.
 */

int main(){

	int iInput = 183;// input integer
	int iCount = 0; // counts total number of 1 bit in the given integer.
	while(iInput!=0){
		
		iInput &= (iInput-1);
		iCount++;
	}
	printf("Total number of set bits will be %d \n",iCount);
}
