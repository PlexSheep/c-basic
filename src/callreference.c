#include <stdio.h>

int* ref(int *i, int* j, int* result){
    *result = *i + *j;
    return result;
}
    
int val(int a, int b){
    return a+b;
}

int main(){

    int x = 1000;
    int y = 337;
    int z;
    printf("given: %d\n", x);
    printf("reference: %d\n", *ref(&x, &y, &z));
    printf("value: %d\n", val(x, y));

    return 0;
}
