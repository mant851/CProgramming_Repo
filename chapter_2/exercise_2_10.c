/*
 * This program converts uppercase letters into lowercase letters.
 * Author: Manthan Nagar
 * Created: 9 July 2024
 * Modified: 28 July 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
#include "../error_handling.h"

/** MACRO DEFINITIONS */
#define MAX_INPUT_LENGTH 100 /* Maximum length of the input string */


/** FUNCTION PROTOTYPES */
void convertToLowercase(char sInput[]);

/** MAIN PROGRAM */
/*
 * main: Allows the user to input a string and converts all uppercase letters to lowercase.
 */
int main() {
    char sInput[MAX_INPUT_LENGTH + 1]; /* Buffer to hold the input string (including space for null terminator) */
    int iValidInput; /* Validation flag */

    while (1) {
        printf("\n--------------------------------------\n");
        printf("Uppercase to Lowercase Converter\n");
        printf("--------------------------------------\n");

        /* Get the input string from the user */
        printf("Enter a string (max %d characters): ", MAX_INPUT_LENGTH);
        iValidInput = scanf("%100s", sInput);
        if (iValidInput != 1) {
            handle_error(ERROR_INVALID_INPUT);
	    return 1;
        }

        /* Validate input length */
        if (strlen(sInput) > MAX_INPUT_LENGTH) {
            handle_error(ERROR_STRING_TOO_LONG);
	    return 1;
        }

        /* Convert the input string to lowercase */
        convertToLowercase(sInput);
        printf("The string in lowercase is: %s\n", sInput);

        /* Ask user if they want to perform another operation */
        char cContinueChoice;
        printf("Would you like to convert another string? (y/n): ");
        iValidInput = scanf(" %c", &cContinueChoice);
        if (iValidInput != 1 || (cContinueChoice != 'y' && cContinueChoice != 'Y' && cContinueChoice != 'n' && cContinueChoice != 'N')) {
            handle_error(ERROR_STRING_TOO_LONG);
	    return 1;
        }

        if (cContinueChoice != 'y' && cContinueChoice != 'Y') {
            break;
        }

        while (getchar() != '\n'); /* Clear the input buffer */
    }

    return 0;
}

/*
 * convertToLowercase: Converts all uppercase letters in the string to lowercase.
 * Author: Manthan Nagar
 * Created: 9 July 2024
 * Modified: 28 July 2024
 */
void convertToLowercase(char sInput[]) {
    int iIndex;
    for (iIndex = 0; iIndex < strlen(sInput); iIndex++) {
        if (sInput[iIndex] >= 'A' && sInput[iIndex] <= 'Z') {
            sInput[iIndex] = sInput[iIndex] + 32; /* Convert to lowercase */
        }
    }
}
