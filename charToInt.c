#include <ctype.h>
#include "charToInt.h"


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
