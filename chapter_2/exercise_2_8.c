/*
 * This program returns the value of the integer iInput rotated to the right by Nbits positions
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include "../error_handling.h"


/** MACRO DEFINITIONS */
#define MAX_BITS (sizeof(int) * 8) /* Maximum number of bits in an int */

/** FUNCTION PROTOTYPES*/
int rightRotationInput(int iInput,int iNbit);

/** MAIN PROGRAM */
/*
 * main: prints the value of the integer iInput rotated to the right by Nbits positions
 */

int main(){

        int iInput; /* input number */
        int iNbits ; /* total number of bits from iPositionth that will be inverted */
	int iResult;  /* Store the result */
    	int iValidInput; /* Validation Flag */

	while (1) {
        printf("\n--------------------------------------\n");
        printf("Bit Rotation Operation\n");
        printf("--------------------------------------\n");

        /* Get iInput from the user */
        printf("Enter the input value (iInput): ");
        iValidInput = scanf("%d", &iInput);
        if (iValidInput != 1) {
            handle_error(ERROR_INVALID_INPUT);
	    return 1;
        }

        /* Get iNbits from the user */
        printf("Enter the number of bits to rotate (iNbits): ");
        iValidInput = scanf("%d", &iNbits);
        if (iValidInput != 1) {
            handle_error(ERROR_INVALID_INPUT);
	    return 1;
        }

        /* Validate inputs */
        if (iNbits < 0 || iNbits >= MAX_BITS) {
            handle_error(NBITS_OUT_OF_RANGE);
	    return 1;
        }
        if (iNbits > MAX_BITS) {
            handle_error(ERROR_ROTATION_TOO_LARGE);
	    return 1;
        }
	
	
        /* Perform the right rotation operation */
        iResult = rightRotationInput(iInput, iNbits);
        printf("iInput after the rotation operation will be: %d\n", iResult);
	
        char cContinueChoice;
	printf("Would you like to perform another operation? (y/n): ");
	if (scanf(" %c", &cContinueChoice) != 1) {
    		handle_error(ERROR_INVALID_INPUT);
    		while (getchar() != '\n'); // Clear the input buffer
    			continue; // Continue to the start of the loop
	}
	while (getchar() != '\n'); // Clear the input buffer

		if (cContinueChoice != 'y' && cContinueChoice != 'Y') {
    			break; /* Exit the loop if the user does not enter 'y' or 'Y' */
		}

	}
}
/*
 * iInput: returns the value of the integer iInput rotated to the right by Nbits positions.
 * Author:Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

int rightRotationInput(int iInput, int iNbits){
	int iTemp = iInput; /* Temparory variable to store input */
	int iIndex;
	for(iIndex=1;iIndex<=iNbits;iIndex++){
		iTemp = (iTemp<<1) | (( (iTemp >> sizeof(int)*8 -1) ));
		
	}

        return iTemp;

}
