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
			result = 10 * result + (sting[it] - '0');
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

void sort(int *x, int *y) {
	int minVal = min(*x, *y);
	int maxVal = max(*x, *y);
	
	*x = minVal;
	*y = maxVal;
}

int gcd(int x, int y) {
	sort(&x, &y);	
	
	unsigned int modVal = y % x;
	
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

int readFromUserInput () {
	char arg1[9], arg2[9];
	printf ("Enter your first number: ");
	scanf ("%9s", arg1);
	
	printf ("Enter your second number: ");
	scanf ("%9s", arg2);
	
	return dataValidationWrapper(arg1, arg2);
}
