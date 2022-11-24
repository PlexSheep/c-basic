#include <stdio.h>

int main(){

    int result = 0;
    for (int i = 1; i < 101; i++){
	result+=i;
    }
    printf("sum of 1 up to 100 is: %d\n", result);
    return 0;
}
