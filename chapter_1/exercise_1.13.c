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
	int c;
	int temp;
	while((c=getchar())!=EOF){
		if(c=='\t' || c==' ' || c=='\n'){
			putchar('\n');
			
		}
		else{
			putchar('*');
		}
	}
	
	
}/* End main()*/
