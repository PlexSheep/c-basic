#include <stdio.h>

typedef struct
{
    float real;
    float imaginary;
}complex;

complex assignComplex(){
    float r, i;
    scanf("%f", &r);
    scanf("%f", &i);
    complex c;
    c.real = r;
    c.imaginary = i;
    return c;
}

void addComplex() {
    printf("First complex\n");
    complex a = assignComplex(); 
    printf("Second complex\n");
    complex b = assignComplex(); 

    complex r;
    r.real = a.real + b.real;
    r.imaginary = a.imaginary + b.imaginary;
    printf("Result: %f+%fi\n", r.real, r.imaginary);
}

void subComplex() {
    printf("First complex\n");
    complex a = assignComplex(); 
    printf("Second complex\n");
    complex b = assignComplex(); 

    complex r;
    r.real = a.real - b.real;
    r.imaginary = a.imaginary - b.imaginary;
    printf("Result: %f+%fi\n", r.real, r.imaginary);
}

void mulComplex() {
    printf("First complex\n");
    complex a = assignComplex(); 
    printf("Second complex\n");
    complex b = assignComplex(); 

    complex r;
    r.real = a.real * b.real;
    r.imaginary = a.imaginary * b.imaginary;
    printf("Result: %f+%fi\n", r.real, r.imaginary);
}

void divComplex() {
    printf("First complex\n");
    complex a = assignComplex(); 
    printf("Second complex\n");
    complex b = assignComplex(); 

    complex r;
    r.real = a.real / b.real;
    r.imaginary = a.imaginary / b.imaginary;
    printf("Result: %f+%fi\n", r.real, r.imaginary);
}

int main() {
    printf("Usage:\n\toperations: + - * /\n\tquit: q\n");

    char in;
    while(1){

        in = getchar();
        switch(in){
            case 'q': return 0;
            case '+': addComplex(); break;
            case '-': subComplex(); break;
            case '*': mulComplex(); break;
            case '/': divComplex(); break;
            default: printf("kaputt\n"); break;
        }
    }
}
