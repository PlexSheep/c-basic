#include <stdio.h>

int main() {
	int a, b;
	printf("Please input two integers to be added.\n");
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a+b);
	return 0;
}
