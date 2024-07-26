/*
 * This program is deletes each character of fisrt string that match with any character of other string.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** MACRO DEFINITONS */
#define MAX_INPUT_LENGTH 100

/** FUNCTION PROTOTYPES*/
void squeeze(char sSource[], char sCompare[]);

/** MAIN PROGRAM */
/*
 * main: funtion to print string after removing each character from the given other string.
 */

int main(){
    char sSource[MAX_INPUT_LENGTH + 1];  /* Buffer to hold user input (including space for null terminator) */
    char sCompare[MAX_INPUT_LENGTH + 1]; /* Buffer for characters to be removed */
    
    /* Prompt user for the source string */
    printf("Enter the source string (max %d characters): ", MAX_INPUT_LENGTH);
    if (scanf("%100s", sSource) != 1) {
        handle_error("Error reading source string");
        return 1;
    }
    
    /* Prompt user for the compare string */
    printf("Enter the characters to be removed (max %d characters): ", MAX_INPUT_LENGTH);
    if (scanf("%100s", sCompare) != 1) {
        handle_error("Error reading compare string");
        return 1;
    }
    
    /* Validate input */
    if (strlen(sSource) == 0 || strlen(sCompare) == 0) {
        handle_error("Source or compare string cannot be empty.");
        return 1;
    }

    /* Perform the squeeze operation */
    squeeze(sSource, sCompare);
    
    /* Display result */
    printf("String after removing characters: %s\n", sSource);
    
    return 0;
}

/*
 * squeeze: Deletes each character in sSource that matches any character in sCompare.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */
void squeeze(char sSource[], const char sCompare[]) {
    int removeMap[256] = {0}; // Assuming ASCII characters
    
    // Populate the removeMap with characters to be removed
    for (int i = 0; sCompare[i] != '\0'; i++) {
        removeMap[(unsigned char)sCompare[i]] = 1;
    }

    // Filter the source string
    int iSourceIndex, iFilteredIndex;
    for (iSourceIndex = iFilteredIndex = 0; sSource[iSourceIndex] != '\0'; iSourceIndex++) {
        if (removeMap[(unsigned char)sSource[iSourceIndex]] == 0) {
            sSource[iFilteredIndex++] = sSource[iSourceIndex];
        }
    }

    // Null-terminate the result
    sSource[iFilteredIndex] = '\0'; 
}


