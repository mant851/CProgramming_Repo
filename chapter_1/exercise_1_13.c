/*
 * This program is to print histrogram of length of words in its input.
 * Author: Manthan Nagar
 * Created: 25 June 2024
 * Modified: 25 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MAIN PROGRAM */
/*
 * main: funtion to print histogram of length of word in its input.
 */

int main(){
	int iCharacter; /* Input Character */
	int iTemp; /* temporary vaiable */
	while((iCharacter=getchar())!=EOF){
		if(iCharacter=='\t' || iCharacter==' ' || iCharacter=='\n'){
			putchar('\n');
			
		}
		else{
			putchar('*');
		}
	}
	
	
}/* End main()*/
