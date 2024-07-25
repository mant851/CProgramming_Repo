/*
 * This program copies its input to its output, replacing each backspace by \b and each backslash by \\.
 * This makes tabs and backspaces unambiguous in the output.
 * Author: Manthan Nagar
 * Created: 24 June 2024
 * Modified: 24 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include "../error_handling.h"  

/** MAIN PROGRAM */
/*
 * main: function to copy its input to its output.
 */
int main(){
    int iCharacter;
    
    while((iCharacter = getchar()) != EOF){
        if(iCharacter == '\t'){ /* If the current character is a tab ('\t') */
            putchar('\t');     /* Output a tab character */
            putchar('\\');     /* Output a backslash character */
        }
        else if(iCharacter == '\b'){ /* If the current character is a backspace ('\b') */
            putchar('\b');           /* Output a backspace character */
        }
        else if(iCharacter == '\\'){ /* If the current character is a backslash ('\\') */
            putchar('\\');           /* Output a backslash character (to make it unambiguous) */
        }
        else{
            putchar(iCharacter);     /* Output the current character as-is */
        }
	
        /* Error handling for unexpected characters */
        if (iCharacter != '\t' && iCharacter != '\b' && iCharacter != '\\' && iCharacter != '\n' && iCharacter != ' ') {
  	    	handle_error(INVALID_CHARACTER_DETECTED);
        }
    }
    
    return 0;  
}/* End main()*/

