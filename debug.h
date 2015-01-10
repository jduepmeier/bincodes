#pragma once

#define LOG_ERROR 0
#define LOG_WARNING 1
#define LOG_DEBUG 2
#define LOG_INFO 3

void setDebugLevel(int status);
void debug(int level, char* format, ...);
