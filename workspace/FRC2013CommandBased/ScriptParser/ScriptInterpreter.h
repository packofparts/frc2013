#ifndef SCRIPT_INTERPRETER_H
#define SCRIPT_INTERPRETER_H

#include "ScriptScanner.h"

class ScriptInterpreter
{
public:
	typedef void (*ScriptInterpreterCallbackFunc)(const char* func, float param, void* ref);
	
	ScriptInterpreter(void);
	~ScriptInterpreter(void);

	int OpenScript(const char* fileName);
	void Start(void* ref);
	int Tick();

	void SetCallback(ScriptInterpreterCallbackFunc func);
private:
	char* script;
	void* refNum;
	float startTime;
	ScriptScanner* scan;
	ScriptInterpreterCallbackFunc _callback;
};

#endif
