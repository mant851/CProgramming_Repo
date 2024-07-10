/*
 * This program returns iX with the Nbits that begin at position iPosition set to the rightmost nbits of iY, leaving the other bits unchanged. 
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>

/** FUNCTION PROTOTYPES*/
int setbits(int iX,int iPosition,int iNbits,int iY);

/** MAIN PROGRAM */
/*
 * main: funtion to print the iX with the Nbits that begin at position iPosition set to the rightmost nbits of iY, leaving the other bits unchanged. 
 */

int main(){

	int iX= 183;
	int iPosition = 4;
	int iNbits = 3;
	int iY = 16;
        printf("iX after the setbits operation will be %d \n",setbits(iX,iPosition,iNbits,iY));
        return 0;
}

/*
 * setbits:This program returns iX with the Nbits that begin at position iPosition set to the rightmost nbits of iY, leaving the other bits unchanged.
 * Author:Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

int setbits(int iX,int iPosition,int iNbits,int iY){

	return (iX & ((~0 << (iPosition + 1)) | (~(~0 << (iPosition + 1 - iNbits))))) | ((iY & ~(~0 << iNbits)) << (iPosition + 1 - iNbits));
}
