/**
 * Write a program to converts the integer iInput into a base iBase character representation in the string sString. 
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/


/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../error_handling.h"

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void itob(int iInput, char sString[], int iBase);
void reverse(char sString[]);
int isValidBase(int iBase);

/** MAIN PROGRAM */
/*
 * main: print the integer iInput into a base iBase character representation in the string sString.
*/


int main() {
    char sString[1000]; /* String conversion of input */
    int iInput;         /* Input integer */
    int iBase;          /* Base for conversion */

    /* User input for integer value*/
    printf("Enter an integer: ");
    if (scanf("%d", &iInput) != 1) {
        handle_error(ERROR_INVALID_INPUT);
        return 1;
    }

    /* User input for base value*/
    printf("Enter the base (between 2 and 36): ");
    if (scanf("%d", &iBase) != 1 || !isValidBase(iBase)) {
        handle_error(ERROR_INVALID_BASE);
        return 1;
    }

    /* Convert integer to string representation in specified base */
    itob(iInput, sString, iBase);
    printf("The representation of %d in base %d is: %s\n", iInput, iBase, sString);

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

/**
 * isValidBase: Validate the base for conversion.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
 */
int isValidBase(int iBase) {
    return (iBase >= 2 && iBase <= 36);
}
