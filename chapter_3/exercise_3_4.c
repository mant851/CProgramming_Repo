/**
 * Write a program to convert an integer iInput into a character string sString.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 28 July 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <limits.h>
#include <string.h>

#include "../error_handling.h"

/** MACRO DEFINITIONS */
#define MAX_LENGTH 1000

/** FUNCTION PROTOTYPES */
void itoa(int iInput, char sString[]);
void reverse(char sString[]);


/** MAIN PROGRAM */
/*
 * main: Takes an integer input from the user, converts it to a string, and prints the result.
 */
int main() {
    char sString[MAX_LENGTH]; /* string conversion of input */
    int iInput;
    char cContinueInput;
    int iValidInput;

    do {
        printf("Enter an integer (up to %d digits):\n", MAX_LENGTH - 1);

        /* Read integer input from user */
        while (1) {
            iValidInput = scanf("%d", &iInput);
            if (iValidInput == 1) {
                break; /* Valid input received */
            } else {
                handle_error(ERROR_INVALID_INPUT);
                while (getchar() != '\n'); 
                printf("Please enter a valid integer:\n");
            }
        }
	
        /* Convert integer to string */
        itoa(iInput, sString);

        /* Print the result */
        printf("The string representation of the integer is:\n%s\n", sString);

        /* Ask user if they want to continue */
        printf("Do you want to convert another integer? (y/n): ");
        while (getchar() != '\n'); /* Clear the input buffer */
        cContinueInput = getchar();

        /* Clear the input buffer */
        while (getchar() != '\n');

    } while (cContinueInput == 'y' || cContinueInput == 'Y');

    return 0;
}

/*
 * itoa: Converts an integer iInput into a string in sString with handling for the largest negative number.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 28 July 2024
 */
void itoa(int iInput, char sString[]) {
    int iIndex = 0;
    int iSign = iInput;  /* Initialize iSign with iInput for sign handling */

    /* Check for overflow for INT_MIN */
    if (iInput == INT_MIN) {
        handle_error(ERROR_OUT_OF_RANGE);
        sString[0] = '\0';
        return;
    }

    if (iSign < 0) {
        iInput = -iInput;
    }

    /* Convert number to string */
    do {
        if (iIndex >= MAX_LENGTH - 1) { 
            handle_error(ERROR_OUT_OF_RANGE);
            sString[0] = '\0';
            return;
        }
        sString[iIndex++] = iInput % 10 + '0';
    } while ((iInput /= 10) > 0);

    if (iSign < 0) {
        if (iIndex >= MAX_LENGTH - 1) { 
            handle_error(ERROR_OUT_OF_RANGE);
            sString[0] = '\0';
            return;
        }
        sString[iIndex++] = '-';
    }

    sString[iIndex] = '\0';

    /* Reverse the string to get the correct representation */
    reverse(sString);
}

/*
 * reverse: Reverses a given string.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 28 July 2024
 */
void reverse(char sString[]) {
    int iStart = 0;
    int iEnd = strlen(sString) - 1;
    char cTemp;

    while (iStart < iEnd) {
        /* Swap characters */
        cTemp = sString[iStart];
        sString[iStart] = sString[iEnd];
        sString[iEnd] = cTemp;

        /* Move towards the center */
        iStart++;
        iEnd--;
    }
}
