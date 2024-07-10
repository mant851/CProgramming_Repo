/*
 * This program returns the value of the integer iInput rotated to the right by Nbits positions
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** FUNCTION PROTOTYPES*/
int rightRotationInput(int iInput,int iNbit);

/** MAIN PROGRAM */
/*
 * main: prints the value of the integer iInput rotated to the right by Nbits positions
 */

int main(){

        int iInput= 46593; // input number
        int iNbits = 5; // total number of bits from iPositionth that will be inverted

        printf("iInput after the rotation operation will be %d \n",rightRotationInput(iInput,iNbits));
        return 0;
}

/*
 * iInput: returns the value of the integer iInput rotated to the right by Nbits positions.
 * Author:Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

int rightRotationInput(int iInput, int iNbits){
	int iTemp = iInput; // Temparory variable to store input
	int iIndex;
	for(iIndex=1;iIndex<=iNbits;iIndex++){
		iTemp = (iTemp<<1) | (( (iTemp >> sizeof(int)*8 -1) ));
		
	}

        return iTemp;

}
