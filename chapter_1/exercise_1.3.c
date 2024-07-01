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
 * main: convert corresponding Celsius to given Fahrenheit table with heading.
 */

int main(){
	printf("Program to convert Celsius to given Fahrenheit\n");
	printf("Fahrenheit\tCelsius\n");
	float lower = 0; /*Lower limit of temperature scale */ 
	float upper = 300; /*Upper limit of temperature scale */
	float step = 20; /* Step size */

	float fahr = lower; 
	while (fahr <= upper){
	float celsius = (5.0/9.0) * (fahr-32.0);
	printf("%3.0f\t\t%6.1f\n",fahr,celsius);
	fahr = fahr + step;
	}
}/* End main()*/
