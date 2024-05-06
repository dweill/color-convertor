#include "intToChar.h"


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
