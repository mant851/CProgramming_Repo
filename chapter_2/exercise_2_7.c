/*
 * This program returns iInput with the iNbits that begin at position iPosition inverted.
 * Author: Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** FUNCTION PROTOTYPES*/
int invert(int iX,int iPosition,int iNbit);

/** MAIN PROGRAM */
/*
 * main: iInput with the iNbits that begin at position iPosition inverted.
 */

int main(){

        int iInput= 183; // input number
        int iPosition = 4; // position from which the bits will be inverted
        int iNbits = 3; // total number of bits from iPositionth that will be inverted

        printf("iInput after the setbits operation will be %d \n",invert(iInput,iPosition,iNbits));
        return 0;
}

/*
 * iInput: iInput with the iNbits that begin at position iPosition inverted.
 * Author:Manthan Nagar
 * Created: 8 July 2024
 * Modified: 8 July 2024
 */

int invert(int iInput, int iPosition, int iNbits){
	
	return iInput ^ (~(~0 << iNbits) << iPosition+1-iNbits );

}
