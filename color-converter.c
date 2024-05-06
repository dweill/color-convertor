#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const int HEX_BASIS = 16;
int charToInt(char c);
char intToChar(int i);
void getHelpOutput();
int convertHexToRGB(char *hex);
int validateArgs(int argc, int minArgs);
int convertRGBToHex(int r, int g, int b);
int validateHexArgs(char *args);
int validateRGBArgs(char *r, char *g, char *b);

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

int validateArgs(int argc, int minArgs) {
	
	if (argc < minArgs) {
	printf("%d\n",argc);	
		printf("Incorrect number of arguments\n"); 
		printf("Please provide a flag for hexadecimal or rgb input, followed by a hexadecimal or RGB value \n");
		return 1;
	}
	return 0;
}

int validateHexArgs(char *args) {
	for (int i = 0; i < strlen(args); i++) {
		int result = charToInt(args[i]);
		if (result >= HEX_BASIS) return 1;
	}
	return 0;
}

int validateRGBArgs(char *r, char *g, char *b) {
	char *args[] = {r, g, b};
	for (int i = 0; i < 3; i++) {
		if (atoi(args[i]) >= 256) {
			return 1;
		}
		if (atoi(args[i]) < 0) {
			return 1;
		}
	}	
	return 0;
}

void getHelpOutput() {
	printf("COLOR CONVERTER\n");
	printf("This program is for converting colors between hexadecimal and RGB\n");
	printf("To convert from hexadecimal to RGB, execute the program with the flag --hexadecimal or -ix\n");
	printf("followed by ###### (6 digits between 0 - F)\n");
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


char intToChar(int i) {
	switch(i) {
		case 15:
			return 'F';
		case 14:
			return 'E';
		case 13:
			return 'D';
		case 12:
			return 'C';
		case 11:
			return 'B';
		case 10:
			return 'A';
		default:
			return i + '0';
	}
}

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

