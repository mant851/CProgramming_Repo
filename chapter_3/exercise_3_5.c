/**
 * Write a program to converts the integer iInput into a base iBase character representation in the string sString. 
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void itob(int iInput, char sString[],int iBase);
void reverse(char sString[]);

/** MAIN PROGRAM */
/*
 * main: print the integer iInput into a base iBase character representation in the string sString.
*/


int main(){
        char sString[1000]; // string conversion of input
        int iInput = 255; // input integer
	int iBase = 7; // base for conversion
        itob(iInput, sString,iBase);
        printf("%s\n", sString); // print conversion of iInput into sString
        return 0;
}


/*
 * itob: funtion to converts the integer iInput into a base iBase character representation in the string sString.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/

void itob(int iInput, char sString[],int iBase){
	
	int iTemp;
	char cChartemp;
	int iIndex = 0;
	while(iInput!=0){
		iTemp = iInput % iBase;
		if (iTemp > 9){
			cChartemp = iTemp+87; 
		}
		else{
			cChartemp = iTemp+48;
		}
		sString[iIndex] = cChartemp;
		iIndex++;
		iInput = iInput / iBase;
	}
	reverse(sString);

}


/*
 * reverse: reverse a given string.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/

void reverse(char sString[]) {
    int iStart = 0;
    int iEnd = strlen(sString) - 1;
    char cTemp;

    while (iStart < iEnd) {
        // Swap characters
        cTemp = sString[iStart];
        sString[iStart] = sString[iEnd];
        sString[iEnd] = cTemp;

        // Move towards the center
        iStart++;
        iEnd--;
    }
}


