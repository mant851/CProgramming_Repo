/**
 * Write a program to convert characters like newline and tab into visible escape sequences like \n and \t as it copies the string sStringt to sStrings. Using a switch case also converting escape sequences into the real characters.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
 */


/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h> 
#include "../error_handling.h"

/** MACRO DEFINITIONS */
#define MAX_LENGTH 1000

/** FUNCTION PROTOTYPES */
void escape(const char sStrings[], char sStringt[]);

/** MAIN PROGRAM */
/*
 * main: Takes a string from the user, converts special characters to escape sequences, and displays the result.
 */

int main() {
    char sStrings[MAX_LENGTH];
    char sStringt[MAX_LENGTH];
    char continueInput;

    do {
        printf("Enter a string (up to %d characters):\n", MAX_LENGTH - 1);

        /* Read input with a limit to avoid buffer overflow */
        if (fgets(sStrings, MAX_LENGTH, stdin) == NULL) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }

        /* Remove newline character if present */
        int length = strlen(sStrings);
        if (length > 0 && sStrings[length - 1] == '\n') {
            sStrings[length - 1] = '\0';
        }

        /* Convert special characters to escape sequences */
        escape(sStrings, sStringt);
        
        /* Print the result */
        printf("Converted string:\n%s\n", sStringt);

        /* Ask user if they want to continue */
        printf("Do you want to enter another string? (y/n): ");
        continueInput = getchar();
        
        // Clear the newline character left in the buffer
        while (getchar() != '\n');

    } while (continueInput == 'y' || continueInput == 'Y');
    return 0;
}

/*
 * escape: Converts characters like newline and tab into visible escape sequences like \n and \t.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
 */

void escape(const char sStrings[], char sStringt[]) {
    int iIndexs = 0, iIndext = 0;

    while (sStrings[iIndexs] != '\0') {
        switch (sStrings[iIndexs]) {
            case '\n':
                sStringt[iIndext++] = '\\';
                sStringt[iIndext++] = 'n';
                break;
            case '\t':
                sStringt[iIndext++] = '\\';
                sStringt[iIndext++] = 't';
                break;
            default:
                sStringt[iIndext++] = sStrings[iIndexs];
                break;
        }
        iIndexs++;
    }
    sStringt[iIndext] = '\0'; /* Null-terminate the result string */
}
