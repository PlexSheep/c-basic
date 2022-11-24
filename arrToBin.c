#include <stdio.h>
#include <stdlib.h>

int main(){
    // input as single int, output as array of ints with only 0 and 1s 

    char str_i[20];
    int i;
    
    fgets(str_i, 20, stdin);
    i = strtol(str_i, NULL, 0);
    printf("%d", i);

    int bin[16] = { -1 };
    int b;

    printf("[CONTROL]as hex %x\n", i);
    for(int j = 16; j>0; j--){
        b = i%2;
        i /= 2;
        bin[i] = b;
    }
    for(int j = 0; j < 16; j++){
        if(
            printf("%d", bin[j]);
    }
    printf("\n");
    return 0;
}
