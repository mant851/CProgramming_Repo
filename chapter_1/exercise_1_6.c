/*
 * This program is to varify that the expression getchar() != EOF is 0 or 1
 * Author: Manthan Nagar
 * Created: 24 June 2024
 * Modified: 24 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MAIN PROGRAM */
/*
 * main: function varifies the expression getchar() != EOF is 0 or 1
 */

int main(){

	int iCharacter; // Given input character
	if (iCharacter = getchar()!=EOF)
		printf("0");
	else
		printf("1");	
}/* End main()*/
