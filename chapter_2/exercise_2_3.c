#include <stdio.h>
#include <math.h>
#include <string.h>
#include "../error_handling.h"

/** FUNCTION PROTOTYPES */
int convertToHexadecimal(char sHexChar[]);
int isValidHexadecimal(char sHexChar[]);

/** MAIN PROGRAM */
int main() {
    char sHexChar[100]; /* Buffer to hold user input */
    int iResult; /* Store the result */
    int choice; /* To store user's menu choice */

    while (1) {
        /* Display menu */
        printf("Hexadecimal Conversion Program\n");
        printf("1. Convert a hexadecimal string to decimal\n");
        printf("2. Exit\n");
        printf("Enter your choice (1 or 2): ");
        
        if (scanf("%d", &choice) != 1) {
            handle_error(ERROR_INVALID_INPUT);
            return 1; /* Return with error code */
        }

        switch (choice) {
            case 1:

                /* Prompt user for input */
                printf("Enter a hexadecimal string: ");
                scanf("%s", sHexChar); 
                
                /* Validate input */

                if (!isValidHexadecimal(sHexChar)) {
                    handle_error(INVALID_HEXADECIMAL);
                    continue; // Ask for input again
                }

                /* Convert and display result */
                iResult = convertToHexadecimal(sHexChar);
                printf("The decimal value of the hexadecimal string \"%s\" is %d.\n", sHexChar, iResult);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                return 0; // Exit the program

            default:
                printf("Invalid choice. Please enter 1 or 2.\n");
        }

        /* Clear input buffer to handle incorrect entries gracefully */
        
	while (getchar() != '\n'); // Clear the buffer
    }

    return 0;
}

/*
 * convertToHexadecimal: This function returns the decimal value of a hexadecimal string.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */
int convertToHexadecimal(char sHexChar[]) {
    int iIndex = strlen(sHexChar) - 1; /* Current index element */
    int iResult = 0; /* Current result */
    int iPower = 0; /* Power of the current index element */

    while (iIndex >= 0) {
        char ch = sHexChar[iIndex];

        if (ch >= '0' && ch <= '9') {
            iResult += pow(16, iPower) * (ch - '0');
        } else if (ch >= 'A' && ch <= 'F') {
            iResult += pow(16, iPower) * (ch - 'A' + 10);
        } else if (ch >= 'a' && ch <= 'f') {
            iResult += pow(16, iPower) * (ch - 'a' + 10);
        }

        iIndex--;
        iPower++;
    }

    return iResult;
}

/*
 * isValidHexadecimal: Checks if the input string is a valid hexadecimal number.
 * Author: Manthan Nagar
 * Created: 26 July 2024
 * Modified: 26 July 2024
 */
int isValidHexadecimal(char sHexChar[]) {
    int iIndex = 0; /* Variable for indexing */
    int iLength = strlen(sHexChar);

    if (iLength == 0) {
        return 0; 
    }

    while (iIndex < iLength) {
        char cCharacter = sHexChar[iIndex];
        if (!((cCharacter >= '0' && cCharacter <= '9') || (cCharacter >= 'A' && cCharacter <= 'F') || (cCharacter >= 'a' && cCharacter <= 'f'))) {
            return 0; /* Invalid character found */
        }
        iIndex++;
    }

    return 1; /* All characters are valid hexadecimal digits */
}
