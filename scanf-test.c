#include <stdio.h>

int main() {
    int a;
    float f;
    char s[20];
    printf("input an integer, a float, then a string.\n");
    scanf("%d %f %s", &a, &f, s);
    printf("%d %f %s\n", a, f, s);
    return 0;
}
