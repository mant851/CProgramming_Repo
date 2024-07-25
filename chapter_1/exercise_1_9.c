/*
 * This program is to copy its input to its output, replacing each string of one of more blancks by a single blanck.
 * Author: Manthan Nagar
 * Created: 24 June 2024
 * Modified: 24 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MACRO DEFINITIONS */
#define BLANCK '-'

/** MAIN PROGRAM */
/*
 * main: function to copy inputto its output, replacing each string of one of more blancksby a single blanck.
 */

int main(){
	int iCharacter;
	int iBlanck; /* Variable to store the previously read character */
	iBlanck = BLANCK;  /* Initialize iBlanck to the specified blank character (BLANCK) */
	while((iCharacter=getchar())!=EOF){
	if(iCharacter==' '){
		if(iBlanck!=' '){
		 putchar(iCharacter);
	}
	}
	else{
		putchar(iCharacter); /* Output non-blank characters directly */
	}
	iBlanck = iCharacter;
	}
}/* End main()*/
