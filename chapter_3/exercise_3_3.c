/**
 * Write a program that expands shorthand notations.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
#include "../error_handling.h"

/** MARCO DEFINATIONS */
#define MAX_LENGTH 1000

/** FUNCTION PROTOTYPES */
void expand(char sString1[], char sString2[]);

/** MAIN PROGRAM */
/*
 * main: takes input string and prints expanded shorthad string
*/


int main() {
    char sString1[MAX_LENGTH];
    char sString2[MAX_LENGTH];
    char cContinueInput;

    do {
        printf("Enter a shorthand notation (up to %d characters):\n", MAX_LENGTH - 1);

        /* Read user input */
        if (fgets(sString1, MAX_LENGTH, stdin) == NULL) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }

        /* Remove newline character if present */
        int length = strlen(sString1);
        if (length > 0 && sString1[length - 1] == '\n') {
            sString1[length - 1] = '\0';
        }

        /* Check for empty input */
        if (strlen(sString1) == 0) {
            handle_error(ERROR_EMPTY_INPUT);
            continue;
        }

        /* Expand shorthand notation */
        expand(sString1, sString2);
        
        /* Print the result */
        printf("Expanded string:\n%s\n", sString2);

        /* Ask user if they want to continue */
        printf("Do you want to enter another shorthand notation? (y/n): ");
        cContinueInput = getchar();
        
        /* Clear the newline character left in the buffer */
        while (getchar() != '\n');

    } while (cContinueInput == 'y' || cContinueInput == 'Y');

    return 0;
}

/*
 * expand: Expands shorthand notations in the input string and copies the result to the output string.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
 */

void expand(char sString1[], char sString2[]) {
    int iIndex1 = 0, iIndex2 = 0;
    int length = strlen(sString1);

    while (iIndex1 < length) {
        if (sString1[iIndex1] == '-') {
            /* Check for invalid dash placement */
            if (iIndex1 == 0 || iIndex1 == length - 1 || !isalnum(sString1[iIndex1 - 1]) || !isalnum(sString1[iIndex1 + 1])) {
                handle_error(ERROR_INVALID_DASH_PLACEMENT);
                sString2[0] = '\0'; 
                return;
            }

            char start = sString1[iIndex1 - 1];
            char end = sString1[iIndex1 + 1];

            /* Check if the range is valid */
            if (start < end) {
                for (char c = start + 1; c < end; c++) {
                    sString2[iIndex2++] = c;
                }
            } else {
                handle_error(ERROR_INVALID_NOTATION);
                sString2[0] = '\0'; 
                return;
            }

            iIndex1 += 2; /* Skip the next character as it's part of the range */
            } else if (isalnum(sString1[iIndex1])) {
            	sString2[iIndex2++] = sString1[iIndex1];
                 } 
		else {
            	handle_error(ERROR_NON_ALPHANUMERIC);
            	sString2[0] = '\0'; /* Clear output on error */
            	return 1;
            	}
            iIndex1++;
    }
    sString2[iIndex2] = '\0'; /* Null-terminate the result string */
}