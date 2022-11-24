/*
 * lower and upper end as user input
 * use a for loop to output all numbers for which 7|x is true.
 */

#include <stdio.h>

int main() {
    
    int a,b;
    printf("input lower end:\n");
    fflush(stdin);
    scanf("%d",&a);
    printf("input upper end:\n");
    fflush(stdin);
    scanf("%d",&b);

    printf("inputs: %d %d\n", a, b);
    for(int i=a; i<=b; i++){
	if(i%7==0)
	    printf("%d ", i);
	if(i==b)
	    printf("\n");
    }

    // reverse array order
    
    return 0;
}
