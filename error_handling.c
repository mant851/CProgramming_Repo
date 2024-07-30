#include "error_handling.h"
#include <stdio.h>

// Function definitions
void handle_error(int error_code) {
    switch (error_code) {
        case ERROR_NONE:
            break;  // No error
        case ERROR_INVALID_INPUT:
            printf("Error %d: Invalid input entered.\n",ERROR_INVALID_INPUT);
            break;
        case ERROR_OUT_OF_RANGE:
            printf("Error %d: Input out of range.\n",ERROR_OUT_OF_RANGE);
            break;
        case ERROR_STEP_TOO_LARGE:
            printf("Error %d: Step size greater than upper bound.\n",ERROR_STEP_TOO_LARGE);
            break;
	case ZERO_DEVISION_ERROR:
	    printf("Error %d: Zero devision error\n",ZERO_DEVISION_ERROR);
	    break;
	case INVALID_CHARACTER_DETECTED:
	    printf("Error %d: Invalid Character Detected\n",INVALID_CHARACTER_DETECTED);
	    break;
	case INVALID_CHOICE:
	    printf("Error %d: Invalid Choice given\n",INVALID_CHOICE);
	    break;
	case INVALID_HEXADECIMAL:
	    printf("Error %d: Invalid Hexadecimal value given\n",INVALID_HEXADECIMAL);
	    break;
	case INPUT_UNDERFLOW:
            printf("Error %d: Input Should Not Be Empty\n",INPUT_UNDERFLOW);
	    break;
	case POSITION_OUT_OF_RANGE:
	    printf("Error %d: Position is out of range\n",POSITION_OUT_OF_RANGE);
	    break;
	case NBITS_OUT_OF_RANGE:
	    printf("Error %d: Number of bits is out of range.\n",NBITS_OUT_OF_RANGE);
	    break;
	case INVALID_BIT_POSITION:
	    printf("Error %d: The combination of position and number of bits is invalid \n",INVALID_BIT_POSITION);
	    break;
    	case ERROR_ROTATION_TOO_LARGE:
	    printf("Error %d:The number of bits to rotate is too large \n",ERROR_ROTATION_TOO_LARGE);
	    break;
	case ERROR_STRING_TOO_LONG:
	    printf("Error %d:The input string is too long. Please enter a shorter string. \n",ERROR_STRING_TOO_LONG);
	    break;
	case ERROR_INVALID_NOTATION:
            printf("Error %d: Invalid shorthand notation.\n",ERROR_INVALID_NOTATION);
            break;
        case ERROR_NON_ALPHANUMERIC:
            printf("Error %d: Input contains non-alphanumeric characters.\n",ERROR_NON_ALPHANUMERIC);
            break;
        case ERROR_INVALID_DASH_PLACEMENT:
            printf("Error %d: Invalid dash placement.\n",ERROR_INVALID_DASH_PLACEMENT);
            break;
        case ERROR_EMPTY_INPUT:
            printf("Error %d: Empty input.\n",ERROR_EMPTY_INPUT);
            break;
	case ERROR_INVALID_BASE:
            printf("Error %d: Invalid base. Base must be between 2 and 36.\n",ERROR_INVALID_BASE);
            break;
	case ERROR_INVALID_WIDTH:
            printf("Error %d: Invalid width. Minimum field width must be positive.\n",ERROR_INVALID_WIDTH);
            break;
        default:
            printf("Error: Unknown error.\n");
            break;
    }
}
