#include "../headers/main.h"

int main(int argc, char *argv[]) {
	
	switch(argc)
	{
	case 3:
		printf("%d\n", dataValidationWrapper(argv[1], argv[2]) );
		break;
	default:
		printUsage(argv[0]);
		break;
	}
	
	exit(0);
}
