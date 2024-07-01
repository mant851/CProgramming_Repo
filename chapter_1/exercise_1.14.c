/*
 * This program is to print frequency of different characters in the input.
 * Author: Manthan Nagar
 * Created: 25 June 2024
 * Modified: 25 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MAIN PROGRAM */
/*
 * main: funtion to print frequency of different characters in the input.
 */

int main(){
	int c;
	int temp;
	int nChars[26];
	for(int i=0;i<=25;i++){
		nChars[i]=0;
	}
	while((c=getchar())!=EOF){
		if(c>=65 || c<=90){
			nChars[c-'A']++;

		}
		if(c>=97 || c<=122){
			nChars[c-'a']++;
		}
		
	}
	for(int i=0;i<26;i++){
		if(nChars[i]>0){
		printf("%c\t",i+97);
		for(int j=0;j<nChars[i];j++){
			printf("*");
			}
		printf("\n");
		}
	}

	
}/* End main()*/
