#include "hex-basis.h"
#include <string.h>
#include "charToInt.h"
int validateHexArgs(char *args) {
	for (int i = 0; i < strlen(args); i++) {
		int result = charToInt(args[i]);
		if (result >= HEX_BASIS) return 1;
	}
	return 0;
}
