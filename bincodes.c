#include <stdio.h>
#include <ctype.h>
#include <barcode.h>
#include <string.h>

#include "debug.h"
#include "parse.h"

#define BARCODE_STD "code39"
#define BAR_CHAR '1'
#define SPACE_BAR '0'
#define BAR_WIDTH 3

unsigned int find_encoding(const char* encoding) {

	if (!strcmp(encoding, "39")) {
		return BARCODE_39;
	} else if (!strcmp(encoding, "ean")) {
		return BARCODE_EAN;
	} else if (!strcmp(encoding, "upc")) {
		return BARCODE_UPC;
	} else if (!strcmp(encoding, "isbn")) {
		return BARCODE_ISBN;
	} else if (!strcmp(encoding, "128")) {
		return BARCODE_128;
	} else if (!strcmp(encoding, "128c")) {
		return BARCODE_128C;
	} else if (!strcmp(encoding, "128b")) {
		return BARCODE_128B;
	} else if (!strcmp(encoding, "i25")) {
		return BARCODE_I25;
	} else if (!strcmp(encoding, "128raw")) {
		return BARCODE_128RAW;
	} else if (!strcmp(encoding, "cbr")) {
		return BARCODE_CBR;
	} else if (!strcmp(encoding, "msi")) {
		return BARCODE_MSI;
	} else if (!strcmp(encoding, "pls")) {
		return BARCODE_PLS;
	} else if (!strcmp(encoding, "93")) {
		return BARCODE_93;
	}
	return BARCODE_ANY;

}

int main(int argc, char* argv[]) {

	Config config = (Config) {
		BARCODE_STD,
		BAR_CHAR,
		SPACE_BAR,
		BAR_WIDTH,
		0,
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

	unsigned int encoding = find_encoding(config.encoding);

	debug(LOG_DEBUG, "encoding: %s: %d\n", config.encoding, encoding);

	if (!config.checksum) {
		debug(LOG_DEBUG, "encode without checksum\n");
		encoding |= BARCODE_NO_CHECKSUM;
	}

	int status = Barcode_Encode(bc, encoding);

	if (status < 0) {
		printf("Encoding failed: error %s\n", strerror(bc->error));
		return 4;
	}


	int i = 0;
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
