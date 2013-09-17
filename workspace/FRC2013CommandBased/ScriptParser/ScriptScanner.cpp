#include "ScriptScanner.h"

#include <stdlib.h>
#include <string.h>

#define DIGITS "-0.123456789"
#define WHITESPACE_CHARS " \n\r\t"


bool strcont(char c, char* str)
{
	for(int i = 0; str[i] != 0; i++)
	{
		if(str[i] == c)
			return 1;
	}

	return 0;
}

ScriptScanner::ScriptScanner(char* str)
{
	this->str = str;
}

ScriptScanner::~ScriptScanner(void)
{
}

bool ScriptScanner::ReadOneLine()
{
	// A line that we parse looks like this:
	//		5.5: setThing(3);   This is a comment.\n


	if(!this->_hasExeced)	// Check if this function has already executed
		return 0;

	this->_hasExeced = false;



	double time = nextd();	// Get the time

	this->eatWhitespace();

	if(!this->hasNextc(':'))	// Check for the colon
		return 1;

	this->eatWhitespace();

	char* func = this->nexta();		// Get the function

	if(!this->hasNextc('('))		// Check for open paren
		return 1;

	if(this->hasNextd())			// Check if there is an arg
	{
		this->_nextFuncArg = this->nextd();		// Get the arg
	}
	else
	{
		this->_nextFuncArg = 0;					// Otherwise set arg to zero
	}

	if(!this->hasNextc(')'))		// Check for close parenthesis
		return 1;

	if(!this->hasNextc(';'))		// Check for semicolon
		return 1;

	this->toEOL();					// Skip over comments, to next line.
	this->eatWhitespace();

	this->_nextFunc = func;
	this->_nextFuncTime = time;

	return 0;
}

void ScriptScanner::hasExec()
{
	this->_hasExeced = true;
}

float ScriptScanner::NextFuncTime()
{
	return this->_nextFuncTime;
}
char* ScriptScanner::NextFunc()
{
	return this->_nextFunc;
}
float ScriptScanner::NextFuncArg()
{
	return this->_nextFuncArg;
}

bool ScriptScanner::isAlpha(char c)
{
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}
bool ScriptScanner::hasNexta()
{
	return this->isAlpha(this->str[0]);
}
bool ScriptScanner::hasNextc(char c)
{
	if(this->str[0] == c)
	{
		this->str++;

		return true;
	}

	return false;
}
bool ScriptScanner::hasNextd()
{
	return strcont(this->str[0], DIGITS);
}
char* ScriptScanner::nexta()
{
	char* buf = new char[strlen(this->str)];

	int i = 0;

	while(this->isAlpha(this->str[0]))
	{
		buf[i++] = this->str[0];

		this->str++;
	}

	buf[i] = '\0';

	this->eatWhitespace();

	return buf;
}
double ScriptScanner::nextd()
{
	char* buf = new char[strlen(this->str)];
	int i = 0;

	while(strcont(this->str[0], DIGITS))
	{
		buf[i++] = this->str[0];
		
		this->str++;
	}

	buf[i] = '\0';

	double val = atof(buf);
	
	this->eatWhitespace();

	return val;
}

void ScriptScanner::eatWhitespace()
{
	while(strcont(this->str[0], WHITESPACE_CHARS)) this->str++;
}
void ScriptScanner::toEOL()
{
	while(this->str[0] != '\n') this->str++;
	this->str++;
}
