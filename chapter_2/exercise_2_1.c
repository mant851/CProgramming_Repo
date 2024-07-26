/*
 * This program determines the ranges of various variable types,
 * both signed and unsigned, using calculations and standard headers.
 * It also provides an interactive user experience and error handling.
 * Author: Manthan Nagar
 * Created: 7 July 2024
 * Modified: 26 July 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include "../error_handling.h"

/** MAIN PROGRAM */
int main() {
    int choice;
    int result;

    while (1) {
        /* Display menu to the user */
        printf("\nChoose an option to display ranges:\n");
        printf("1. Display ranges using calculations\n");
        printf("2. Display ranges using standard headers\n");
        printf("3. Exit\n");

        /* Read user's choice */
        result = scanf("%d", &choice);
        
        if (result != 1) {
            // Clear the input buffer in case of invalid input
            while (getchar() != '\n');
            handle_error(ERROR_INVALID_INPUT);
            continue;
        }

        /* Execute based on user's choice */
        switch (choice) {
            case 1:
                /* Ranges using calculations */
                printf("\nRanges of variables using calculation\n");

                printf("Minimum Signed Char: %d\n", -(int)((unsigned char)~0 >> 1) - 1);
                printf("Maximum Signed Char: %d\n", (int)((unsigned char)~0 >> 1));

                printf("Minimum Signed Short: %d\n", -(int)((unsigned short)~0 >> 1) - 1);
                printf("Maximum Signed Short: %d\n", (int)((unsigned short)~0 >> 1));

                printf("Minimum Signed Int: %d\n", -(int)((unsigned int)~0 >> 1) - 1);
                printf("Maximum Signed Int: %d\n", (int)((unsigned int)~0 >> 1));

                printf("Minimum Signed Long: %ld\n", -(long)((unsigned long)~0 >> 1) - 1);
                printf("Maximum Signed Long: %ld\n", (long)((unsigned long)~0 >> 1));

                printf("\nUnsigned Maximum Values\n");

                printf("Maximum Unsigned Char: %d\n", (unsigned char)~0);
                printf("Maximum Unsigned Short: %d\n", (unsigned short)~0);
                printf("Maximum Unsigned Int: %u\n", (unsigned int)~0);
                printf("Maximum Unsigned Long: %lu\n", (unsigned long)~0UL);
                break;

            case 2:
                /* Ranges using standard headers */
                printf("\nRanges of various integer and floating-point types from standard headers:\n");

                printf("Minimum Signed Char: %d\n", SCHAR_MIN);
                printf("Maximum Signed Char: %d\n", SCHAR_MAX);

                printf("Minimum Signed Short: %d\n", SHRT_MIN);
                printf("Maximum Signed Short: %d\n", SHRT_MAX);

                printf("Minimum Signed Int: %d\n", INT_MIN);
                printf("Maximum Signed Int: %d\n", INT_MAX);

                printf("Minimum Signed Long: %ld\n", LONG_MIN);
                printf("Maximum Signed Long: %ld\n", LONG_MAX);

                printf("Minimum Signed Long Long: %lld\n", LLONG_MIN);
                printf("Maximum Signed Long Long: %lld\n", LLONG_MAX);

                printf("Minimum Float: %E\n", FLT_MIN);
                printf("Maximum Float: %E\n", FLT_MAX);

                printf("Minimum Double: %E\n", DBL_MIN);
                printf("Maximum Double: %E\n", DBL_MAX);

                printf("Minimum Long Double: %LE\n", LDBL_MIN);
                printf("Maximum Long Double: %LE\n", LDBL_MAX);

                printf("\nUnsigned Maximum Values\n");

                printf("Maximum Unsigned Char: %d\n", UCHAR_MAX);
                printf("Maximum Unsigned Short: %d\n", USHRT_MAX);
                printf("Maximum Unsigned Int: %u\n", UINT_MAX);
                printf("Maximum Unsigned Long: %lu\n", ULONG_MAX);
                printf("Maximum Unsigned Long Long: %llu\n", ULLONG_MAX);
                break;

            case 3:
                /* Exit the program */
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                /* Handle invalid choice */
                handle_error(ERROR_INVALID_INPUT);
                break;
        }
    }

    return 0;
}
