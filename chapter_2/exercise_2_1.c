/*
 * This program is to print ranges of variables.
 * Author: Manthan Nagar
 * Created: 7 July 2024
 * Modified: 7 July 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<limits.h>
#include<float.h>
/** MAIN PROGRAM */
/*
 * main: funtion to print range of variables
 */

int main(){
        
	printf("Ranges of variables using calculation\n");

	printf("Minimum Signed Char %d\n", -(int)((unsigned char)~0 >> 1) - 1);
	printf("Maximum Signed Char %d\n", (int)((unsigned char)~0 >> 1));

	printf("Minimum Signed Short %d\n", -(int)((unsigned short)~0 >> 1) - 1);
	printf("Maximum Signed Short %d\n", (int)((unsigned short)~0 >> 1));

	printf("Minimum Signed Int %d\n", -(int)((unsigned int)~0 >> 1) - 1);
 	printf("Maximum Signed Int %d\n", (int)((unsigned int)~0 >> 1));

 	printf("Minimum Signed Long %ld\n", -(long)((unsigned long)~0 >> 1) - 1);
 	printf("Maximum signed Long %ld\n", (long)((unsigned long)~0 >> 1));

    	/* Unsigned Maximum Values */

 	printf("Maximum Unsigned Char %d\n", (unsigned char)~0);
        printf("Maximum Unsigned Short %d\n", (unsigned short)~0);
        printf("Maximum Unsigned Int %u\n", (unsigned int)~0);
        printf("Maximum Unsigned Long %lu\n\n", (unsigned long)~0UL);


        /* ranges of various floating-point types from standard headers */
        printf("Ranges of various integer and floating-point types from standard headers:\n");
        printf("Minimum Signed Char %d\n", SCHAR_MIN);
        printf("Maximum Signed Char %d\n", SCHAR_MAX);

        printf("Minimum Signed Short %d\n", SHRT_MIN);
        printf("Maximum Signed Short %d\n", SHRT_MAX);

        printf("Minimum Signed Int %d\n", INT_MIN);
        printf("Maximum Signed Int %d\n", INT_MAX);

        printf("Minimum Signed Long %ld\n", LONG_MIN);
        printf("Maximum signed Long %ld\n", LONG_MAX);

        printf("Minimum Signed Long Long %lld\n", LLONG_MIN);
        printf("Maximum Signed Long Long %lld\n", LLONG_MAX);

        printf("Minimum Float %E\n", FLT_MIN);
        printf("Maximum Float %E\n", FLT_MAX);

        printf("Minimum Double %E\n", DBL_MIN);
        printf("Maximum Double %E\n", DBL_MAX);

        printf("Minimum Long Double %LE\n", LDBL_MIN);
        printf("Maximum Long Double %LE\n", LDBL_MAX);

        /* Unsigned Maximum Values */

        printf("Maximum Unsigned Char %d\n", UCHAR_MAX);
        printf("Maximum Unsigned Short %d\n", USHRT_MAX);
        printf("Maximum Unsigned Int %u\n", UINT_MAX);
        printf("Maximum Unsigned Long %lu\n", ULONG_MAX);
        printf("Maximum Unsigned Long Long %llu\n", ULLONG_MAX);

        return 0;

}
