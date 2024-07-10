/*
 * This program converts upper case letters into lower case latters.
 * Author: Manthan Nagar
 * Created: 9 July 2024
 * Modified: 9 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** MAIN PROGRAM */
/*
 * main: prints the upper case letters and equivelent lower case letters.
 */

int main(){

	char sInput[] = "MANTHAN";
	int iIndex;
	printf("The string after a lower case will be ");
	for(iIndex=0;iIndex<strlen(sInput);iIndex++){
		printf("%c",sInput[iIndex]+32);
	}
	printf("\n");
        return 0;
}
