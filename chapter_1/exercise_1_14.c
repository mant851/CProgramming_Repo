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
    int iChar;
    int iTemp; /* temporary value will be store */
    int nChars[26] = {0};  /* Array to store counts of each letter */

    for (int iIndex = 0; iIndex < 26; iIndex++) {
        nChars[iIndex] = 0;
    }

    while ((iChar = getchar()) != EOF) {
        if (iChar >= 'A' && iChar <= 'Z') {
            nChars[iChar - 'A']++;
        }
        if (iChar >= 'a' && iChar <= 'z') {
            nChars[iChar - 'a']++;
        }
    }

    for (int iIndex = 0; iIndex < 26; iIndex++) {
        if (nChars[iIndex] > 0) {
            printf("%c\t", iIndex + 'a');
            for (int j = 0; j < nChars[iIndex]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;

	
}/* End main()*/
