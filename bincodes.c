#include <stdio.h>
#include <ctype.h>
#include <barcode.h>

#include "debug.h"
#include "parse.h"

#define BAR_CHAR '1'
#define SPACE_BAR '0'
#define BAR_WIDTH 3

int main(int argc, char* argv[]) {

	Config config = (Config) {
		BAR_CHAR,
		SPACE_BAR,
		BAR_WIDTH,
		0
	};

	int last = parseArguments(argc, argv, &config);

	setDebugLevel(config.debug_level); 

	if (last >= argc) {
		return 2;
	}
	debug(LOG_DEBUG,"to barcode: %s\n",argv[last]);

	struct Barcode_Item *bc = Barcode_Create(argv[last]);

	if (!bc) {
		return 1;
	}
		int status = Barcode_Encode(bc, BARCODE_39 | BARCODE_NO_CHECKSUM);

	int i = 0;
	int j = 0;
	char* output = bc->partial;

	debug(LOG_DEBUG,"textinfo: %s\nascii: %s\npartial: %s\n", bc->textinfo, bc->ascii, bc->partial);

	unsigned int flag = 0;
	char c = config.bar;
	int num = 0;
	int k = 0;
	while (output[i] != 0) {

		if (flag) {
			c = config.bar;	
		} else {
			c = config.space;
		}


		if (isdigit(output[i])) {
			num = output[i] - '0';
		} else {
			num = output[i] - 96;
		}

		for (k = 0; k < num * config.width; k++) {
			printf("%c", c);
		}

		i++;
		flag = !flag;
	}
	printf("\n");

	Barcode_Delete(bc);

	return 0;
}
