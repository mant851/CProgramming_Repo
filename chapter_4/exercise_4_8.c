/**
 * Write a program for reverse polish notation calculator with the given functionality.
 * Author: Manthan Nagar
 * Created: 17 July 2024
 * Modified: 17 July 2024
*/


/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

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
	int iType; // type of the given character
	double dOp2; // temporary opeand store
	char sInput[MAXOP]; // input stack 

	while((iType=getop(sInput)) != EOF){
	
		switch(iType){
			case NUMBER: // push the number into the stack
				push(atof(sInput));
				break;
			case '+': // addition operation
 				push(pop() + pop()); 
 				break; 
 			case '*': // multiplication operation
 				push(pop() * pop()); 
 				break; 
 			case '-': // substration operation
 				dOp2 = pop(); 
 				push(pop() - dOp2); 
 				break; 
 			case '/': // divison operation
 				dOp2 = pop(); 
 				if (dOp2 != 0.0) 
 					push(pop() / dOp2); 
				else 
					printf("error: zero divisor\n"); 
 				break; 
			case '%': // modulus operation
				dOp2 = pop();
                                if (dOp2 != 0.0)
                                        push((int)pop() % (int) dOp2);
                                else
                                        printf("error: zero divisor\n");
                                break;
 			case '\n': 
 				printf("\t%.8g\n", pop()); 
 				break;
			case '?': // print top element without deleting element
				dOp2 = pop();
				printf("\t%.8g\n", dOp2);
				push(dOp2);
				break;
			
			case 'd': // duplicate top value
				dOp2 = pop();
				push(dOp2);
				push(dOp2);
				break;

			case '#': // swap the top two values
				double dTemp;
				dOp2 = pop();
				dTemp = pop();
				push(dOp2);
				push(dTemp);
				break;
			case 'k': // clear the stack
				giStackPosition = 0;
				break;
			case 's': // sine of the top of the stack
				push(sin(pop()));
				break;
			case 'c': // cosine of the top of the stack
				push(cos(pop()));
				break;
			case 'e': // exponent of the top of the stack
				push(exp(pop()));
				break;
			case 'p': // powew of the top two value of the stack
				dOp2= pop();
				push(pow(pop(),dOp2));
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
 * Created: 17 July 2024
 * Modified: 17 July 2024
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
 * Created: 17 July 2024
 * Modified: 17 July 2024
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
 * Created: 17 July 2024
 * Modified: 17 July 2024
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
 * Created: 17 July 2024
 * Modified: 17 July 2024
*/


int getch(void) /* get a (possibly pushed-back) character */ 
 { 
 return (giNextFreePos > 0) ? gsBuffer[--giNextFreePos] : getchar(); 
 int iCharacter;
 if(giNextFreePos!=0)
        iCharacter = giNextFreePos;
    else
        iCharacter = getchar();

    giNextFreePos =0;
    return iCharacter;
 } 


/*
 * ungetch: push character back on the buffer
 * Author: Manthan Nagar
 * Created: 17 July 2024
 * Modified: 17 July 2024
*/

void ungetch(int iCharacter) /* push character back on input */
 {
 if (giNextFreePos >= BUFSIZE)
 	printf("ungetch: too many characters\n");
 else
 	gsBuffer[giNextFreePos++] = iCharacter;
 }

/*
 * ungetch: it will push the entire input back into the buffer using ungetch.
 * Author: Manthan Nagar
 * Created: 17 July 2024
 * Modified: 17 July 2024
*/

void ungets(char sInput[]) /* push character back on input */
 {
    int iLength = strlen(sInput);
    while (iLength > 0) {
        ungetch(sInput[--iLength]);
    }	
 }


