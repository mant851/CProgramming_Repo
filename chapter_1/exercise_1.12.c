/*
 * This program is to print one word per line.
 * Author: Manthan Nagar
 * Created: 25 June 2024
 * Modified: 25 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MAIN PROGRAM */
/*
 * main: funtion to print the one word per line.
 */

int main(){
	int c;
	while((c=getchar())!=EOF){
		if(c=='\t' || c=='\n' || c=='\t' || c==' '){
			putchar('\n');
		}

		else{
		    putchar(c);
		}
		
	}
	
}/* End main()*/
