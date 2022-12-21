#include <stdio.h>

int main(){
    char s[2];
    /*
     * The following line of code is unsafe. It writes up to 10 bytes into the char array 's', which is only
     * 2 Bytes big. A Buffer Overflow can happen. I have chosen to keep that line, because i wanted a source
     * file that produces a compiler warning when it is compiled. That is the true purpose of this file.
     *
     * a safe alternative would be: fgets(s, 2, stdin);
     */
    fgets(s, 10, stdin);    // UNSAFE 
    printf("%s\n",s);
    return 0;
}
