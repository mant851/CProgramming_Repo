/**
 * Write a program to convert integer iInput into character is sString
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void itoa(int iInput, char sString[]);
void reverse(char sString[]);
/** MAIN PROGRAM */
/*
 * main: convert iInput into characters in sString. 
*/


int main(){
        char sString[1000]; // string conversion of input 
	int iInput = -1234567890; // input integer 
        itoa(iInput,sString);
        printf("%s\n", sString); // print conversion of iInput into sString
        return 0;
}


/*
 * itoa: convert integer iInput into character in sString with handling largest negative number.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/

void itoa(int iInput, char sString[]){
int iIndex = 0;
    int iSign = iInput;  // Initialize iSign with iInput for sign handling

    if (iSign < 0) {
        iInput = -iInput;
    }

    do {
        sString[iIndex++] = iInput % 10 + '0';
    } while ((iInput /= 10) > 0);

    if (iSign < 0) {
        sString[iIndex++] = '-';
    }

    sString[iIndex] = '\0';

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

