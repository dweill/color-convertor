#include "hex-basis.h"
#include <stdio.h>
#include "intToChar.h"

int convertRGBToHex(int r, int g, int b) {
	char hex[8]= "#";
	int bigR;
	int smallR;
	int bigG;
	int smallG;
	int bigB;
	int smallB;
	if (r > 15) {
		bigR = r / HEX_BASIS;
		smallR = r % HEX_BASIS;
	} else {
		bigR = 0;
		smallR = r;
	}

	if (g > 15) {
		bigG = g / HEX_BASIS;
		smallG = g % HEX_BASIS;
	} else {
		bigG = 0;
		smallG = g;
	}
	if (b > 15) {
		bigB = b / HEX_BASIS;
		smallB = b % HEX_BASIS;
	} else {
		bigB = 0;
		smallB = b;
	}
	
	hex[1] = intToChar(bigR);
	hex[2] = intToChar(smallR);
	hex[3] = intToChar(bigG);
	hex[4] = intToChar(smallG);
	hex[5] = intToChar(bigB);
	hex[6] = intToChar(smallB);
	hex[7] = '\0';
	printf("Hex value is: %s\n", hex);
	return 0;
}
