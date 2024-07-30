/*
 * This program deletes each character of the first string that matches any character of the second string.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
#include "../error_handling.h"

/** MACRO DEFINITIONS */
#define MAX_INPUT_LENGTH 100

/** FUNCTION PROTOTYPES */
void squeeze(char sSource[], char sCompare[]);

/** MAIN PROGRAM */
/*
 * main: Function to interact with the user and perform the squeeze operation.
 */
int main() {
    char sSource[MAX_INPUT_LENGTH + 1];  /* Buffer to hold user input (including space for null terminator) */
    char sCompare[MAX_INPUT_LENGTH + 1]; /* Buffer for characters to be removed */
    char cContinueChoice;                 /* Variable to determine if the user wants to continue */
    
    do {
        printf("\n--------------------------------------\n");
        printf("String Squeeze Program\n");
        printf("--------------------------------------\n");

        /* Get the source string */
        printf("Enter the source string (max %d characters): ", MAX_INPUT_LENGTH);
        if (scanf("%100s", sSource) != 1) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }
        
        /* Get the characters to be removed */
        printf("Enter the characters to be removed (max %d characters): ", MAX_INPUT_LENGTH);
        if (scanf("%100s", sCompare) != 1) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }
        
        /* Validate input */
        if (strlen(sSource) == 0 || strlen(sCompare) == 0) {
            handle_error(INPUT_UNDERFLOW);
            return 1;
        }

        /* Perform the squeeze operation */
        squeeze(sSource, sCompare);
        
        /* Display the result */
        printf("\nString after removing characters: \"%s\"\n", sSource);

        /* Ask user if they want to continue */
        printf("Would you like to process another string? (y/n): ");
        scanf(" %c", &cContinueChoice);
        
    } while (cContinueChoice == 'y' || cContinueChoice == 'Y');


    return 0;
}

/*
 * squeeze: Deletes each character in sSource that matches any character in sCompare.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */
void squeeze(char sSource[], char sCompare[]) {
    int removeMap[256] = {0}; // Assuming ASCII characters
    
    /* Populate the removeMap with characters to be removed */
    for (int i = 0; sCompare[i] != '\0'; i++) {
        removeMap[(unsigned char)sCompare[i]] = 1;
    }

    /* Filter the source string */
    int iSourceIndex, iFilteredIndex;
    for (iSourceIndex = iFilteredIndex = 0; sSource[iSourceIndex] != '\0'; iSourceIndex++) {
        if (removeMap[(unsigned char)sSource[iSourceIndex]] == 0) {
            sSource[iFilteredIndex++] = sSource[iSourceIndex];
        }
    }

    /* Null-terminate the result */
    sSource[iFilteredIndex] = '\0'; 
}


