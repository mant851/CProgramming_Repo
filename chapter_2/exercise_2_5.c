/*
 * This program return first location in a sString1 where any character from the sString2 occurs.
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** FUNCTION PROTOTYPES*/
int any(char sString1[], char sString2[]);

/** MAIN PROGRAM */
/*
 * main: funtion to print the location of a character from where any character from the sString2 occurs.
 */

int main(){
        char sString1[] = "manthan"; //First String
        char sString2[]= "an"; // Second String
        int location = any(sString1, sString2);

	if(location==-1){
		printf("sString1 contains no characters from sString2");
	}
        printf("The location of a character will be %d \n",location);
        return 0;
}

/*
 * any: This funtion return first location in a sString1 where any character from the sString2 occurs.
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

int any(char sString1[], char sString2[]){
	int iIndexString1;
	int iIndexString2;
	for(iIndexString1=0;iIndexString1<strlen(sString1);iIndexString1++){
		for(iIndexString2=0;iIndexString2<strlen(sString2);iIndexString2++){
			if(sString1[iIndexString1]==sString2[iIndexString2]){
				return iIndexString1;
			}
		}
	}

	return -1;

}
