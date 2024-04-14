#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NOT_IMP printf("ERROR: that feature hasn't been implemented yet\n"); \
				exit(-1);

void printUsage(char *arg0) {
	printf("Usage: %s <num1> <num2>\n", arg0);
}

int stringToInt(char *sting) {
	size_t length = strlen(sting);
	int result = 0;

	for(size_t it = 0; it < length; it++) {
		if ( (sting[it] >= '0') && (sting[it] <= '9') ) {
			result = 10 * result + sting[it];
		}
		else {
			return -1;
		}
	}
	
	return result;
}

int min(int x, int y) {
	if(x <= y)
		return x;
	else
		return y;
}

int max(int x, int y) {
	if(x >= y)
		return x;
	else
		return y;
}

int gcd(int x, int y) {
	unsigned int modVal = max(x, y) % min(x, y);
	
	while(modVal != 0) {
		y      = x;
		x      = modVal;
		modVal = y % x;
	}
	
	return x;
}

int dataValidationWrapper(char *arg1, char *arg2) {
	int x = stringToInt(arg1);
	int y = stringToInt(arg2);
	if ((x == -1) || (y == -1)) {
		printf("ERROR: both numbers must be valid positive integers.\n");
		return -1;
	}
	
	printf("%d\n", gcd(x, y));
	return 0;
}
