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

int main(){
	printf("Program to convert Celsius to given Fahrenheit in reverse order.\n");
	printf("Fahrenheit\tCelsius\n");
	int fahr;
	for(fahr=300;fahr>=0;fahr = fahr-20){
	float celsius = (5.0/9.0) * (fahr-32.0);
	printf("%3d\t\t%3.4f\n",fahr,(5.0/9.0) * (fahr-32.0));
	}
	
}/* End main()*/
