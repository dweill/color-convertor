#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "charToInt.h"
#include "intToChar.h"
#include "getHelpOutput.h"
#include "validateArgs.h"
#include "hex-basis.h"
#include "convertHexToRGB.h"
#include "convertRGBToHex.h"
#include "validateHexArgs.h" 
#include "validateRGBArgs.h"


int main(int argc, char *argv[]) {
	char *firstArg;
	if (argc == 1) {
		getHelpOutput();
		return 0;
	}
	firstArg = argv[1];
	if ( strcmp(firstArg, "--help") == 0 || strcmp(firstArg, "-h") == 0) {
		getHelpOutput();
		return 0;
	}

	if (strcmp(firstArg, "--hexadecimal")  == 0|| strcmp(firstArg, "-ix") == 0) {
		if (validateArgs(argc, 3) == 0 && validateHexArgs(argv[2]) == 0) {
			char *hexArg = argv[2];
			convertHexToRGB(hexArg);
		}
	}

	if (strcmp(firstArg, "--rgb") == 0 || strcmp(firstArg, "-ir") == 0) {
		if (validateArgs(argc, 5) == 0 && validateRGBArgs(argv[2], argv[3], argv[4]) == 0) {
			int r = atoi(argv[2]); 
			int g = atoi(argv[3]);
			int b = atoi(argv[4]);
			convertRGBToHex(r, g, b);
		}
	}
 
}

