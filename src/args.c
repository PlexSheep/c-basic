#include <stdio.h>

int main(int argc, char* argv[]){

    if(argc==1){
	printf("Recieved only one argument, idiot");
	return 1;
    }

    for(int i = 0; i < argc+1; i++){
	printf("%d.	[%s]\n", i+1, argv[i]);
    }

    return 0;
}
