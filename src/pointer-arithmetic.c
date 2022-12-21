#include <stdio.h>

int main() {
    int a[5] = {22, 33, 44, 55, 66};
    int *ptr = NULL;
    ptr = a;  /* point to the first array element */
    for(int i = 0; i < 50; i++) {
    printf(" value:0x%-10x\tor 0d%-16d\tAdress:%-8x\n", *(ptr+i), *(ptr+i), ptr+i);  /* 33 */
}}
