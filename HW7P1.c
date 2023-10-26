/*  Homework 7
    Problem 1
    by: Adrian De Souza
    CS1412
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


typedef struct{

int denom;
int numerator;

} fract_t;

void scan_fraction(fract_t *num);
void add_fractions(fract_t num1, fract_t num2, fract_t *numAns);
void sub_fractions(fract_t num1, fract_t num2, fract_t *numAns);
void multiply_fractions(fract_t num1, fract_t num2, fract_t *numAns, char op);
void divide_fractions(fract_t num1, fract_t num2, fract_t *numAns);
void print_fractions(fract_t num1, fract_t num2, fract_t numAns, char op);
int find_gcd (fract_t numAns);
void reduce_fraction(fract_t num1, fract_t num2, fract_t *numAns, int gcd);


void scan_fraction(fract_t *num){

    char dummy;

        printf("Please enter your numerator: ");
        scanf("%d", &(num->numerator));
        printf("Please enter your denominator: ");
        scanf("%d%c", &(num->denom), &dummy);

}


int find_gcd(fract_t numAns) {
    int gcd;
    int a = numAns.numerator;
    int b = numAns.denom;

    while (b != 0) {
        int temp = b;
        b = a % b;
        gcd = temp;
    }
    return (gcd);
}


void reduce_fraction(fract_t num1, fract_t num2, fract_t *numAns, int gcd) {
    ;    
	numAns->numerator = numAns->numerator / gcd;
	numAns->denom = numAns->denom / gcd;
}

void add_fractions(fract_t num1, fract_t num2, fract_t *numAns){

    if (num1.denom == num2.denom){
        numAns->numerator = num1.numerator + num2.numerator;
        numAns->denom = num1.denom;
    } else {
        numAns->denom = num1.denom * num2.denom;
        numAns->numerator = (num1.numerator * num2.denom) + (num1.denom * num2.numerator);
    }
}

void sub_fractions(fract_t num1 , fract_t num2, fract_t *numAns){

    if (num1.denom == num2.denom){
        numAns->numerator = num1.numerator - num2.numerator;
        numAns->denom = num1.denom;
    } else {
        numAns->denom = num1.denom * num2.denom;
        numAns->numerator = (num1.numerator * num2.denom) - (num1.denom * num2.numerator);
    }
}

void multiply_fractions(fract_t num1, fract_t num2, fract_t *numAns, char op){

    if (op == '*'){
        numAns->numerator = num1.numerator * num2.numerator;
        numAns->denom = num1.denom * num2.denom;
    } else if (op == '/'){
        numAns->numerator = num1.numerator * num2.denom;
        numAns->denom = num1.denom * num2.numerator;
    }
    if (numAns->numerator < 0) {
    
        numAns->numerator *= -numAns->numerator;
        numAns->denom *= -1;
    }

}



void print_fractions(fract_t num1, fract_t num2, fract_t numAns, char op){

        printf("\n");
        printf("%d/%d %c %d/%d = %d/%d\n", num1.numerator, num1.denom, op, num2.numerator, num2.denom, numAns.numerator, numAns.denom);

}


int main (void){

    char again, dummy, op;
    int gcd;

    do {
		/* Gets a fraction problem */
		fract_t num1;
        fract_t num2;
        fract_t numAns;
        

        printf("Your first number \n");
        scan_fraction(&num1);
        printf("Your second number \n");
        scan_fraction(&num2);

        printf("Please choose what type of operator you want (+ - * /): ");
        scanf("%c", &op);

		/* Computes the result */
		switch (op) {
		case '+':
			add_fractions(num1, num2, &numAns);
			break;

		case '-':
			sub_fractions(num1, num2, &numAns);
			break;

		case '*':
			multiply_fractions(num1, num2, &numAns, op);
			break;

		case '/':
			multiply_fractions(num1, num2, &numAns, op);

        default: 
            printf("Please enter a valid operator");
		}
        gcd = find_gcd(numAns);
		reduce_fraction(num1, num2, &numAns, gcd);

		/* Displays problem and result                                     */
        print_fractions(num1, num2, numAns, op);

		/* Asks user about doing another problem                           */
		printf("\nDo another problem? (y/n)> ");
		scanf(" %c", &again);
	} while (again == 'y' || again == 'Y');
	
}