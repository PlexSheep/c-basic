#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct a {
    int a;
    char str[30];
};

/*
 * give an argument to keep the file /tmp/structdump
 * like this: bin/dump aaa
 */

int main(int argc, char** argv){
    struct a* mystruct = malloc(sizeof(struct a));
    if(mystruct == NULL){
        printf("malloc for 1st struct failed!\n");
        return 1;
    }
    mystruct->a = 12;
    char s[30] = "Wer das liest ist doof";
    strcpy(mystruct->str, s);
    FILE* fptr = fopen("/tmp/structdump", "wb");
    fwrite(mystruct, sizeof(struct a), 1, fptr);
    fclose(fptr);
    free(mystruct);

    fptr = fopen("/tmp/structdump", "rb"); 
    mystruct = malloc(sizeof(struct a));
    if(mystruct == NULL){
        printf("malloc for 2nd struct failed!\n");
        return 1;
    }
    fread(mystruct, sizeof(struct a), 1, fptr); 
    printf("mystruct->a: %d\nmystruct->str: \"%s\"\n", mystruct->a, mystruct->str);   // SIGSEV
    free(mystruct);
    fclose(fptr);
    if(argc<2)
        remove("/tmp/structdump");
    return 0;
}
