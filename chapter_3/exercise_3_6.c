/**
 * Write a program to convert integer iInput into character is sString with minimum field width functionality.
 * Author: Manthan Nagar
 * Created: 11 July 2024
 * Modified: 11 July 2024
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../error_handling.h"

/** FUNCTION PROTOTYPES */
void itoa(int iInput, char sString[], int iMinWidth);
void reverse(char sString[]);
int isValidWidth(int minWidth);

int main() {
    char sString[1000]; /* String conversion of input */
    int iInput;         /* Input integer */
    int iMinWidth;      /* Minimum field width

    /* User input for integer value */
    printf("Enter an integer: ");
    if (scanf("%d", &iInput) != 1) {
        handle_error(ERROR_INVALID_INPUT);
        return 1;
    }

    /* User input for minimum field width */
    printf("Enter minimum field width: ");
    if (scanf("%d", &iMinWidth) != 1 || !isValidWidth(iMinWidth)) {
        handle_error(ERROR_INVALID_WIDTH);
        return 1;
    }

    /* Convert integer to string with minimum field width */
    itoa(iInput, sString, iMinWidth);
    printf("Formatted string: '%s'\n", sString);

    return 0;
}

/**
 * itoa: Convert integer iInput into a string in sString with minimum field width functionality.
 */
void itoa(int iInput, char sString[], int iMinWidth) {
    int iIndex = 0;
    int iSign = iInput; // Store the sign of the number
    int iNumSpaces; // Number of leading spaces needed

    /* Validate minWidth */
    if (!isValidWidth(iMinWidth)) {
        handle_error(ERROR_INVALID_WIDTH);
        sString[0] = '\0'; // Set an empty string to indicate error
        return;
    }

    /* Handle negative numbers */
    if (iSign < 0) {
        iInput = -iInput;
    }

    /* Generate the number string in reverse */
    do {
        sString[iIndex++] = iInput % 10 + '0';
    } while ((iInput /= 10) > 0);

    /* Handle negative sign */
    if (iSign < 0) {
        sString[iIndex++] = '-';
    }

    /* Calculate number of spaces needed */
    iNumSpaces = iMinWidth - iIndex;

    /* Add leading spaces if necessary */
    while (iNumSpaces > 0) {
        sString[iIndex++] = ' ';
        iNumSpaces--;
    }

    /* Terminate the string */
    sString[iIndex] = '\0';

    /* Reverse the string to correct order */
    reverse(sString);
}

/**
 * reverse: Reverse a given string.
 */
void reverse(char sString[]) {
    int iStart = 0;
    int iEnd = strlen(sString) - 1;
    char cTemp;

    while (iStart < iEnd) {
        // Swap characters
        cTemp = sString[iStart];
        sString[iStart] = sString[iEnd];
        sString[iEnd] = cTemp;

        // Move towards the center
        iStart++;
        iEnd--;
    }
}

/**
 * isValidWidth: Validate the minimum field width.
 */
int isValidWidth(int minWidth) {
    return (minWidth > 0);
}
