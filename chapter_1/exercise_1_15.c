/*
 * This program is to print the corresponding Celsius to given Fahrenheit table using function.
 * Author: Manthan Nagar
 * Created: 25 June 2024
 * Modified: 25 June 2024
 */

/** REQUIRED HEADER FILES */
#include<stdio.h>

/** FUNCTION PROTOTYPE*/
int fahrtocelsius(float fFahr);

/** MAIN PROGRAM */
/*
 * main: convert corresponding Celsius to given Fahrenheit table with using function.
 */

int main(){
	printf("Program to convert Celsius to given Fahrenheit\n");
	printf("Fahrenheit\tCelsius\n");
	float fLower = 0; /*Lower limit of temperature scale */ 
	float fUpper = 300; /*Upper limit of temperature scale */
	float fStep = 20; /* Step size */

	float fFahr = fLower; 
	while (fFahr <= fUpper){
	float fCelsius = fahrtocelsius(fFahr);
	printf("%3.0f\t\t%6.1f\n",fFahr,fCelsius);
	fFahr = fFahr + fStep;
	}
}/* End main()*/

/*
 * fahrtocelsius: This function returns celcius value from given fahrenheit.
 * Author: Manthan Nagar
 * Created: 25 June 2024
 * Modified: 25 June 2024
 */

int fahrtocelsius(float fFahr){
	float fCelcius = (5.0/9.0) * (fFahr-32.0);
	return fCelcius;
}
