/*
 * This program returns iX with the Nbits that begin at position iPosition set to the rightmost nbits of iY, leaving the other bits unchanged. 
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 28 July 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <limits.h>  
#include "../error_handling.h"

/** MACRO DEFINITIONS */
#define MAX_BITS (sizeof(int) * 8) /* Maximum number of bits in an int */

/** FUNCTION PROTOTYPES */
int setbits(int iX, int iPosition, int iNbits, int iY);

/** MAIN PROGRAM */
/*
 * main: Function to interact with the user and perform the setbits operation.
 */
int main() {
    int iX, iPosition, iNbits, iY;
    int iResult;
    int iValidInput;

    while (1) {
        printf("\n--------------------------------------\n");
        printf("Set Bits Operation\n");
        printf("--------------------------------------\n");

        /* Get iX from the user */
        printf("Enter the value of iX: ");
        iValidInput = scanf("%d", &iX);
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

        /* Get iY from the user */
        printf("Enter the value of iY: ");
        iValidInput = scanf("%d", &iY);
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
        iResult = setbits(iX, iPosition, iNbits, iY);
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
 * setbits: This function returns iX with the Nbits that begin at position iPosition set to the rightmost nbits of iY, leaving the other bits unchanged.
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 28 July 2024
 */
int setbits(int iX, int iPosition, int iNbits, int iY) {
    return (iX & ((~0 << (iPosition + 1)) | (~(~0 << (iPosition + 1 - iNbits))))) | ((iY & ~(~0 << iNbits)) << (iPosition + 1 - iNbits));
}

