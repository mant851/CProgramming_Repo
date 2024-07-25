/*
 * This program is to get the count of new lines, blancks and tabs.
 * Author: Manthan Nagar
 * Created: 24 June 2024
 * Modified: 24 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include "../error_handling.h"

/** MAIN PROGRAM */
/*
 * main: funtion to get count of new lines, blancks and tabs.
 */

int main(){
	
    int iCharacter;  // Variable to hold each character read from input
    int iNewline = 0;  // Counter for the number of newline characters ('\n')
    int iBlanks = 0;   // Counter for the number of blank spaces (' ')
    int iTabs = 0;     // Counter for the number of tab characters ('\t')


    while ((iCharacter = getchar()) != EOF) {
        if (iCharacter == '\n') {
            iNewline++;
        } else if (iCharacter == ' ') {
            iBlanks++;
        } else if (iCharacter == '\t') {
            iTabs++;
        } else if (iCharacter != '\n' && iCharacter != ' ' && iCharacter != '\t') {
            handle_error(INVALID_CHARACTER_DETECTED);
        }
    }

    printf("\nCharacter count summary:\n");
    printf("----------------------------\n");
    printf("Count of newline: %d\n", iNewline);
    printf("Count of blanks : %d\n", iBlanks);
    printf("Count of tabs   : %d\n", iTabs);
	
}/* End main()*/
