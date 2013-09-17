#include "ScriptInterpreter.h"

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>

#include "stdlib.h"

#include "Timer.h"
#include "ScriptScanner.h"

#include "../logging.h"

#define GETELAP Timer::GetFPGATimestamp

ScriptInterpreter::ScriptInterpreter(void)
{
}


ScriptInterpreter::~ScriptInterpreter(void)
{
	delete this->script;
	this->script = NULL;
}

void ScriptInterpreter::SetCallback(ScriptInterpreterCallbackFunc func)
{
	this->_callback = func;
}

int ScriptInterpreter::OpenScript(const char* file)
{
	std::fstream f(file);

	if(!f.is_open())
	{
		log(kError, "Could not find script file: %s", file);
		return 1;
	}
	
	std::stringstream buf;
	buf << f.rdbuf();

	std::string s = buf.str();

	const char* srcString = s.c_str();

	buf.flush();
	f.close();
	
	this->script = new char[strlen(srcString) + 1];
	strcpy(this->script, srcString);
	
	delete srcString;
	
	return 0;
}

void ScriptInterpreter::Start(void* ref)
{
	this->refNum = ref;
	scan = new ScriptScanner(script);
	this->startTime = GETELAP();		// Write down our offset time.
}

int ScriptInterpreter::Tick()
{
	float execTime = GETELAP() - this->startTime;	// Offset current time from when we started.

	scan->ReadOneLine();	// Check that we have a line ready.
	
	while(scan->NextFuncTime() <= execTime)		// Run all of the lines that execute before or on now.
	{
		char* func = scan->NextFunc();
		float funcTime = scan->NextFuncTime();
		float funcArg = scan->NextFuncArg();
		
		//log(kInformation, "Exec: at: %f\tFunc: %s\tArg: %f", funcTime, func, funcArg);
		printf("Exec: at: %f\tFunc: %s\tArg: %f\n", funcTime, func, funcArg);
		_callback(func, funcArg, this->refNum);
		
		if(!strcmp(func, "return"))
			break;
		
		scan->hasExec();		// We have now executed the line.

		scan->ReadOneLine();	// Read another one.
	}

	return 1;			// If Tick() is required again, return 1.
}
