#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parse.h"
#include "debug.h"

void usage() {

	printf("convert text to binary barcodes.\n");
	printf("\t --help\tshow this usage.\n");
	printf("\t -b, --bar <char>\tchar for bars.\n");
	printf("\t -s, --space <char>\t char for spaces.\n");
	printf("\t -w, --width <int>\t width for one element.\n");
	printf("\t -d, --debug <int>\t debug level (0 only errors to 3 all infos).\n");
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
}
