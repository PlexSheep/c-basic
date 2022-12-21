#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>

int main(int argc, char **argv){

    if(argc<3){
	printf("not enough args! Ex: ./abc 12 -3 5\n");
	exit(EXIT_FAILURE);
    }
    double a = atoi(argv[1]);
    double b = atoi(argv[2]);
    double c = atoi(argv[3]);

    printf("(%f)x²+(%f)x+(%f)=0\n", a, b, c);
    double l1 = 0, l2 = 0;
    double cl1 = 0, cl2 = 0;
    l1=(-b + sqrt((b*b)-(4*a*c)))/(2*a);
    l2=(-b - sqrt((b*b)-(4*a*c)))/(2*a);
    cl1=(-b + csqrt((b*b)-(4*a*c)))/(2*a);
    cl2=(-b - csqrt((b*b)-(4*a*c)))/(2*a);
    printf("(-%.0f (+-) sqrt[(%.0f²)-(4*%.0f*%.0f)])/2*%.0f\n", b, b, a, c, a);
    printf("x1=%f	x2=%f\n", l1, l2);
    printf("(complex mode)\nx1=%fi\tx2=%fi\n", cl1, cl2);
    return 0;
}
