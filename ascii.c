#include <stdio.h>

int main(){
    for(int i=0; i<256; i++){
	printf("(dec)%d\t(hex)0x%02x\t(char)%c\t\n",i,i,i);
    }
    return 0;
}
