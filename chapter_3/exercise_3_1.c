/*
 * This program reduces the time complexity of binary search and makes it interactive.
 * Author: Manthan Nagar
 * Created: 9 July 2024
 * Modified: 9 July 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <time.h>
#include "../error_handling.h"

/** MACRO DEFINATIONS */
#define MAX_SIZE 100

/** FUNCTION PROTOTYPES */
int binarySearch(int iKey, int iArray[], int iSize);
int binarySearchOptimized(int iKey, int iArray[], int iSize);


/** MAIN PROGRAM */
/*
 * main: Perform binary search and optimized binary search.
 */

int main() {
    int iKey;
    int iSize;
    int iArray[MAX_SIZE];

    /* Get array size from user */
    printf("Enter the number of elements in the array (up to %d): ", MAX_SIZE);
    if (scanf("%d", &iSize) != 1 || iSize <= 0 || iSize > MAX_SIZE) {
        handle_error(ERROR_INVALID_INPUT);
        return 1;
    }

    /* Get array elements from user */
    printf("Enter %d elements in ascending order:\n", iSize);
    for (int i = 0; i < iSize; i++) {
        if (scanf("%d", &iArray[i]) != 1) {
            handle_error(ERROR_INVALID_INPUT);
            return 1;
        }
    }

    /* Get the key to search for from user */
    printf("Enter the key to search for: ");
    if (scanf("%d", &iKey) != 1) {
        handle_error(ERROR_INVALID_INPUT);
        return 1;
    }

    int iIndex;

    /* Time the binary search */
    clock_t start = clock();
    iIndex = binarySearch(iKey, iArray, iSize);
    clock_t end = clock();
    double dSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for binary search: %f seconds\n", dSeconds);
    if (iIndex == -1) {
        printf("The key %d was not found in the array using binary search.\n", iKey);
    } else {
        printf("Index found by binary search: %d\n", iIndex);
    }

    /* Time the optimized binary search */
    start = clock();
    iIndex = binarySearchOptimized(iKey, iArray, iSize);
    end = clock();
    dSeconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for optimized binary search: %f seconds\n", dSeconds);
    if (iIndex == -1) {
        printf("The key %d was not found in the array using optimized binary search.\n", iKey);
    } else {
        printf("Index found by optimized binary search: %d\n", iIndex);
    }
    return 0;
}

/*
 * binarySearch: Performs a binary search on a sorted array.
 * Author: Manthan Nagar
 * Created: 9 July 2024
 * Modified: 9 July 2024
 */
int binarySearch(int iKey, int iArray[], int iSize) {
    int iLow = 0;
    int iHigh = iSize - 1;
    while (iLow <= iHigh) {
        int iMid = (iLow + iHigh) / 2;
        if (iKey < iArray[iMid])
            iHigh = iMid - 1;
        else if (iKey > iArray[iMid])
            iLow = iMid + 1;
        else
            return iMid;
    }
    return -1;
}

/*
 * binarySearchOptimized: Optimized binary search implementation.
 * Author: Manthan Nagar
 * Created: 9 July 2024
 * Modified: 9 July 2024
 */
int binarySearchOptimized(int iKey, int iArray[], int iSize) {
    int iLow = 0;
    int iHigh = iSize - 1;
    while (iLow <= iHigh) {
        int iMid = (iLow + iHigh) / 2;
        if (iKey == iArray[iMid])
            return iMid;
        if (iKey < iArray[iMid])
            iHigh = iMid - 1;
        else
            iLow = iMid + 1;
    }
    return -1;
}


