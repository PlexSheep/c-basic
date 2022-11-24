#include <stdio.h>
int main() {
    int a, digits = 0, b = 0;
    printf("input a number for calculation\n");
    fflush(stdin);
    scanf("%d",&a);

    int digit[128];

    // look out for wrong order
    for(int i=0; i<128; i++) {
	digit[i] = a % 10;
	if(a>0)
	    a = a / 10;
	else {
	    if(digits==-1)
		digits = i;
	    digit[i] = -1;
	}
	//printf("%d. digit is: %d\n", i, digit[i]);
    }

    // array is in wrong order, but who cares for the quersumme
    for(int i=0; i<128; i++){
	if(digit[i]>0)
	    b += digit[i];
    }
    printf("quersumme is: %d\n", b);
    return 0;
}
