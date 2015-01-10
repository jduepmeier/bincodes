#pragma once

typedef struct {
	char bar;
	char space;
	unsigned int width;
	unsigned int debug_level;
} Config;

int parseArguments(int argc, char* argv[], Config* config);
