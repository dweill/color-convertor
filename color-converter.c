#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int HEX_BASIS = 16;
int charToInt(char c); 
void getHelpOutput();
int convertHexToRGB(char *hex);
int validateArgs(int argc, char *args[]);

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
		if (validateArgs(argc, argv) == 0) {
			char *hexArg = argv[2];
			convertHexToRGB(hexArg);
		}
	}

	if (strcmp(firstArg, "--rgb") == 0 || strcmp(firstArg, "-ir") == 0) {
		printf("rgb - hex\n");
	}
 
}

int validateArgs(int argc, char *args[]) {
	
	if (argc < 3) {
	printf("%d",argc);	
		printf("Incorrect number of arguments\n"); 
		printf("Please provide a flag for hexadecimal or rgb input, followed by a hexadecimal or RGB value \n");
		return 1;
	}
	return 0;
}

void getHelpOutput() {
	printf("COLOR CONVERTER\n");
	printf("This program is for converting colors between hexadecimal and RGB\n");
	printf("To convert from hexadecimal to RGB, execute the program with the flag --hexadecimal or -ix\n");
	printf("followed by xxxxxx (6 digits between 0 - F)\n");
	printf("To convert from RGB to hexadecimal, execute the program with the flag --rgb or -ir\n");
	printf("followed by ## ## ##\n");
	
	
}

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

int charToInt(char c) {
	switch(toupper(c)) {
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
		default:
			return c - '0';

	}

}
