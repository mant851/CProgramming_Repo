/*
 * This program is deletes each character of fisrt string that match with any character of other string.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** FUNCTION PROTOTYPES*/
void squeeze(char sSource[], char sCompare[]);

/** MAIN PROGRAM */
/*
 * main: funtion to print string after removing each character from the given other string.
 */

int main(){
        char sSource[] = "manthan"; //source string 
	char sCompare[]= "an"; // characters that will be deleted
	squeeze(sSource, sCompare);
	printf("string would be %s after removing each character of %s \n",sSource,sCompare);
        return 0;
}

/*
 * convertToHexadecimal: This funtion return decimal value of hexadecimal string characters.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */

void squeeze(char sSource[], char sCompare[]) {

    int removeMap[256] = {0}; // Assuming ASCII characters

    
    for (int iCompareIndex = 0; sCompare[iCompareIndex] != '\0'; iCompareIndex++) {
        removeMap[(unsigned char)sCompare[iCompareIndex]] = 1;
    }

  
    int iSourceIndex, iFilteredIndex;
    for (iSourceIndex = iFilteredIndex = 0; sSource[iSourceIndex] != '\0'; iSourceIndex++) {
        if (removeMap[(unsigned char)sSource[iSourceIndex]] == 0) {
            sSource[iFilteredIndex++] = sSource[iSourceIndex];
        }
    }

    sSource[iFilteredIndex] = '\0'; 
}


