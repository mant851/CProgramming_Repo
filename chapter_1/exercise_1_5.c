/*
 * This program is to print the corresponding Celsius to given Fahrenheit table.
 * Author: Manthan Nagar
 * Created: 24 June 2024
 * Modified: 24 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MAIN PROGRAM */
/*
 * main: convert corresponding Celsius to given Fahrenheit table reverse order.
 */

#include <stdio.h>

int main() {
    
    printf("Program to convert Celsius to given Fahrenheit in reverse order.\n");
    printf("Fahrenheit\tCelsius\n");
    
    int ffahr;  /* Declare variable to hold Fahrenheit values */
    
  
    for(ffahr = 300; ffahr >= 0; ffahr = ffahr - 20) {
        
        float fcelsius = (5.0 / 9.0) * (ffahr - 32.0); /*Calculate Celsius equivalent for current Fahrenheit value*/
        
        printf("%3d\t\t%3.4f\n", ffahr, fcelsius);
    }
    
    return 0;  // Exit program
}

	
}/* End main()*/
