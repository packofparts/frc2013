#ifndef LOGGING_H
#define LOGGING_H

typedef enum LogType
{
	kInformation, kError, kCritical
};

void log(LogType level, char* format, ...);

#endif
