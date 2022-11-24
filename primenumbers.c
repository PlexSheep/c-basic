#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int maxPrime = atoi(argv[1]);

    int *arr1 = malloc(sizeof(int)*maxPrime);
    if(arr1==NULL)
        return -1;
    for(int i=0; i<maxPrime; i++) {
        arr1[i]=i+2;
    }

    int p = 2;

    for(int i=1; i<maxPrime; i++) {
        for(int j=1; j<maxPrime; j++) {
            if((arr1[j]%p==0)&&(arr1[j]>0)&&(arr1[j]!=p))
                arr1[j]=-1;
        }
        // get next prime in arr
        // FIXME
        p = arr1[i];
        for(int l=0;l<512;l++){
            if(p>0)
                break;
            else {
                p = arr1[i+l]; 
            }
        }
        for(int l=0;l<maxPrime;l++){
        }
    }
    printf("\n");
    printf("\n");
    for(int i=0;i<maxPrime;i++){
        if(arr1[i]>0)
            printf("%d ", arr1[i]);
    }
    free(arr1);
    printf("\n");
    return 0;
}
