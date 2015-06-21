#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parse.h"
#include "debug.h"

void usage() {

	printf("convert text to binary barcodes.\n");
	printf("\t -h, --help\t\tshow this usage.\n");
	printf("\t -c, --checksum\t\tadd checksum to barcodes.\n");
	printf("\t -e, --encoding <char*>\tset the encoding. Standard is code39. See ENCODINGS for valid inputs.\n");
	printf("\t -b, --bar <char>\tcharacter that represents the bars.\n");
	printf("\t -s, --space <char>\tcharacter that represents the spaces.\n");
	printf("\t -w, --width <int>\twidth that represents an element.\n");
	printf("\t -d, --debug <int>\tsets the debug level (ERROR = 0; WARNING = 1; DEBUG = 2; INFO = 3).\n");
	printf("\n");
	printf("encodings:\n");
	printf("\t39\t-\tcode39\n");
	printf("\tean\t-\tean\n");
	printf("\tupc\t-\tupc == 12-digit ean\n");
	printf("\tisbn\t-\tisbn numbers (still EAN13)\n");
	printf("\t128\t-\tcode128 (a,b,c: autoselection)\n");
	printf("\t128c\t-\tcode128 (compact form for digits)\n");
	printf("\t128b\t-\tcode128, full printable ascii\n");
	printf("\ti25\t-\tinterleaved 2 of 5 (only digits)\n");
	printf("\t128raw\t-\traw code 128 (by Leonid A. Broukhis)\n");
	printf("\tcbr\t-\tCodebar (by Leonid A. Broukhis)\n");
	printf("\tmsi\t-\tMSI (by Leonid A. Broukhis)\n");
	printf("\tpls\t-\tPlessey (by Leonid A. Broukhis)\n");
	printf("\t93\t-\tcode93 (by Nathan D. Holmes)\n");
	exit(3);
}

int getInt(char* integer) {
	int i = -1;

	sscanf(integer, "%d", &i);
	return i;
}

int parseArguments(int argc, char* argv[], Config* config) {

	//parse arguments
	int i;
	for (i = 1; i < argc; i++) {
		if (*argv[i] == '-') {
			if (i + 1 < argc && (!strcmp(argv[i], "--debug") || !strcmp(argv[i], "-d"))) {
                		config->debug_level = getInt(argv[i +1]);
				i++;
	    		} else if ((!strcmp(argv[i], "--checksum") || !strcmp(argv[i], "-c"))) { 
                		config->checksum = 1;
            		} else if (i + 1 < argc && (!strcmp(argv[i], "--encoding") || !strcmp(argv[i], "-e"))) { 
                		config->encoding = argv[i + 1];
				i++;
            		} else if (i + 1 < argc && (!strcmp(argv[i], "--width") || !strcmp(argv[i], "-w"))) { 
                		config->width = getInt(argv[i + 1]);
				i++;
            		} else if (i + 1 < argc && (!strcmp(argv[i], "--bar") || !strcmp(argv[i], "-b"))) { 
                		config->bar = argv[i + 1][0];
				i++;
            		} else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
                		usage();
            		} else if (i + 1 < argc && (!strcmp(argv[i], "--space") || !strcmp(argv[i], "-s"))) {
				config->space = argv[i + 1][0];
				i++;
	    		} else {
                		printf("Invalid arguments.\n");
                		usage();
            		}
        	} else {
			return i;
		}
    
    	}

	return 1;
}
