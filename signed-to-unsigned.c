#include <stdio.h>

int main() {
    signed int a = -1;
    printf("%u\n",a); // no need to type cast. %u interprets given bytes of type unsigned int regardless of the datatype. truly low level
    }
