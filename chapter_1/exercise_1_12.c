/*
 * This program is to print one word per line.
 * Author: Manthan Nagar
 * Created: 25 June 2024
 * Modified: 25 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include "../error_handling.h" 

/** MAIN PROGRAM */
/*
 * main: Funtion to print the one word per line.
 */

int main(){
	int iCharacter; /* Input character */
	while((iCharacter=getchar())!=EOF){
		if(iCharacter=='\t' || iCharacter=='\n' || iCharacter==' '){
			putchar('\n'); /* Output a newline to separate words */ 
		}
		
		else {
			putchar(iCharacter); // Output the character as-is if it's a letter
		}

	}	
}/* End main()*/
