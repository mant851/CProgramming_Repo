/**
 * Write a program to get a position of rightmost occurance of a cChart in sStrings.
 * Author: Manthan Nagar
 * Created: 12 July 2024
 * Modified: 12 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
/** MARCO DEFINATIONS */


/** FUNCTION PROTOTYPES */
double atof(char sStrings[]);

/** MAIN PROGRAM */
/*
 * main: print a position of rightmost occurance of a cChart in sStrings.
*/


double main(){
        char sStrings[] = "123.45e-6"; // input string
      	        
        double iOutput = atof(sStrings);
	
	printf("The number after conversion will be %g\n",iOutput);


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

	if(sStrings[iIndex+1] == '-')
	{
		iIndex = iIndex+2;
		iCounter = sStrings[iIndex] - '0';
		while(iCounter>0){
		iAns= iAns /10 ;

		iCounter--;
		
		}
		
	
	}
	else{
		iIndex = iIndex +1;
		iCounter = sStrings[iIndex]-'0';
		while(iCounter>0){

                iAns= iAns * 10 ;

                iCounter--;

                }

	}
	

	return iAns;	

}

