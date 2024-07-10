/*
 * This program to reduce time complexity of binary search.
 * Author: Manthan Nagar
 * Created: 9 July 2024
 * Modified: 9 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<time.h>

/** FUNCTION PROTOTYPES */
int binarySearch(int iKey,int iArray[],int iSize);
int binarySearchOptimized(int iKey, int iArray[],int iSize);

/** MAIN PROGRAM */
/*
 * main: reduce the time complexity of binary search using with help of if else.
 */

int main(){

        int iKey=5;
	int iArray[] = {0,1,2,3,5,8,6};
	int iSize = 7;
	
	int iIndex;

	clock_t start = clock();
	
	iIndex = binarySearch(iKey,iArray,iSize);

	clock_t end = clock();

	double dSeconds = (double)(end-start)/ CLOCKS_PER_SEC ;

	printf("Time taken for binary search is %f \n",dSeconds);



	start = clock();

        iIndex = binarySearchOptimized(iKey,iArray,iSize);

        end = clock();

        dSeconds = (double)(end-start)/ CLOCKS_PER_SEC ;

        printf("Time taken for binary search optimized is %f \n",dSeconds);
	

}

/*
 * binarySearch: This is a program of binary search.
 * Author: Manthan Nagar
 * Created: 9 July 2024
 * Modified: 9 July 2024
 */

int binarySearch(int iKey,int iArray[],int iSize){

	int iLow,iHigh,iMid;

	iLow= 0;
	iHigh = iSize-1;
	while(iLow<iHigh){
		
		iMid = (iLow+iHigh)/2;
		if(iKey < iArray[iMid])
			iHigh = iMid -1;
		else if(iKey > iArray[iMid])
			iLow = iMid +1;
		else
			return iMid;
	
	}
	return -1;
}

/*
 * binarySearchOptimized: This program to reduce time complexity of binary search.
 * Author: Manthan Nagar
 * Created: 9 July 2024
 * Modified: 9 July 2024
 */

int binarySearchOptimized(int iKey, int iArray[],int iSize){
	

        int iLow,iHigh,iMid;

        iLow= 0;
        iHigh = iSize-1;
        while(iLow<iHigh){

                iMid = (iLow+iHigh)/2;
		
		if(iKey == iArray[iMid])
			return iMid;
                if(iKey < iArray[iMid])
                        iHigh = iMid -1;
                else
                        iLow = iMid +1;

        }
        return -1;
}
