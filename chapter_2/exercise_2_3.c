/*
 * This program is write a function to convert string to hexadecimal digit.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<math.h>
#include<string.h>
/** FUNCTION PROTOTYPES*/
int convertToHexadecimal(char sHexChar[]);
/** MAIN PROGRAM */
/*
 * main: funtion to print hexadecimal digit of string.
 */

int main(){
	char sHexChar[]= "12A";
	int iResult = convertToHexadecimal(sHexChar);
	printf("Result is %d\n",iResult);
	return 0;
}

/*
 * convertToHexadecimal: This funtion return decimal value of hexadecimal string characters.
 * Author: Manthan Nagar
 * Created: 4 July 2024
 * Modified: 4 July 2024
 */


int convertToHexadecimal(char sHexChar[]){
	int iIndex = strlen(sHexChar)-1; //current index element 
	int iResult = 0;// current result
	int iPower = 0;// power of the current index element
	while((sHexChar[iIndex]>='0'&& sHexChar[iIndex] <= '9') || (sHexChar[iIndex]>='A' && sHexChar[iIndex]<='F')|| (sHexChar[iIndex]>='a' && sHexChar[iIndex]<='f')){
		if(sHexChar[iIndex]>='0'&& sHexChar[iIndex] <= '9'){
			iResult += pow(16,iPower) * (sHexChar[iIndex] - '0');
        		
		}
		else if(sHexChar[iIndex]>='A' && sHexChar[iIndex]<='F'){

 			iResult += pow(16,iPower) * (sHexChar[iIndex] - 'A'+ 10);  

		}
		else if(sHexChar[iIndex]>='a' && sHexChar[iIndex]<='f'){

                        iResult += pow(16,iPower) * (sHexChar[iIndex] - 'a'+ 10);

                }
			iIndex--;
			iPower++;
	}

	return iResult;
}

