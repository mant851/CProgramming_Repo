/*
 * This program is to print the corresponding Fahrenheit to given Celsius table.
 * Author: Manthan Nagar
 * Created: 24 June 2024
 * Modified: 24 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** MAIN PROGRAM */
/*
 * main: convert corresponding Fahrenheit to given Celsius table with heading.
 */

int main(){
	printf("Program to convert Fahrenheit to given Celsius\n");
	printf("Celsius\tFahrenheit\n");
	float lower = 0; /*Lower limit of temperature scale */ 
	float upper = 300; /*Upper limit of temperature scale */
	float step = 20; /* Step size */

	float celsius = lower; 
	while (celsius <= upper){
	float fahr = ((9.0/5.0) * celsius) + 32.0;
	printf("%3.0f\t\t%6.1f\n",celsius,fahr);
	celsius = celsius + step;
	}
}/* End main()*/
