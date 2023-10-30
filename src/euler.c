#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

// range of unsigned long long is:
// 18.446.744.073.709.551.615
// maximum factorial with this is 65!
// Double goes up to 170!
double factorial(double i) {

   if(i <= 1) {
      return 1;
   }
   return i * factorial(i - 1);
}

 double factorialFor(double given){
    double p = 1;

    // someone said i need 2 for loops. Totally wrong?
    for(int j=1;j<given;j++){

        p *= j;
        //printf("[DEBUG]p is %f, j is %d\n", p, j);
    }
    return given * p;
}

double euler(int k) {
    return 1/factorial(k);
}
int main(int argc, char *argv[]){
    double res = 0, lres = 0;
    int k = 0;
    int end = 0;
    while(!end){
        res += euler(k);
        printf("%f, %f\n", res, lres);
        if(res==lres)
            end = 1;
        else {
            lres = res;
        }
        k++;
    }
    printf("calculated eulers number as %f\n", res);
    return 0;
}
