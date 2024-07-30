/*
 * This program counts the number of 1 bits in a given integer.
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 28 July 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include "../error_handling.h"

/** FUNCTION PROTOTYPES */
int countSetBits(int iInput);

/** MAIN PROGRAM */
/*
 * main: Prompts the user for an integer and prints the count of 1 bits in the given integer.
 */
int main() {
    int iInput;  /* Input integer */
    int iCount;  /* Count of 1 bits */
    int iValidInput; /* Validation flag */

    while (1) {
        printf("\n--------------------------------------\n");
        printf("Bit Count Operation\n");
        printf("--------------------------------------\n");

        /* Get the integer input from the user */
        printf("Enter an integer: ");
        iValidInput = scanf("%d", &iInput);
        if (iValidInput != 1) {
            handle_error(ERROR_INVALID_INPUT);
	    return 1;
        }

        /* Count the number of 1 bits */
        iCount = countSetBits(iInput);
        printf("Total number of set bits is: %d\n", iCount);

        /* Ask user if they want to perform another operation */
        char cContinueChoice;
        printf("Would you like to count bits for another integer? (y/n): ");
        iValidInput = scanf(" %c", &cContinueChoice);
        if (iValidInput != 1 || (cContinueChoice != 'y' && cContinueChoice != 'Y' && cContinueChoice != 'n' && cContinueChoice != 'N')) {
            handle_error(ERROR_INVALID_INPUT);
	    return 1;
        }

        if (cContinueChoice != 'y' && cContinueChoice != 'Y') {
            break;
        }

        while (getchar() != '\n'); 
    }

    return 0;
}

/*
 * countSetBits: Counts the number of 1 bits in the given integer.
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 28 July 2024
 */
int countSetBits(int iInput) {
    int iCount = 0; /* Counts total number of 1 bits */
    while (iInput != 0) {
        iInput &= (iInput - 1);
        iCount++;
    }
    return iCount;
}
