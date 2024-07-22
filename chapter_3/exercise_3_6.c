/**
 * Write a program to convert integer iInput into character is sString with minimum field width functionality.
 * Author: Manthan Nagar
 * Created: 11 July 2024
 * Modified: 11 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void itoa(int iInput, char sString[], int minWidth);
void reverse(char sString[]);

/** MAIN PROGRAM */
/*
 * main: convert iInput into character in sString with minimum field width functionality.
*/


int main(){
        char sString[1000]; // string conversion of input
        int iInput = 123; // input integer
	int minWidth = 6;
        itoa(iInput,sString,minWidth);
        printf("%s\n", sString); // print conversion of iInput into sString
        return 0;
}


/*
 * itoa: convert integer iInput into character in sString with adding minimum field width functionality.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/

void itoa(int iInput, char sString[], int minWidth) {
    int iIndex = 0;
    int iSign = iInput; // Store the sign of the number
    int numSpaces; // Number of leading spaces needed

    // Handle negative numbers
    if (iSign < 0) {
        iInput = -iInput;
    }

    // Generate the number string in reverse
    do {
        sString[iIndex++] = iInput % 10 + '0';
    } while ((iInput /= 10) > 0);

    // Handle negative sign
    if (iSign < 0) {
        sString[iIndex++] = '-';
    }

    // Calculate number of spaces needed
    numSpaces = minWidth - iIndex;

    // Add leading spaces if necessary
    while (numSpaces > 0) {
        sString[iIndex++] = ' ';
        numSpaces--;
    }

    // Terminate the string
    sString[iIndex] = '\0';

    // Reverse the string to correct order
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
