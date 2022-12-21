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

int main(int argc, char *argv[]){
    if(argc<=1) {
        printf("You did not feed me arguments, I will die now :( gimme ints");
	return 1;
    }  //otherwise continue on our merry way....

    double num = atoi(argv[1]);
    printf("the factorial of the given input calculated by a recursive algorithm is: %.0f\n", factorial(num));
    printf("the factorial of the given input calculated by a nonrecursive algorithm is: %.0f\n", factorialFor(num));
    return 0;
}

