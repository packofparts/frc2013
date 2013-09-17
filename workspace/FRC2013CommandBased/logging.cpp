#include "logging.h"

#include "Robotmap.h"

#include <cstdio>
#include <stdarg.h>

void log(LogType level, char* format, ...)
{
	if (level >= MINIMUM_LOG_LEVEL)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		printf("\n");
		va_end(args);
	}
}
