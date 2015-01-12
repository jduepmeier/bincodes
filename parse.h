#pragma once

typedef struct {
	char* encoding;
	char bar;
	char space;
	unsigned int width;
	unsigned int debug_level;
	unsigned int checksum;
} Config;

int parseArguments(int argc, char* argv[], Config* config);
