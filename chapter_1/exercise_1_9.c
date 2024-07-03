/*
 * This program is to copy its input to its output, replacing each string of one of more blancks by a single blanck.
 * Author: Manthan Nagar
 * Created: 24 June 2024
 * Modified: 24 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#define BLANCK '-'
/** MAIN PROGRAM */
/*
 * main: function to copy inputto its output, replacin geach string of one of more blancksby a single blanck.
 */

int main(){
	int c,b;
	b = BLANCK;
	while((c=getchar())!=EOF){
	if(c==' '){
		if(b!=' '){
		 putchar(c);
	}
	}
	else{
		putchar(c);
	}
	b = c;
	}
}/* End main()*/
