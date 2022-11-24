#include <stdio.h>

void printLoc(int y) {
    printf("Address of y is %x\n", &y);
}

void printPointerLoc(int *x) {
    printf("Adress of x is %x\n", &x);
    printf("Adress the x pointer points to is %x\n", x);
    printf("Adress of whatever *x is is %x\n", *x);
}

int main() {
    int a = 0xAAAA;
    printf("Address of a is %x\n", &a);
    printLoc(a);
    printPointerLoc(&a);
    return 0;
}
