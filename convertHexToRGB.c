#include "convertHexToRGB.h"
#include "hex-basis.h"
#include <stdio.h>
#include "charToInt.h"
#include <string.h>
int convertHexToRGB(char* hex) {

	if (strlen(hex) == 6) {
		printf("checking hex...\n");
		printf("%s\n", hex);
		char r[3];
		char g[3];
		char b[3];
		memcpy(r, &hex[0], 2);
		memcpy(g, &hex[2], 2);
		memcpy(b, &hex[4], 2);
		r[2] = '\0';
		g[2] = '\0';
		b[2] = '\0';
		int bigR = charToInt(r[0]) * HEX_BASIS;
		int smallR = charToInt(r[1]);
		
		int bigG = charToInt(g[0]) * HEX_BASIS;
		int smallG = charToInt(g[1]);

		int bigB = charToInt(b[0]) * HEX_BASIS;
		int smallB = charToInt(b[1]);
		printf("R: %d, G: %d, B: %d\n", bigR + smallR, bigG + smallG, bigB + smallB);
		return 0;
	} else {
		printf("Please provide a six character Hexadecimal value  with no spaces. Ex: FF00D1\n");
		return 1;
	}
}

