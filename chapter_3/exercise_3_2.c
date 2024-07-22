/**
 * Write a program to converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string sStringt to sStrings. Using a switch case also converting escape sequences into the real characters.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
void escape(char sStrings[], char sStringt[]);

/** MAIN PROGRAM */
/*
 * main: takes string sStringt and put the real characters in place of tab and newLine.
*/


int main(){
	char sStrings[]= "Hello		Manthan		here";
	char sStringt[1000];
	escape(sStrings, sStringt);
	printf("%s\n", sStringt);
	return 0;
}


/*
 * escape: converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string sStringt to sStrings. Using a switch case also converting escape sequences into the real characters.
 * Author: Manthan Nagar
 * Created: 10 July 2024
 * Modified: 10 July 2024
*/

void escape(char sStrings[], char sStringt[]){
	char cCharacter;
	int iIndexs, iIndext;
	iIndexs=iIndext=0;
	while((sStrings[iIndexs])!='\0'){
		switch(sStrings[iIndexs]){
			case '\n':
				sStringt[iIndext] = '\\';
				iIndext++;
				sStringt[iIndext] = 'n';
				
				break;
			case '\t':
				sStringt[iIndext] = '\\';
				iIndext++;
				sStringt[iIndext] = 't';
				
				break;
			default:
				sStringt[iIndext]=sStrings[iIndexs];
				break;
		}
		iIndexs++;
		iIndext++;
	}
	sStringt[iIndext] = '\0';

}
