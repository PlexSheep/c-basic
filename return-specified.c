#include <stdio.h>
#include <stdlib.h>

/*
 * This program takes the given argument and returns it as an integer.
 * It might be useful to test a shell.
 */

int main(int argc, char** argv){
    if(argc<2){
        printf("No argument given.\n");
        return -1;
    }
    return atoi(argv[1]);
}
