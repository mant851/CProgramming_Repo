/*
 * This program returns iInput with the iNbits that begin at position iPosition inverted.
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
int invert(int iX,int iPosition,int iNbit);

/** MAIN PROGRAM */
/*
 * main: iInput with the iNbits that begin at position iPosition inverted.
 */

int main(){

        int iInput= 183; /* input number */
        int iPosition = 4; /* position from which the bits will be inverted */
        int iNbits = 3; /* total number of bits from iPositionth that will be inverted */
	int iResult;  /* Store the result */
    	int iValidInput; /* Validation Flag */

    while (1) {
        printf("\n--------------------------------------\n");
        printf("Bit Inversion Operation\n");
        printf("--------------------------------------\n");

        /* Get iX from the user */
        printf("Enter the value of iInput: ");
        iValidInput = scanf("%d", &iInput);
        if (iValidInput != 1) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }

        /* Get iPosition from the user */
        printf("Enter the position (iPosition): ");
        iValidInput = scanf("%d", &iPosition);
        if (iValidInput != 1) {
            handle_error(ERROR_INVALID_INPUT);
	    return 1;
        }

        /* Get iNbits from the user */
        printf("Enter the number of bits (iNbits): ");
        iValidInput = scanf("%d", &iNbits);
        if (iValidInput != 1) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }

     

        /* Validate inputs */
        if (iPosition < 0 || iPosition >= MAX_BITS) {
            handle_error(POSITION_OUT_OF_RANGE);
            return 1;
        }
        if (iNbits < 0 || iNbits > MAX_BITS) {
            handle_error(NBITS_OUT_OF_RANGE);
	    return 1;
        }
        if (iPosition + 1 - iNbits < 0) {
            handle_error(INVALID_BIT_POSITION);
	    return 1;
        }

        /* Perform the setbits operation */
        iResult = invert(iInput,iPosition,iNbits);
        printf("iX after the setbits operation will be: %d\n", iResult);
	
	char cContinueChoice;
        printf("Would you like to perform another operation? (y/n): ");
        if (scanf(" %c", &cContinueChoice) != 1) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }
        while (getchar() != '\n'); 
        if (cContinueChoice != 'y' && cContinueChoice != 'Y') {
            break;
        }

	
    }


    return 0;

}

/*
 * iInput: iInput with the iNbits that begin at position iPosition inverted.
 * Author:Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

int invert(int iInput, int iPosition, int iNbits){
	
	return iInput ^ (~(~0 << iNbits) << iPosition+1-iNbits );

}
