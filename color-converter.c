#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int charToInt(char c); 

int main(int argc, char *argv[]) {
	char *hexArg = "--hex=#";
	if (argc > 1 && strncmp(argv[1], hexArg, strlen(hexArg)) == 0) {
		printf("checking hex...\n");
		char hex[7];
		memcpy(hex, &argv[1][strlen(hexArg)], 6);
		hex[6] = '\0';
		printf("%s\n", hex);
		if (strlen(hex) != 6) {
			printf("Please provide a 6 digit hex color\n");
			return 1;
		}
		char r[3];
		char g[3];
		char b[3];
		memcpy(r, &hex[0], 2);
		memcpy(g, &hex[2], 2);
		memcpy(b, &hex[4], 2);
		r[2] = '\0';
		g[2] = '\0';
		b[2] = '\0';
		int bigR = charToInt(r[0]) * 16;
		int smallR = charToInt(r[1]);
		
		int bigG = charToInt(g[0]) * 16;
		int smallG = charToInt(g[1]);

		int bigB = charToInt(b[0]) * 16;
		int smallB = charToInt(b[1]);
		printf("R: %d, G: %d, B: %d\n", bigR + smallR, bigG + smallG, bigB + smallB);
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
