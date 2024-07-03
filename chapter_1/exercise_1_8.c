/*
 * This program is to get the count of new lines, blancks and tabs.
 * Author: Manthan Nagar
 * Created: 24 June 2024
 * Modified: 24 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MAIN PROGRAM */
/*
 * main: funtion to get count of new lines, blancks and tabs.
 */

int main(){
	int c;
	int cNewline = 0; 
	int cblancks = 0;
	int ctabs = 0;

	while((c = getchar())!=EOF){
		if(c =='\n'){
			cNewline++;
		}
		else if (c ==' '){
			cblancks++;
		}
		else if(c =='\t'){
			ctabs++;
		}
	}
	printf("count of newline=%d\ncount of blancks=%d\ncount of tabs=%d",cNewline,cblancks,ctabs);
	
}/* End main()*/
