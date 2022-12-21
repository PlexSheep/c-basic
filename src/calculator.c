#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

double factorial(double i) {
    if(i <= 1) {
	return 1;
    }
    return i * factorial(i - 1);
}

double power(double a, double b) {
    double result = a;
    for(int i=0;i<b;i++){
	result*=a;
    }
    return result;
}

int main(int argc, char **argv){

    // inputs
    uint32_t a, b;
    char op;
    while(1) {
	printf("\nPlease input the first number.\n");
	fflush(stdin);
    	scanf("%d", &a);
    	printf("Please input the second number.\n");
	fflush(stdin);
    	scanf("%d", &b);
    	printf("Please select an operation. ( + - * / ^ ! ), e to exit.\n");
	fflush(stdin);
    	scanf(" %c", &op);	//The %c conversion specifier won't automatically skip any leading whitespace
    	
    	// calculate stuff.
    	switch(op) {
    	    case '+': printf("%d + %d = %d\n", a, b, a+b); break;
    	    case '-': printf("%d - %d = %d\n", a, b, a-b); break;
    	    case '*': printf("%d * %d = %d\n", a, b, a*b); break;
    	    case '/': printf("%d / %d = %f\n", a, b, (double)a/(double)b); break;
    	    case '^': printf("%d^%d = %f\n", a, b, power((double)a,(double)b)); break;
    	    case '!': printf("%d! = %f\n", a, factorial((double)a)); break;
	    case 'e': printf("exiting...\n"); return 0;
    	    //case '%': printf("%d % %d = %d\n", a, b, a%b); break; // idk weird outputs.
    	    default: printf("no operation recognized.\n"); return 1;
    	}
    }
}
