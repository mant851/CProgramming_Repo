/*
 * This program returns the first location in sString1 where any character from sString2 occurs.
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 28 July 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../error_handling.h" 

/** MACRO DEFINITIONS */
#define MAX_INPUT_LENGTH 100

/** FUNCTION PROTOTYPES */
int any(char sString1[], char sString2[]);

/** MAIN PROGRAM */
/*
 * main: Function to interact with the user and find the location of the first occurrence of a character.
 */
int main() {
    char sString1[MAX_INPUT_LENGTH + 1];  /* Buffer to hold the first string (including space for null terminator) */
    char sString2[MAX_INPUT_LENGTH + 1];  /* Buffer to hold the second string (including space for null terminator) */
    int iLocation;                         /* Variable to store the location of the first occurrence */
    
    while (1) {
        printf("\n--------------------------------------\n");
        printf("String Character Location Finder\n");
        printf("--------------------------------------\n");

        /* Get the first string from the user */
        printf("Enter the first string (max %d characters): ", MAX_INPUT_LENGTH);
        if (scanf("%100s", sString1) != 1) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }
        
        /* Get the second string from the user */
        printf("Enter the second string (max %d characters): ", MAX_INPUT_LENGTH);
        if (scanf("%100s", sString2) != 1) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }
        
        /* Validate input */
        if (strlen(sString1) == 0 || strlen(sString2) == 0) {
            handle_error(INPUT_UNDERFLOW);
            return 1;
        }

        /* Perform the search operation */
        iLocation = any(sString1, sString2);
        
        /* Display the result */
        if (iLocation == -1) {
            printf("sString1 contains no characters from sString2.\n");
        } else {
            printf("The location of the first occurrence is: %d\n", iLocation);
        }
        
        /* Ask user if they want to continue */
        char cContinueChoice;
        printf("Would you like to find another occurrence? (y/n): ");
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
 * any: This function returns the first location in sString1 where any character from sString2 occurs.
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 28 July 2024
 */
int any(char sString1[], char sString2[]) {
    int iIndexString1;
    int iIndexString2;

    /* Iterate over each character in sString1 */
    for (iIndexString1 = 0; iIndexString1 < strlen(sString1); iIndexString1++) {
        /* Compare with each character in sString2 */
        for (iIndexString2 = 0; iIndexString2 < strlen(sString2); iIndexString2++) {
            if (sString1[iIndexString1] == sString2[iIndexString2]) {
                return iIndexString1;
            }
        }
    }

    /* Return -1 if no match is found */
    return -1;
}
