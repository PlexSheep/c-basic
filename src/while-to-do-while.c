#include <stdio.h>

int main() {
    int init = 5;
    int i = init;
    while (i < 10 || i == init) {
        printf("helo %d\n", i);
        i++;
    } 
    i = init;
    do {
        printf("ahelo %d\n", i);
        i++;
    } while (i < 10);
}
