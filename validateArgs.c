#include <stdio.h>
#include "validateArgs.h"

int validateArgs(int argc, int minArgs) {
	
	if (argc < minArgs) {
	printf("%d\n",argc);	
		printf("Incorrect number of arguments\n"); 
		printf("Please provide a flag for hexadecimal or rgb input, followed by a hexadecimal or RGB value \n");
		return 1;
	}
	return 0;
}
