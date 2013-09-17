#ifndef SCRIPT_SCANNER_H
#define SCRIPT_SCANNER_H

class ScriptScanner
{
public:
	ScriptScanner(char* str);
	~ScriptScanner(void);

	float NextFuncTime();
	char* NextFunc();
	float NextFuncArg();
	void hasExec();

	bool ReadOneLine();

private:	
	char* str;
	float _nextFuncTime;
	char* _nextFunc;
	float _nextFuncArg;

	bool _hasExeced;
	
	void eatWhitespace();
	void toEOL();

	char* nexta();
	double nextd();
	bool isAlpha(char c);
	bool hasNexta();
	bool hasNextc(char c);
	bool hasNextd();
};

#endif
