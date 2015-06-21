#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "debug.h"

int debug_level = -1;

void debug(int level, char* format, ...) {

        va_list va;
        va_start(va, format);

	if (debug_level < level) {
		return;
	}


	char* before;


	switch(level) {

		case LOG_ERROR:
			before = "ERROR: ";
			break;
		case LOG_WARNING:
			before = "WARNING: ";
			break;
		case LOG_DEBUG:
			before = "DEBUG: ";
			break;
		case LOG_INFO:
			before = "INFO: ";
			break;
		default:
			va_end(va);
			return;
	}


	int size = strlen(before) + strlen(format) + 1;
	char output[size];

	sprintf(output, "%s%s", before, format);

	vprintf(output,va);

	va_end(va);
}

void setDebugLevel(int level) {
	debug_level = level;
}
