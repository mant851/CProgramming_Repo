/*
 * This program is to copy its input to its output, replacing each backspace by \b,  and each backslash by \\.This makes tabs and backspace unambigous way.
 * Author: Manthan Nagar
 * Created: 24 June 2024
 * Modified: 24 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MAIN PROGRAM */
/*
 * main: funtion to copy its input to its output.
 */

int main(){
	int c;
	while((c=getchar())!=EOF){
		if(c=='\t'){
		    putchar('\t');
		    putchar('\\');

		}

		else if(c=='\b'){
		    putchar('\b');
		}
		else if(c=='\\'){
		    putchar('\\');
		}
		else{
		    putchar(c);
		}
		
	}
	
}/* End main()*/
