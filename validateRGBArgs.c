#include <stdlib.h>

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
