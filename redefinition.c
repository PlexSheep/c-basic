#include <stdio.h>
int a = 1;
int main() {
    int a = 2;
    printf("%d\n", a); // local overrides global
    return 0;
}
