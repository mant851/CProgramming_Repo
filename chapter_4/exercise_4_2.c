/**
 * Write a program to get a position of rightmost occurance of a cChart in sStrings.
 * Author: Manthan Nagar
 * Created: 12 July 2024
 * Modified: 12 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
#include "../error_handling.h"

/** MARCO DEFINATIONS */
#define MAX_INPUT_SIZE 256

/** FUNCTION PROTOTYPES */
double atof(char sStrings[]);

/** MAIN PROGRAM */
/*
 * main: print a position of rightmost occurance of a cChart in sStrings.
*/


double main() {
    char sStrings[MAX_INPUT_SIZE];
    printf("Enter a string to convert to a floating-point number (e.g., 12.3e16): ");
    if (scanf("%s", sStrings) != 1) {
        handle_error(ERROR_INVALID_INPUT);
        return 1;
    }

    // Convert the string to a floating-point number
    double iOutput = atof(sStrings);
    
    // Print the result
    printf("The number after conversion is %.17g\n", iOutput);

    return 0;
}


/*
 * strindex: return position of rightmost occurance of a cChart in sStrings.
 * Author: Manthan Nagar
 * Created: 11 July 2024
 * Modified: 11 July 2024
*/

double atof(char sStrings[]){
	
	
	int iIndex = 0 ;
       	double iAns = 0;
	int iNegative = 0;

	if (sStrings[iIndex] == '-'){
		iIndex++;
		iNegative = 1;
	}
	
	while((sStrings[iIndex]!='e') && (sStrings[iIndex]!='.')){
		
		iAns= (iAns *10) + (sStrings[iIndex] - '0') ;
		
		iIndex++;
	
	}
	int iFloatpoint = 0;
	if(sStrings[iIndex]=='.'){
		iIndex++;
		while (sStrings[iIndex]!='e'){
			
		
		iAns= iAns *10 + (sStrings[iIndex] - '0') ;
		iFloatpoint++;
		iIndex++;
		}	
	}
	
	int iCounter ;
	for(iCounter=0;iCounter<iFloatpoint;iCounter++){
		iAns = iAns/10;
	}
	iCounter = 0;
	if(sStrings[iIndex+1] == '-')
	{
		iIndex = iIndex+2;

		while(iIndex< strlen(sStrings)) {

		  iCounter = iCounter*10 + sStrings[iIndex]-'0';
		  iIndex++;
		}

		while(iCounter>0){

		iAns= iAns /10 ;

		iCounter--;
		
		}
		
	
	}
	else{
		iIndex = iIndex +1;
		while(iIndex< strlen(sStrings)) {

		  iCounter = iCounter*10 + sStrings[iIndex]-'0';
		  iIndex++;
		}

		while(iCounter>0){

                iAns= iAns * 10 ;

                iCounter--;

                }

	}
	
	if(iNegative == 1){

		return (-1 * iAns);	
	}
	return iAns;	

}

