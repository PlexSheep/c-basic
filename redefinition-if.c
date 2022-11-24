#include <stdio.h>
int main() {
    int a;
    if(1){
	int a;	// works, this a is only in scope of the if statement.
    }
    return 0;
}
