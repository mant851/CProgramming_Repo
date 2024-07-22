/**
 * Write a program for reverse polish notation calculator with modulus operator and provisionas for negative numbers.
 * Author: Manthan Nagar
 * Created: 16 July 2024
 * Modified: 16 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/** MARCO DEFINATIONS */
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100


int giStackPosition = 0; /*current stack postion*/
double gdValueStack[MAXVAL]; /*value stack*/
char gsBuffer[BUFSIZE]; /* buffer for ungetch */ 
int giNextFreePos = 0; /* next free position in buf */

/** FUNCTION PROTOTYPES */
int getop(char sInput[]);
void push(double dValue) ;
double pop(void);
int getch(void);
void ungetch(int);

/** MAIN PROGRAM */
/*
 * main: print the result of the given reverse polish notation with a modulus operator and provisions for negative numbers.
*/

int main(){
	int iType;
	double iOp2;
	char sInput[MAXOP];

	while((iType=getop(sInput)) != EOF){
	
		switch(iType){
			case NUMBER:
				push(atof(sInput));
				break;
			case '+': 
 				push(pop() + pop()); 
 				break; 
 			case '*': 
 				push(pop() * pop()); 
 				break; 
 			case '-': 
 				iOp2 = pop(); 
 				push(pop() - iOp2); 
 				break; 
 			case '/': 
 				iOp2 = pop(); 
 				if (iOp2 != 0.0) 
 					push(pop() / iOp2); 
				else 
					printf("error: zero divisor\n"); 
 				break; 
			case '%':
				iOp2 = pop();
                                if (iOp2 != 0.0)
                                        push((int)pop() % (int) iOp2);
                                else
                                        printf("error: zero divisor\n");
                                break;
 			case '\n': 
 				printf("\t%.8g\n", pop()); 
 				break; 
 			default: 
 				printf("error: unknown command %s\n", sInput); 
 				break; 
		}
	}
}


/*
 * push: insert element at top in the stack
 * Author: Manthan Nagar
 * Created: 16 July 2024
 * Modified: 16 July 2024
*/

void push(double dValue) 
 { 
 if (giStackPosition < MAXVAL) 
 	gdValueStack[giStackPosition++] = dValue; 
 else 
 	printf("error: stack full, can't push %g\n", dValue); 
 }

/*
 * pop: return and remove top most element of the stack.
 * Author: Manthan Nagar
 * Created: 16 July 2024
 * Modified: 16 July 2024
*/

double pop(void)
 {
 	if (giStackPosition> 0)
 		return gdValueStack[--giStackPosition];
 	else {
 		printf("error: stack empty\n");
 	return 0.0;
 	}
 }

/*
 * getop: return type of the given character whether it is a number or operand or any other.
 * Author: Manthan Nagar
 * Created: 16 July 2024
 * Modified: 16 July 2024
*/

int getop(char sToken[])
{
    int iIndex = 0 ;   // Index for current position in token array
    int iCharacter;   // Current character being processed

    // Skip whitespace characters
    while ((sToken[0] = iCharacter = getch()) == ' ' || iCharacter == '\t')
	    ;
    

    sToken[1] = '\0';  // Null-terminate the token string

    // If it's not a digit or a '.', return the character itself
    if (!isdigit(iCharacter) && iCharacter != '.' && iCharacter != '-')
        return iCharacter; // Not a number

    // Collect integer part
    if (isdigit(iCharacter))
    {
        while (isdigit(sToken[++iIndex] = iCharacter = getch()))
            ;
    }
    if (iCharacter == '-' || isdigit(iCharacter))
    {
    	while (isdigit(sToken[++iIndex] = iCharacter = getch()))
		;
    }

    // Collect fraction part
    if (iCharacter == '.')
    {
        while (isdigit(sToken[++iIndex] = iCharacter = getch()))
            ;
    }

    sToken[iIndex] = '\0'; // Null-terminate the token string

    if (iCharacter != EOF)
        ungetch(iCharacter); // Push back the character that is not part of the number

    if(strcmp(sToken,"-")==0)
	    return '-';

    return NUMBER;  // Return NUMBER to indicate a numeric operand
}


/*
 * getch: return character from the buffer 
 * Author: Manthan Nagar
 * Created: 16 July 2024
 * Modified: 16 July 2024
*/


int getch(void) /* get a (possibly pushed-back) character */ 
 { 
 return (giNextFreePos > 0) ? gsBuffer[--giNextFreePos] : getchar(); 
 } 


/*
 * ungetch: return position of rightmost occurance of a cChart in sStrings.
 * Author: Manthan Nagar
 * Created: 16 July 2024
 * Modified: 16 July 2024
*/

void ungetch(int iCharacter) /* push character back on input */
 {
 if (giNextFreePos >= BUFSIZE)
 	printf("ungetch: too many characters\n");
 else
 	gsBuffer[giNextFreePos++] = iCharacter;
 }
