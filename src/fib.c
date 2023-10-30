#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

const int START_VALUES[2] = {0, 1};
const int LIMIT = 90;

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("usage: %s MAX_NUMBER\n", argv[0]);
		exit(1);
	}
	int max = atoi(argv[1]);
	if (max > LIMIT) {
		printf("C does not provide a datatype large enough to compute fibonacci numbers > %d. (%d)\n", LIMIT, max);
		exit(1);
	}
	uintmax_t* nums = malloc(max * sizeof(uintmax_t));
	nums[0] = START_VALUES[0];
	nums[1] = START_VALUES[1];

	for(int i = 2; i < max+1; i++) {
		nums[i] = nums[i-2] + nums[i-1];
	}

	for(int i = 0; i < max+1; i++) {
		printf("%02d. %ju\n", i, nums[i]);
	}
}
