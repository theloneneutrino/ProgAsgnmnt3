#include "../headers/main.h"

int main(int argc, char *argv[]) {
	int status;	

	switch(argc)
	{
	case 1:
		NOT_IMP
	case 3:
		status = dataValidationWrapper(argv[1], argv[2]);
		break;
	default:
		printUsage(argv[0]);
		status = -1;
		break;
	}
	
	exit(status);
}
