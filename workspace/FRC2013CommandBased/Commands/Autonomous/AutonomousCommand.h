#ifndef AUTONOMOUSCOMMAND_H
#define AUTONOMOUSCOMMAND_H

#include "../../ScriptParser/ScriptInterpreter.h"
#include "../../CommandBase.h"

#include "../Launcher/FireShotCommand.h"
#include "../Drive/ClosedLoop/GyroRotateCommand.h"

/**
 *
 *
 * @author matthew
 */
class AutonomousCommand: public CommandBase
{
private:
	void Callback(const char* func, float arg);
	static void CallbackSt(const char* func, float arg, void* ref)
	{
		((AutonomousCommand*)ref)->Callback(func, arg);
	};
	ScriptInterpreter* si;
	bool scriptIsCompleted;
	
	
	FireShotCommand* fireShot;
	GyroRotateCommand* gyroRotate;
public:
	AutonomousCommand(const char* autoScriptFile);
	~AutonomousCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
