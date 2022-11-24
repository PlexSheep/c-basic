#include <stdio.h>

int main(){
    char s[2];
    // produce warning, char* s is too small for the following fgets instruction
    fgets(s, 10, stdin);
    printf("%s\n",s);
    return 0;
}
