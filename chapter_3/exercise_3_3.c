/**
 * Write a program that expands shorthand notations.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void expand(char sString1[], char sString2[]);

/** MAIN PROGRAM */
/*
 * main: takes input string and prints expanded shorthad string
*/


int main(){
        char sString1[]= "0-9a-c";
        char sString2[1000];
        expand(sString1, sString2);
        printf("%s\n", sString2);
        return 0;
}


/*
 * escape: takes input string and returns expanded shorthand notations.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/

void expand(char sString1[], char sString2[]){
	int iLength = strlen(sString1); // Length of sString1
	int iIndex1=0;// index of sString1
	int iIndex2=0;// index of sString2
	while(iIndex1<iLength){
		if(sString1[iIndex1]=='-'){
			for(int i= sString1[iIndex1-1];i<= sString1[iIndex1+1];i++) {
				sString2[iIndex2] = i ;
				iIndex2++;
			
			}
		}
		iIndex1++;
	}

}
